using System;
using System.Collections.Generic;
using System.Linq;
using Macad.Common;
using Macad.Occt;

namespace Macad.Core.Geom;

public static class Geom2dUtils
{
    public static Pnt2d FindEllipseCenterFromEndpoints(Pnt2d startPnt, Pnt2d endPnt, double rX, double rY, double angle, bool sense)
    {
        // https://www.w3.org/TR/SVG/implnote.html#ArcImplementationNotes
        // F.6.5.1
        var matRotation = new Mat2d();
        matRotation.SetRotation(-angle);
        var v1 = new XY(startPnt.X - endPnt.X, startPnt.Y - endPnt.Y)
                 .Multiplied(0.5)
                 .Multiplied(matRotation);

        // F.6.5.2
        var denom = rX.Sqr() * v1.Y.Sqr() + rY.Sqr() * v1.X.Sqr();
        var numer = rX.Sqr() * rY.Sqr() - denom;

        var root = Math.Sqrt(Math.Abs(numer / denom)) * (sense ? -1 : 1);
        var c1 = new XY(rX * v1.Y / rY, -(rY * v1.X / rX)).Multiplied(root);

        // F.6.5.3
        matRotation.SetRotation(angle);
        var c = new XY(startPnt.X + endPnt.X, startPnt.Y + endPnt.Y)
                .Multiplied(0.5)
                .Added(c1.Multiplied(matRotation));

        return c.ToPnt();
    }

    //--------------------------------------------------------------------------------------------------

    public static (Pnt2d p1, Pnt2d p2, Pnt2d c1, Pnt2d c2)[] 
        EllipticalArcToBezier(gp_Elips2d ellipse, double startParam, double endParam, double maxInterval = Math.PI / 3)
    {
        if (endParam < startParam)
            endParam += 2 * Math.PI;

        var paramInterval = endParam - startParam;
        var itCount = (int)Math.Ceiling(Math.Abs(paramInterval) / maxInterval);
        var result = new ValueTuple<Pnt2d, Pnt2d, Pnt2d, Pnt2d>[itCount];
        var itParamStep = paramInterval / itCount;
        var itStartParam = startParam;
        for (int step = 0; step < itCount; step++)
        {
            var itEndParam = itStartParam + itParamStep;

            // http://www.spaceroots.org/documents/ellipse/node22.html
            // https://mortoray.com/2017/02/16/rendering-an-svg-elliptical-arc-as-bezier-curves/

            var p1 = Pnt2d.Origin;
            var v1 = Vec2d.Zero;
            ElCLib.D1(itStartParam, ellipse, ref p1, ref v1);

            var p2 = Pnt2d.Origin;
            var v2 = Vec2d.Zero;
            ElCLib.D1(itEndParam, ellipse, ref p2, ref v2);

            var a = 3 * Math.Pow(Math.Tan((itEndParam - itStartParam) / 2), 2);
            var b = (Math.Sqrt(4 + a) - 1) / 3;
            var alpha = Math.Sin(itEndParam - itStartParam) * b;
            var cp1 = p1 + v1.Multiplied(alpha);
            var cp2 = p2 - v2.Multiplied(alpha);

            result[step] = (p1, p2, cp1, cp2);
            itStartParam = itEndParam;
        }
        return result;
    }

    //--------------------------------------------------------------------------------------------------

    public static gp_Elips2d MakeEllipse(Pnt2d center, Pnt2d p1, Pnt2d p2, bool sense = true)
    {
        try
        {
            if ((p1.Distance(p2) <= 0) || (p2.Distance(center) <= 0) || (p1.Distance(center) <= 0))
                return null;

            // Make sure that p1 is the end of the major axis
            if (p1.Distance(center) < p2.Distance(center))
            {
                var ptemp = p2;
                p2 = p1;
                p1 = ptemp;
            }

            // The radius a is defined by distance to point p1
            double a = center.Distance(p1);

            // Normalize ellipse to x-axis running through p1, center is in (0,0)
            double rotAngle = new Ax2d(center, new Vec2d(center, p1).ToDir()).Angle(new Ax2d(center, Dir2d.DX));
            var p2Norm = p2.Translated(center, Pnt2d.Origin).Rotated(Pnt2d.Origin, rotAngle);

            // The ellipse formular is:
            // x²/a² + y²/b² = 1
            // y²/b² = 1 - x²/a²
            // b²/y² = 1 / (1 - x²/a²)
            // b² = y² / (1 - x²/a²)
            double x2 = Math.Pow(p2Norm.X, 2);
            double y2 = Math.Pow(p2Norm.Y, 2);
            double a2 = a * a;
            double b = Math.Sqrt(y2 / (1 - x2 / a2));

            //Debug.WriteLine("a={0}    b={1}", a, b);

            if (Double.IsNaN(a) || Double.IsNaN(b))
                return null;

            var ellipse = new gce_MakeElips2d(new Ax2d(center, new Dir2d(new Vec2d(center, p1))), a, b).Value();

            return ellipse;
        }
        catch (Exception)
        {
            return null;
        }
    }

    //--------------------------------------------------------------------------------------------------
        
    public static Geom2d_BSplineCurve MakeBSplineCurve(int degree, double[] knots, Pnt2d[] controlPoints, double[] weights, bool isClosed)
    {
        // Copy control points
        var poleCount = controlPoints.Length;
        var poles = new TColgp_Array1OfPnt2d(1, poleCount);
        var weightsCol = weights != null ? new TColStd_Array1OfReal(1, poleCount) : null;
        for (int i = 0; i < poleCount; i++)
        {
            poles.SetValue(i + 1, controlPoints[i]);
            weightsCol?.SetValue(i + 1, weights[i] );
        }

        // Count multiplicities and compact knot list
        var knotList = new List<double>();
        var multList = new List<int>();
        var lastKnot = double.NaN;
        foreach (var knot in knots)
        {
            if (lastKnot != knot)
            {
                knotList.Add(knot);
                lastKnot = knot;
                multList.Add(1);
            }
            else
            {
                multList[^1]++;
            }
        }

        // Copy knots and multiplicities
        var knotCount = knotList.Count;
        var knotsCol = new TColStd_Array1OfReal(1, knotCount);
        var multsCol = new TColStd_Array1OfInteger(1, knotCount);
        for (int i = 0; i < knotCount; i++)
        {
            knotsCol.SetValue(i + 1, knotList[i]);
            multsCol.SetValue(i + 1, multList[i]);
        }

        // Create spline
        var spline = weightsCol != null 
                         ? new Geom2d_BSplineCurve(poles, weightsCol, knotsCol, multsCol, degree, isClosed) 
                         : new Geom2d_BSplineCurve(poles, knotsCol, multsCol, degree, isClosed);
        return spline;
    }

    //--------------------------------------------------------------------------------------------------

    /// <summary>
    /// Finds a parameter on the curve where the tangent goes through the given point. Uses Newton-Raphson iteration.
    /// </summary>
    public static bool FindTangentThroughPoint(Geom2d_Curve curve, Pnt2d pnt, ref double u, double umin, double umax, double tolerance = 1e-6, double maxIterations = 100)
    {
        for (int iter = 0; iter < maxIterations; ++iter)
        {
            Pnt2d c = new();
            Vec2d d1 = new();
            Vec2d d2 = new();

            curve.D2(u, ref c, ref d1, ref d2);

            double vx = pnt.X - c.X;
            double vy = pnt.Y - c.Y;
            double f = vx * d1.Y - vy * d1.X;
            double fp = vx * d2.Y - vy * d2.X;

            if (f.Abs() < tolerance)
                return true;

            if (fp.Abs() < 1e-14)
                return false;

            double du = f / fp;
            u -= du;
            if (u < umin)
                u = umin;
            if (u > umax)
                u = umax;
            if (du.Abs() < tolerance)
                return true;
        }

        return false;
    }

    //--------------------------------------------------------------------------------------------------

    /// <summary>
    /// Finds all parameters on the curve where the tangent goes through the given point. Uses sampling and Newton-Raphson iteration.
    /// </summary>
    public static List<double> FindAllTangentsThroughPoint(Geom2d_Curve curve, Pnt2d pnt, double umin, double umax, double tolerance = 1e-6, double samples = 20)
    {
        List<double> roots = new();
        for (int i = 0; i <= samples; ++i)
        {
            double u = umin + (umax - umin) * i / samples;
            if (!FindTangentThroughPoint(curve, pnt, ref u, umin, umax, tolerance))
                continue;

            if(roots.Any(existing => Math.Abs(existing - u) < tolerance))
                continue;

            roots.Add(u);
        }
        roots.Sort();
        return roots;
    }

    //--------------------------------------------------------------------------------------------------

}