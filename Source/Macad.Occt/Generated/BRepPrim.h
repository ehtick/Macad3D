// Generated wrapper code for package BRepPrim

#pragma once


namespace Macad
{
namespace Occt
{
//---------------------------------------------------------------------
//  Enum  BRepPrim_Direction
//---------------------------------------------------------------------
public enum class BRepPrim_Direction
{
    XMin = 0,
    XMax = 1,
    YMin = 2,
    YMax = 3,
    ZMin = 4,
    ZMax = 5
}; // enum  class BRepPrim_Direction

//---------------------------------------------------------------------
//  Class  BRepPrim_Builder
//---------------------------------------------------------------------
/// <summary>
/// implements the abstract Builder with the BRep Builder
/// </summary>
public ref class BRepPrim_Builder sealed
    : public Macad::Occt::BaseClass<::BRepPrim_Builder>
{

#ifdef Include_BRepPrim_Builder_h
public:
    Include_BRepPrim_Builder_h
#endif

public:
    BRepPrim_Builder(::BRepPrim_Builder* nativeInstance)
        : Macad::Occt::BaseClass<::BRepPrim_Builder>( nativeInstance, true )
    {}

    BRepPrim_Builder(::BRepPrim_Builder& nativeInstance)
        : Macad::Occt::BaseClass<::BRepPrim_Builder>( &nativeInstance, false )
    {}

    property ::BRepPrim_Builder* NativeInstance
    {
        ::BRepPrim_Builder* get()
        {
            return static_cast<::BRepPrim_Builder*>(_NativeInstance);
        }
    }

public:
    /// <summary>
    /// Creates an empty, useless  Builder. Necesseray for
    /// compilation.
    /// </summary>
    BRepPrim_Builder();
    /// <summary>
    /// Creates from a Builder.
    /// </summary>
    BRepPrim_Builder(Macad::Occt::BRep_Builder^ B);
    Macad::Occt::BRep_Builder^ Builder();
    /// <summary>
    /// Make a empty Shell.
    /// </summary>
    void MakeShell(Macad::Occt::TopoDS_Shell^ S);
    /// <summary>
    /// Returns in   <F> a  Face  built  with   the  plane
    /// equation <P>. Used by all primitives.
    /// </summary>
    void MakeFace(Macad::Occt::TopoDS_Face^ F, Macad::Occt::Pln P);
    /// <summary>
    /// Returns in <W> an empty Wire.
    /// </summary>
    void MakeWire(Macad::Occt::TopoDS_Wire^ W);
    /// <summary>
    /// Returns in <E> a degenerated edge.
    /// </summary>
    void MakeDegeneratedEdge(Macad::Occt::TopoDS_Edge^ E);
    /// <summary>
    /// Returns   in <E>  an  Edge  built  with  the  line
    /// equation  <L>.
    /// </summary>
    void MakeEdge(Macad::Occt::TopoDS_Edge^ E, Macad::Occt::gp_Lin^ L);
    /// <summary>
    /// Returns  in <E>   an  Edge  built  with the circle
    /// equation  <C>.
    /// </summary>
    void MakeEdge(Macad::Occt::TopoDS_Edge^ E, Macad::Occt::gp_Circ^ C);
    /// <summary>
    /// Sets the line <L> to be the curve representing the
    /// edge <E> in the parametric space of the surface of
    /// <F>.
    /// </summary>
    void SetPCurve(Macad::Occt::TopoDS_Edge^ E, Macad::Occt::TopoDS_Face^ F, Macad::Occt::gp_Lin2d^ L);
    /// <summary>
    /// Sets the    lines  <L1,L2>  to   be     the curves
    /// representing the edge <E>  in the parametric space
    /// of the closed surface of <F>.
    /// </summary>
    void SetPCurve(Macad::Occt::TopoDS_Edge^ E, Macad::Occt::TopoDS_Face^ F, Macad::Occt::gp_Lin2d^ L1, Macad::Occt::gp_Lin2d^ L2);
    /// <summary>
    /// Sets the  circle <C> to  be the curve representing
    /// the  edge <E>  in   the  parametric  space of  the
    /// surface of <F>.
    /// </summary>
    void SetPCurve(Macad::Occt::TopoDS_Edge^ E, Macad::Occt::TopoDS_Face^ F, Macad::Occt::gp_Circ2d^ C);
    /// <summary>
    /// Returns in <V> a Vertex built with the point <P>.
    /// </summary>
    void MakeVertex(Macad::Occt::TopoDS_Vertex^ V, Macad::Occt::Pnt P);
    /// <summary>
    /// Reverses the Face <F>.
    /// </summary>
    void ReverseFace(Macad::Occt::TopoDS_Face^ F);
    /// <summary>
    /// Adds the Vertex <V> in the Edge <E>.  <P> is the
    /// parameter of the vertex on the  edge.  If direct
    /// is False the Vertex is reversed.
    /// </summary>
    void AddEdgeVertex(Macad::Occt::TopoDS_Edge^ E, Macad::Occt::TopoDS_Vertex^ V, double P, bool direct);
    /// <summary>
    /// Adds  the Vertex <V>  in the Edge <E>.   <P1,P2>
    /// are the  parameters of the  vertex on the closed
    /// edge.
    /// </summary>
    void AddEdgeVertex(Macad::Occt::TopoDS_Edge^ E, Macad::Occt::TopoDS_Vertex^ V, double P1, double P2);
    /// <summary>
    /// <P1,P2> are the parameters of the  vertex on the
    /// edge.  The edge is a closed curve.
    /// </summary>
    void SetParameters(Macad::Occt::TopoDS_Edge^ E, Macad::Occt::TopoDS_Vertex^ V, double P1, double P2);
    /// <summary>
    /// Adds the Edge <E> in the  Wire <W>, if direct is
    /// False the Edge is reversed.
    /// </summary>
    void AddWireEdge(Macad::Occt::TopoDS_Wire^ W, Macad::Occt::TopoDS_Edge^ E, bool direct);
    /// <summary>
    /// Adds the Wire <W> in  the Face <F>.
    /// </summary>
    void AddFaceWire(Macad::Occt::TopoDS_Face^ F, Macad::Occt::TopoDS_Wire^ W);
    /// <summary>
    /// Adds the Face <F>  in the Shell <Sh>.
    /// </summary>
    void AddShellFace(Macad::Occt::TopoDS_Shell^ Sh, Macad::Occt::TopoDS_Face^ F);
    /// <summary>
    /// This is called once an edge is completed. It gives
    /// the opportunity to perform any post treatment.
    /// </summary>
    void CompleteEdge(Macad::Occt::TopoDS_Edge^ E);
    /// <summary>
    /// This is called once a wire is  completed. It gives
    /// the opportunity to perform any post treatment.
    /// </summary>
    void CompleteWire(Macad::Occt::TopoDS_Wire^ W);
    /// <summary>
    /// This is called once a face is  completed. It gives
    /// the opportunity to perform any post treatment.
    /// </summary>
    void CompleteFace(Macad::Occt::TopoDS_Face^ F);
    /// <summary>
    /// This is called once a shell is  completed. It gives
    /// the opportunity to perform any post treatment.
    /// </summary>
    void CompleteShell(Macad::Occt::TopoDS_Shell^ S);
}; // class BRepPrim_Builder

//---------------------------------------------------------------------
//  Class  BRepPrim_OneAxis
//---------------------------------------------------------------------
/// <summary>
/// Algorithm to  build  primitives with  one  axis of
/// revolution.
/// 
/// The revolution  body is described by :
/// 
/// A coordinate  system (Ax2 from  gp). The Z axis is
/// the rotational axis.
/// 
/// An Angle around the Axis, When  the Angle  is 2*PI
/// the primitive is not limited  by planar faces. The
/// U parameter range from 0 to Angle.
/// 
/// A parameter range VMin, VMax on the meridian.
/// 
/// A meridian : The  meridian is a curve described by
/// a set of deferred methods.
/// 
/// The  topology consists of  A shell,  Faces,  Wires,
/// Edges and Vertices.  Methods  are provided to build
/// all the elements.  Building an element  implies the
/// automatic building  of  all its  sub-elements.
/// 
/// So building the shell builds everything.
/// 
/// There are at most 5 faces :
/// 
/// - The LateralFace.
/// 
/// - The TopFace and the BottomFace.
/// 
/// - The StartFace and the EndFace.
/// </summary>
public ref class BRepPrim_OneAxis
    : public Macad::Occt::BaseClass<::BRepPrim_OneAxis>
{

#ifdef Include_BRepPrim_OneAxis_h
public:
    Include_BRepPrim_OneAxis_h
#endif

protected:
    BRepPrim_OneAxis(InitMode init)
        : Macad::Occt::BaseClass<::BRepPrim_OneAxis>( init )
    {}

public:
    BRepPrim_OneAxis(::BRepPrim_OneAxis* nativeInstance)
        : Macad::Occt::BaseClass<::BRepPrim_OneAxis>( nativeInstance, true )
    {}

    BRepPrim_OneAxis(::BRepPrim_OneAxis& nativeInstance)
        : Macad::Occt::BaseClass<::BRepPrim_OneAxis>( &nativeInstance, false )
    {}

    property ::BRepPrim_OneAxis* NativeInstance
    {
        ::BRepPrim_OneAxis* get()
        {
            return static_cast<::BRepPrim_OneAxis*>(_NativeInstance);
        }
    }

public:
    /// <summary>
    /// The MeridianOffset is added  to the  parameters on
    /// the meridian curve and  to  the  V values  of  the
    /// pcurves. This is  used for the sphere for example,
    /// to give a range on the meridian  edge which is not
    /// VMin, VMax.
    /// </summary>
    void SetMeridianOffset(double MeridianOffset);
    /// <summary>
    /// The MeridianOffset is added  to the  parameters on
    /// the meridian curve and  to  the  V values  of  the
    /// pcurves. This is  used for the sphere for example,
    /// to give a range on the meridian  edge which is not
    /// VMin, VMax.
    /// </summary>
    void SetMeridianOffset();
    /// <summary>
    /// Returns the Ax2 from <me>.
    /// </summary>
    Macad::Occt::Ax2 Axes();
    void Axes(Macad::Occt::Ax2 A);
    double Angle();
    void Angle(double A);
    double VMin();
    void VMin(double V);
    double VMax();
    void VMax(double V);
    /// <summary>
    /// Returns a face with  no edges.  The surface is the
    /// lateral surface with normals pointing outward. The
    /// U parameter is the angle with the  origin on the X
    /// axis. The  V parameter is   the  parameter of  the
    /// meridian.
    /// </summary>
    Macad::Occt::TopoDS_Face^ MakeEmptyLateralFace();
    /// <summary>
    /// Returns  an  edge with  a 3D curve   made from the
    /// meridian  in the XZ  plane rotated by <Ang> around
    /// the Z-axis. Ang may be 0 or myAngle.
    /// </summary>
    Macad::Occt::TopoDS_Edge^ MakeEmptyMeridianEdge(double Ang);
    /// <summary>
    /// Sets the  parametric curve of the  edge <E> in the
    /// face  <F> to be  the   2d representation  of   the
    /// meridian.
    /// </summary>
    void SetMeridianPCurve(Macad::Occt::TopoDS_Edge^ E, Macad::Occt::TopoDS_Face^ F);
    /// <summary>
    /// Returns the meridian point at parameter <V> in the
    /// plane XZ.
    /// </summary>
    Macad::Occt::Pnt2d MeridianValue(double V);
    /// <summary>
    /// Returns True if the point of  parameter <V> on the
    /// meridian is on the Axis. Default implementation is
    /// Abs(MeridianValue(V).X()) < Precision::Confusion()
    /// </summary>
    bool MeridianOnAxis(double V);
    /// <summary>
    /// Returns True  if the  meridian is  closed. Default
    /// implementation                                  is
    /// MeridianValue(VMin).IsEqual(MeridianValue(VMax),
    /// Precision::Confusion())
    /// </summary>
    bool MeridianClosed();
    /// <summary>
    /// Returns  True   if  VMax    is  infinite.  Default
    /// Precision::IsPositiveInfinite(VMax);
    /// </summary>
    bool VMaxInfinite();
    /// <summary>
    /// Returns  True   if  VMin    is  infinite.  Default
    /// Precision::IsNegativeInfinite(VMax);
    /// </summary>
    bool VMinInfinite();
    /// <summary>
    /// Returns True if  there is  a top  face.
    /// 
    /// That is neither : VMaxInfinite()
    /// MeridianClosed()
    /// MeridianOnAxis(VMax)
    /// </summary>
    bool HasTop();
    /// <summary>
    /// Returns   True if there is   a bottom  face.
    /// 
    /// That is neither : VMinInfinite()
    /// MeridianClosed()
    /// MeridianOnAxis(VMin)
    /// </summary>
    bool HasBottom();
    /// <summary>
    /// Returns True if  there are Start   and  End faces.
    /// 
    /// That is : 2*PI  - Angle > Precision::Angular()
    /// </summary>
    bool HasSides();
    /// <summary>
    /// Returns the Shell containing all the  Faces of the
    /// primitive.
    /// </summary>
    Macad::Occt::TopoDS_Shell^ Shell();
    /// <summary>
    /// Returns  the lateral Face.   It is oriented toward
    /// the outside of the primitive.
    /// </summary>
    Macad::Occt::TopoDS_Face^ LateralFace();
    /// <summary>
    /// Returns the   top planar  Face.    It  is Oriented
    /// toward the +Z axis (outside).
    /// </summary>
    Macad::Occt::TopoDS_Face^ TopFace();
    /// <summary>
    /// Returns  the Bottom planar Face.   It is  Oriented
    /// toward the -Z axis (outside).
    /// </summary>
    Macad::Occt::TopoDS_Face^ BottomFace();
    /// <summary>
    /// Returns  the  Face   starting   the slice, it   is
    /// oriented toward the exterior of the primitive.
    /// </summary>
    Macad::Occt::TopoDS_Face^ StartFace();
    /// <summary>
    /// Returns the Face ending the slice, it  is oriented
    /// toward the exterior of the primitive.
    /// </summary>
    Macad::Occt::TopoDS_Face^ EndFace();
    /// <summary>
    /// Returns  the wire in the lateral face.
    /// </summary>
    Macad::Occt::TopoDS_Wire^ LateralWire();
    /// <summary>
    /// Returns the   wire in the   lateral  face with the
    /// start edge.
    /// </summary>
    Macad::Occt::TopoDS_Wire^ LateralStartWire();
    /// <summary>
    /// Returns the wire with in lateral face with the end
    /// edge.
    /// </summary>
    Macad::Occt::TopoDS_Wire^ LateralEndWire();
    /// <summary>
    /// Returns the wire in the top face.
    /// </summary>
    Macad::Occt::TopoDS_Wire^ TopWire();
    /// <summary>
    /// Returns the wire in the bottom face.
    /// </summary>
    Macad::Occt::TopoDS_Wire^ BottomWire();
    /// <summary>
    /// Returns the wire  in the  start face.
    /// </summary>
    Macad::Occt::TopoDS_Wire^ StartWire();
    /// <summary>
    /// Returns  the wire   in the  start   face  with the
    /// AxisEdge.
    /// </summary>
    Macad::Occt::TopoDS_Wire^ AxisStartWire();
    /// <summary>
    /// Returns the Wire in   the end face.
    /// </summary>
    Macad::Occt::TopoDS_Wire^ EndWire();
    /// <summary>
    /// Returns  the Wire  in  the   end   face  with  the
    /// AxisEdge.
    /// </summary>
    Macad::Occt::TopoDS_Wire^ AxisEndWire();
    /// <summary>
    /// Returns the Edge built along the Axis and oriented
    /// on +Z of the Axis.
    /// </summary>
    Macad::Occt::TopoDS_Edge^ AxisEdge();
    /// <summary>
    /// Returns the   Edge at angle 0.
    /// </summary>
    Macad::Occt::TopoDS_Edge^ StartEdge();
    /// <summary>
    /// Returns the  Edge at  angle Angle.  If !HasSides()
    /// the StartEdge and the EndEdge are the same edge.
    /// </summary>
    Macad::Occt::TopoDS_Edge^ EndEdge();
    /// <summary>
    /// Returns the linear Edge between start Face and top
    /// Face.
    /// </summary>
    Macad::Occt::TopoDS_Edge^ StartTopEdge();
    /// <summary>
    /// Returns the linear  Edge between  start  Face  and
    /// bottom Face.
    /// </summary>
    Macad::Occt::TopoDS_Edge^ StartBottomEdge();
    /// <summary>
    /// Returns the linear Edge  between end Face and  top
    /// Face.
    /// </summary>
    Macad::Occt::TopoDS_Edge^ EndTopEdge();
    /// <summary>
    /// Returns  the  linear  Edge  between end  Face  and
    /// bottom Face.
    /// </summary>
    Macad::Occt::TopoDS_Edge^ EndBottomEdge();
    /// <summary>
    /// Returns the edge at VMax. If  MeridianClosed() the
    /// TopEdge and the BottomEdge are the same edge.
    /// </summary>
    Macad::Occt::TopoDS_Edge^ TopEdge();
    /// <summary>
    /// Returns the edge  at VMin. If MeridianClosed() the
    /// TopEdge and the BottomEdge are the same edge.
    /// </summary>
    Macad::Occt::TopoDS_Edge^ BottomEdge();
    /// <summary>
    /// Returns the Vertex at the Top altitude on the axis.
    /// </summary>
    Macad::Occt::TopoDS_Vertex^ AxisTopVertex();
    /// <summary>
    /// Returns the Vertex  at the Bottom  altitude on the
    /// axis.
    /// </summary>
    Macad::Occt::TopoDS_Vertex^ AxisBottomVertex();
    /// <summary>
    /// Returns the vertex (0,VMax)
    /// </summary>
    Macad::Occt::TopoDS_Vertex^ TopStartVertex();
    /// <summary>
    /// Returns the vertex (angle,VMax)
    /// </summary>
    Macad::Occt::TopoDS_Vertex^ TopEndVertex();
    /// <summary>
    /// Returns the vertex (0,VMin)
    /// </summary>
    Macad::Occt::TopoDS_Vertex^ BottomStartVertex();
    /// <summary>
    /// Returns the vertex (angle,VMax)
    /// </summary>
    Macad::Occt::TopoDS_Vertex^ BottomEndVertex();
}; // class BRepPrim_OneAxis

//---------------------------------------------------------------------
//  Class  BRepPrim_Revolution
//---------------------------------------------------------------------
/// <summary>
/// Implement  the OneAxis algorithm   for a revolution
/// surface.
/// </summary>
public ref class BRepPrim_Revolution
    : public Macad::Occt::BRepPrim_OneAxis
{

#ifdef Include_BRepPrim_Revolution_h
public:
    Include_BRepPrim_Revolution_h
#endif

protected:
    BRepPrim_Revolution(InitMode init)
        : Macad::Occt::BRepPrim_OneAxis( init )
    {}

public:
    BRepPrim_Revolution(::BRepPrim_Revolution* nativeInstance)
        : Macad::Occt::BRepPrim_OneAxis( nativeInstance )
    {}

    BRepPrim_Revolution(::BRepPrim_Revolution& nativeInstance)
        : Macad::Occt::BRepPrim_OneAxis( nativeInstance )
    {}

    property ::BRepPrim_Revolution* NativeInstance
    {
        ::BRepPrim_Revolution* get()
        {
            return static_cast<::BRepPrim_Revolution*>(_NativeInstance);
        }
    }

public:
    /// <summary>
    /// Create a  revolution body <M>  is the  meridian nd
    /// must   be in the XZ  plane   of <A>. <PM>  is  the
    /// meridian in the XZ plane.
    /// </summary>
    BRepPrim_Revolution(Macad::Occt::Ax2 A, double VMin, double VMax, Macad::Occt::Geom_Curve^ M, Macad::Occt::Geom2d_Curve^ PM);
    /// <summary>
    /// The surface normal should be directed  towards the
    /// outside.
    /// </summary>
    Macad::Occt::TopoDS_Face^ MakeEmptyLateralFace();
    /// <summary>
    /// Returns  an  edge with  a 3D curve   made from the
    /// meridian  in the XZ  plane rotated by <Ang> around
    /// the Z-axis. Ang may be 0 or myAngle.
    /// </summary>
    Macad::Occt::TopoDS_Edge^ MakeEmptyMeridianEdge(double Ang);
    /// <summary>
    /// Returns the meridian point at parameter <V> in the
    /// plane XZ.
    /// </summary>
    Macad::Occt::Pnt2d MeridianValue(double V);
    /// <summary>
    /// Sets the  parametric urve of  the edge <E>  in the
    /// face <F>   to be  the  2d  representation  of  the
    /// meridian.
    /// </summary>
    void SetMeridianPCurve(Macad::Occt::TopoDS_Edge^ E, Macad::Occt::TopoDS_Face^ F);
}; // class BRepPrim_Revolution

//---------------------------------------------------------------------
//  Class  BRepPrim_Cone
//---------------------------------------------------------------------
/// <summary>
/// Implement the cone primitive.
/// </summary>
public ref class BRepPrim_Cone sealed
    : public Macad::Occt::BRepPrim_Revolution
{

#ifdef Include_BRepPrim_Cone_h
public:
    Include_BRepPrim_Cone_h
#endif

public:
    BRepPrim_Cone(::BRepPrim_Cone* nativeInstance)
        : Macad::Occt::BRepPrim_Revolution( nativeInstance )
    {}

    BRepPrim_Cone(::BRepPrim_Cone& nativeInstance)
        : Macad::Occt::BRepPrim_Revolution( nativeInstance )
    {}

    property ::BRepPrim_Cone* NativeInstance
    {
        ::BRepPrim_Cone* get()
        {
            return static_cast<::BRepPrim_Cone*>(_NativeInstance);
        }
    }

public:
    /// <summary>
    /// the STEP definition
    /// Angle = semi-angle of the cone
    /// Position : the coordinate system
    /// Height : height of the cone.
    /// Radius : radius of truncated face at z = 0
    /// 
    /// The apex is on z < 0
    /// 
    /// Errors : Height < Resolution
    /// Angle < Resolution / Height
    /// Angle > PI/2 - Resolution / Height
    /// </summary>
    BRepPrim_Cone(double Angle, Macad::Occt::Ax2 Position, double Height, double Radius);
    /// <summary>
    /// the STEP definition
    /// Angle = semi-angle of the cone
    /// Position : the coordinate system
    /// Height : height of the cone.
    /// Radius : radius of truncated face at z = 0
    /// 
    /// The apex is on z < 0
    /// 
    /// Errors : Height < Resolution
    /// Angle < Resolution / Height
    /// Angle > PI/2 - Resolution / Height
    /// </summary>
    BRepPrim_Cone(double Angle, Macad::Occt::Ax2 Position, double Height);
    /// <summary>
    /// infinite cone at origin on Z negative
    /// </summary>
    BRepPrim_Cone(double Angle);
    /// <summary>
    /// infinite cone at Apex on Z negative
    /// </summary>
    BRepPrim_Cone(double Angle, Macad::Occt::Pnt Apex);
    /// <summary>
    /// infinite cone with Axes
    /// </summary>
    BRepPrim_Cone(double Angle, Macad::Occt::Ax2 Axes);
    /// <summary>
    /// create a  Cone at origin  on Z axis, of height  H,
    /// radius R1 at Z = 0, R2 at  Z = H, X is  the origin
    /// of angles.  If R1 or  R2 is 0   there is  an apex.
    /// Otherwise, it is a truncated cone.
    /// 
    /// Error  : R1 and R2  < Resolution
    /// R1 or R2 negative
    /// Abs(R1-R2) < Resolution
    /// H < Resolution
    /// H negative
    /// </summary>
    BRepPrim_Cone(double R1, double R2, double H);
    /// <summary>
    /// same as above but at a given point
    /// </summary>
    BRepPrim_Cone(Macad::Occt::Pnt Center, double R1, double R2, double H);
    /// <summary>
    /// same as above with given axes system.
    /// </summary>
    BRepPrim_Cone(Macad::Occt::Ax2 Axes, double R1, double R2, double H);
    /// <summary>
    /// The surface normal should be directed  towards the
    /// outside.
    /// </summary>
    Macad::Occt::TopoDS_Face^ MakeEmptyLateralFace();
}; // class BRepPrim_Cone

//---------------------------------------------------------------------
//  Class  BRepPrim_Cylinder
//---------------------------------------------------------------------
/// <summary>
/// Cylinder primitive.
/// </summary>
public ref class BRepPrim_Cylinder sealed
    : public Macad::Occt::BRepPrim_Revolution
{

#ifdef Include_BRepPrim_Cylinder_h
public:
    Include_BRepPrim_Cylinder_h
#endif

public:
    BRepPrim_Cylinder(::BRepPrim_Cylinder* nativeInstance)
        : Macad::Occt::BRepPrim_Revolution( nativeInstance )
    {}

    BRepPrim_Cylinder(::BRepPrim_Cylinder& nativeInstance)
        : Macad::Occt::BRepPrim_Revolution( nativeInstance )
    {}

    property ::BRepPrim_Cylinder* NativeInstance
    {
        ::BRepPrim_Cylinder* get()
        {
            return static_cast<::BRepPrim_Cylinder*>(_NativeInstance);
        }
    }

public:
    /// <summary>
    /// the STEP definition
    /// Position : center of a Face and Axis
    /// Radius : radius of cylinder
    /// Height : distance between faces
    /// on positive side
    /// 
    /// Errors : Height < Resolution
    /// Radius < Resolution
    /// </summary>
    BRepPrim_Cylinder(Macad::Occt::Ax2 Position, double Radius, double Height);
    /// <summary>
    /// infinite Cylinder at origin on Z negative
    /// </summary>
    BRepPrim_Cylinder(double Radius);
    /// <summary>
    /// infinite Cylinder at Center on Z negative
    /// </summary>
    BRepPrim_Cylinder(Macad::Occt::Pnt Center, double Radius);
    /// <summary>
    /// infinite Cylinder at Axes on Z negative
    /// </summary>
    BRepPrim_Cylinder(Macad::Occt::Ax2 Axes, double Radius);
    /// <summary>
    /// create a Cylinder  at origin on Z  axis, of
    /// height H and radius R
    /// Error  : Radius  < Resolution
    /// H < Resolution
    /// H negative
    /// </summary>
    BRepPrim_Cylinder(double R, double H);
    /// <summary>
    /// same as above but at a given point
    /// </summary>
    BRepPrim_Cylinder(Macad::Occt::Pnt Center, double R, double H);
    /// <summary>
    /// The surface normal should be directed  towards the
    /// outside.
    /// </summary>
    Macad::Occt::TopoDS_Face^ MakeEmptyLateralFace();
}; // class BRepPrim_Cylinder

//---------------------------------------------------------------------
//  Class  BRepPrim_FaceBuilder
//---------------------------------------------------------------------
/// <summary>
/// The  FaceBuilder is an algorithm   to build a BRep
/// Face from a Geom Surface.
/// 
/// The  face covers  the  whole surface or  the  area
/// delimited by UMin, UMax, VMin, VMax
/// </summary>
public ref class BRepPrim_FaceBuilder sealed
    : public Macad::Occt::BaseClass<::BRepPrim_FaceBuilder>
{

#ifdef Include_BRepPrim_FaceBuilder_h
public:
    Include_BRepPrim_FaceBuilder_h
#endif

public:
    BRepPrim_FaceBuilder(::BRepPrim_FaceBuilder* nativeInstance)
        : Macad::Occt::BaseClass<::BRepPrim_FaceBuilder>( nativeInstance, true )
    {}

    BRepPrim_FaceBuilder(::BRepPrim_FaceBuilder& nativeInstance)
        : Macad::Occt::BaseClass<::BRepPrim_FaceBuilder>( &nativeInstance, false )
    {}

    property ::BRepPrim_FaceBuilder* NativeInstance
    {
        ::BRepPrim_FaceBuilder* get()
        {
            return static_cast<::BRepPrim_FaceBuilder*>(_NativeInstance);
        }
    }

public:
    BRepPrim_FaceBuilder();
    BRepPrim_FaceBuilder(Macad::Occt::BRep_Builder^ B, Macad::Occt::Geom_Surface^ S);
    BRepPrim_FaceBuilder(Macad::Occt::BRep_Builder^ B, Macad::Occt::Geom_Surface^ S, double UMin, double UMax, double VMin, double VMax);
    void Init(Macad::Occt::BRep_Builder^ B, Macad::Occt::Geom_Surface^ S);
    void Init(Macad::Occt::BRep_Builder^ B, Macad::Occt::Geom_Surface^ S, double UMin, double UMax, double VMin, double VMax);
    Macad::Occt::TopoDS_Face^ Face();
    /// <summary>
    /// Returns the edge of index <I>
    /// 1 - Edge VMin
    /// 2 - Edge UMax
    /// 3 - Edge VMax
    /// 4 - Edge UMin
    /// </summary>
    Macad::Occt::TopoDS_Edge^ Edge(int I);
    /// <summary>
    /// Returns the vertex of index <I>
    /// 1 - Vertex UMin,VMin
    /// 2 - Vertex UMax,VMin
    /// 3 - Vertex UMax,VMax
    /// 4 - Vertex UMin,VMax
    /// </summary>
    Macad::Occt::TopoDS_Vertex^ Vertex(int I);
}; // class BRepPrim_FaceBuilder

//---------------------------------------------------------------------
//  Class  BRepPrim_GWedge
//---------------------------------------------------------------------
/// <summary>
/// A wedge is defined by:
/// 
/// Axes: an Axis2 (coordinate system)
/// 
/// YMin, YMax the  coordinates of the ymin and ymax
/// rectangular faces parallel to the ZX plane (of the
/// coordinate systems)
/// 
/// ZMin,ZMax,XMin,XMax the rectangular
/// left (YMin) face parallel to the Z and X axes.
/// 
/// Z2Min,Z2Max,X2Min,X2Max the rectangular
/// right (YMax) face parallel to the Z and X axes.
/// 
/// For a box Z2Min = ZMin, Z2Max = ZMax,
/// X2Min = XMin, X2Max = XMax
/// 
/// The wedge can be open in the corresponding direction
/// of its Boolean myInfinite
/// </summary>
public ref class BRepPrim_GWedge
    : public Macad::Occt::BaseClass<::BRepPrim_GWedge>
{

#ifdef Include_BRepPrim_GWedge_h
public:
    Include_BRepPrim_GWedge_h
#endif

protected:
    BRepPrim_GWedge(InitMode init)
        : Macad::Occt::BaseClass<::BRepPrim_GWedge>( init )
    {}

public:
    BRepPrim_GWedge(::BRepPrim_GWedge* nativeInstance)
        : Macad::Occt::BaseClass<::BRepPrim_GWedge>( nativeInstance, true )
    {}

    BRepPrim_GWedge(::BRepPrim_GWedge& nativeInstance)
        : Macad::Occt::BaseClass<::BRepPrim_GWedge>( &nativeInstance, false )
    {}

    property ::BRepPrim_GWedge* NativeInstance
    {
        ::BRepPrim_GWedge* get()
        {
            return static_cast<::BRepPrim_GWedge*>(_NativeInstance);
        }
    }

public:
    /// <summary>
    /// Default constructor
    /// </summary>
    BRepPrim_GWedge();
    /// <summary>
    /// Creates a GWedge algorithm. <Axes> is the axis
    /// system for the primitive.
    /// 
    /// XMin, YMin, ZMin are set to 0
    /// XMax, YMax, ZMax are set to dx, dy, dz
    /// Z2Min = ZMin
    /// Z2Max = ZMax
    /// X2Min = XMin
    /// X2Max = XMax
    /// The result is a box
    /// dx,dy,dz should be positive
    /// </summary>
    BRepPrim_GWedge(Macad::Occt::BRepPrim_Builder^ B, Macad::Occt::Ax2 Axes, double dx, double dy, double dz);
    /// <summary>
    /// Creates a GWedge primitive. <Axes> is the axis
    /// system for the primitive.
    /// 
    /// XMin, YMin, ZMin are set to 0
    /// XMax, YMax, ZMax are set to dx, dy, dz
    /// Z2Min = ZMin
    /// Z2Max = ZMax
    /// X2Min = ltx
    /// X2Max = ltx
    /// The result is a STEP right angular wedge
    /// dx,dy,dz should be positive
    /// ltx should not be negative
    /// </summary>
    BRepPrim_GWedge(Macad::Occt::BRepPrim_Builder^ B, Macad::Occt::Ax2 Axes, double dx, double dy, double dz, double ltx);
    /// <summary>
    /// Create a GWedge primitive. <Axes> is the axis
    /// system for the primitive.
    /// 
    /// all the fields are set to the corresponding value
    /// XYZMax - XYZMin should be positive
    /// ZX2Max - ZX2Min should not be negative
    /// </summary>
    BRepPrim_GWedge(Macad::Occt::BRepPrim_Builder^ B, Macad::Occt::Ax2 Axes, double xmin, double ymin, double zmin, double z2min, double x2min, double xmax, double ymax, double zmax, double z2max, double x2max);
    /// <summary>
    /// Returns the coordinates system from <me>.
    /// </summary>
    Macad::Occt::Ax2 Axes();
    /// <summary>
    /// Returns Xmin value from <me>.
    /// </summary>
    double GetXMin();
    /// <summary>
    /// Returns YMin value from <me>.
    /// </summary>
    double GetYMin();
    /// <summary>
    /// Returns ZMin value from <me>.
    /// </summary>
    double GetZMin();
    /// <summary>
    /// Returns Z2Min value from <me>.
    /// </summary>
    double GetZ2Min();
    /// <summary>
    /// Returns X2Min value from <me>.
    /// </summary>
    double GetX2Min();
    /// <summary>
    /// Returns XMax value from <me>.
    /// </summary>
    double GetXMax();
    /// <summary>
    /// Returns YMax value from <me>.
    /// </summary>
    double GetYMax();
    /// <summary>
    /// Returns ZMax value from <me>.
    /// </summary>
    double GetZMax();
    /// <summary>
    /// Returns Z2Max value from <me>.
    /// </summary>
    double GetZ2Max();
    /// <summary>
    /// Returns X2Max value from <me>.
    /// </summary>
    double GetX2Max();
    /// <summary>
    /// Opens <me> in <d1> direction. A face and its edges
    /// or vertices are said nonexistent.
    /// </summary>
    void Open(Macad::Occt::BRepPrim_Direction d1);
    /// <summary>
    /// Closes <me> in <d1> direction. A face and its
    /// edges or vertices are said existent.
    /// </summary>
    void Close(Macad::Occt::BRepPrim_Direction d1);
    /// <summary>
    /// Returns True if <me> is open in <d1> direction.
    /// </summary>
    bool IsInfinite(Macad::Occt::BRepPrim_Direction d1);
    /// <summary>
    /// Returns the Shell containing the Faces of <me>.
    /// </summary>
    Macad::Occt::TopoDS_Shell^ Shell();
    /// <summary>
    /// Returns True if <me> has a Face in <d1> direction.
    /// </summary>
    bool HasFace(Macad::Occt::BRepPrim_Direction d1);
    /// <summary>
    /// Returns the Face of <me> located in <d1> direction.
    /// </summary>
    Macad::Occt::TopoDS_Face^ Face(Macad::Occt::BRepPrim_Direction d1);
    /// <summary>
    /// Returns the plane of the Face of <me> located in
    /// <d1> direction.
    /// </summary>
    Macad::Occt::Pln Plane(Macad::Occt::BRepPrim_Direction d1);
    /// <summary>
    /// Returns True if <me> has a Wire in <d1> direction.
    /// </summary>
    bool HasWire(Macad::Occt::BRepPrim_Direction d1);
    /// <summary>
    /// Returns the Wire of <me> located in <d1> direction.
    /// </summary>
    Macad::Occt::TopoDS_Wire^ Wire(Macad::Occt::BRepPrim_Direction d1);
    /// <summary>
    /// Returns True if <me> has an Edge in <d1><d2> direction.
    /// </summary>
    bool HasEdge(Macad::Occt::BRepPrim_Direction d1, Macad::Occt::BRepPrim_Direction d2);
    /// <summary>
    /// Returns the Edge of <me> located in <d1><d2> direction.
    /// </summary>
    Macad::Occt::TopoDS_Edge^ Edge(Macad::Occt::BRepPrim_Direction d1, Macad::Occt::BRepPrim_Direction d2);
    /// <summary>
    /// Returns the line of the Edge of <me> located in
    /// <d1><d2> direction.
    /// </summary>
    Macad::Occt::gp_Lin^ Line(Macad::Occt::BRepPrim_Direction d1, Macad::Occt::BRepPrim_Direction d2);
    /// <summary>
    /// Returns True if <me> has a Vertex in <d1><d2><d3>
    /// direction.
    /// </summary>
    bool HasVertex(Macad::Occt::BRepPrim_Direction d1, Macad::Occt::BRepPrim_Direction d2, Macad::Occt::BRepPrim_Direction d3);
    /// <summary>
    /// Returns the Vertex of <me> located in <d1><d2><d3>
    /// direction.
    /// </summary>
    Macad::Occt::TopoDS_Vertex^ Vertex(Macad::Occt::BRepPrim_Direction d1, Macad::Occt::BRepPrim_Direction d2, Macad::Occt::BRepPrim_Direction d3);
    /// <summary>
    /// Returns the point of the Vertex of <me> located in
    /// <d1><d2><d3> direction.
    /// </summary>
    Macad::Occt::Pnt Point(Macad::Occt::BRepPrim_Direction d1, Macad::Occt::BRepPrim_Direction d2, Macad::Occt::BRepPrim_Direction d3);
    /// <summary>
    /// Checks a shape on degeneracy
    /// </summary>
    /// <returns>
    /// TRUE if a shape is degenerated
    /// </returns>
    bool IsDegeneratedShape();
}; // class BRepPrim_GWedge

//---------------------------------------------------------------------
//  Class  BRepPrim_Sphere
//---------------------------------------------------------------------
/// <summary>
/// Implements the sphere primitive
/// </summary>
public ref class BRepPrim_Sphere sealed
    : public Macad::Occt::BRepPrim_Revolution
{

#ifdef Include_BRepPrim_Sphere_h
public:
    Include_BRepPrim_Sphere_h
#endif

public:
    BRepPrim_Sphere(::BRepPrim_Sphere* nativeInstance)
        : Macad::Occt::BRepPrim_Revolution( nativeInstance )
    {}

    BRepPrim_Sphere(::BRepPrim_Sphere& nativeInstance)
        : Macad::Occt::BRepPrim_Revolution( nativeInstance )
    {}

    property ::BRepPrim_Sphere* NativeInstance
    {
        ::BRepPrim_Sphere* get()
        {
            return static_cast<::BRepPrim_Sphere*>(_NativeInstance);
        }
    }

public:
    /// <summary>
    /// Creates a Sphere at  origin with  Radius. The axes
    /// of the sphere are the  reference axes. An error is
    /// raised if the radius is < Resolution.
    /// </summary>
    BRepPrim_Sphere(double Radius);
    /// <summary>
    /// Creates a Sphere with Center and Radius.
    /// Axes are the reference axes.
    /// This is the STEP constructor.
    /// </summary>
    BRepPrim_Sphere(Macad::Occt::Pnt Center, double Radius);
    /// <summary>
    /// Creates a sphere with given axes system.
    /// </summary>
    BRepPrim_Sphere(Macad::Occt::Ax2 Axes, double Radius);
    /// <summary>
    /// The surface normal should be directed  towards the
    /// outside.
    /// </summary>
    Macad::Occt::TopoDS_Face^ MakeEmptyLateralFace();
}; // class BRepPrim_Sphere

//---------------------------------------------------------------------
//  Class  BRepPrim_Torus
//---------------------------------------------------------------------
/// <summary>
/// Implements the torus primitive
/// </summary>
public ref class BRepPrim_Torus sealed
    : public Macad::Occt::BRepPrim_Revolution
{

#ifdef Include_BRepPrim_Torus_h
public:
    Include_BRepPrim_Torus_h
#endif

public:
    BRepPrim_Torus(::BRepPrim_Torus* nativeInstance)
        : Macad::Occt::BRepPrim_Revolution( nativeInstance )
    {}

    BRepPrim_Torus(::BRepPrim_Torus& nativeInstance)
        : Macad::Occt::BRepPrim_Revolution( nativeInstance )
    {}

    property ::BRepPrim_Torus* NativeInstance
    {
        ::BRepPrim_Torus* get()
        {
            return static_cast<::BRepPrim_Torus*>(_NativeInstance);
        }
    }

public:
    /// <summary>
    /// the STEP definition
    /// Position : center and axes
    /// Major, Minor : Radii
    /// 
    /// Errors : Major < Resolution
    /// Minor < Resolution
    /// </summary>
    BRepPrim_Torus(Macad::Occt::Ax2 Position, double Major, double Minor);
    /// <summary>
    /// Torus centered at origin
    /// </summary>
    BRepPrim_Torus(double Major, double Minor);
    /// <summary>
    /// Torus at Center
    /// </summary>
    BRepPrim_Torus(Macad::Occt::Pnt Center, double Major, double Minor);
    /// <summary>
    /// The surface normal should be directed  towards the
    /// outside.
    /// </summary>
    Macad::Occt::TopoDS_Face^ MakeEmptyLateralFace();
}; // class BRepPrim_Torus

//---------------------------------------------------------------------
//  Class  BRepPrim_Wedge
//---------------------------------------------------------------------
/// <summary>
/// Provides constructors without Builders.
/// </summary>
public ref class BRepPrim_Wedge sealed
    : public Macad::Occt::BRepPrim_GWedge
{

#ifdef Include_BRepPrim_Wedge_h
public:
    Include_BRepPrim_Wedge_h
#endif

public:
    BRepPrim_Wedge(::BRepPrim_Wedge* nativeInstance)
        : Macad::Occt::BRepPrim_GWedge( nativeInstance )
    {}

    BRepPrim_Wedge(::BRepPrim_Wedge& nativeInstance)
        : Macad::Occt::BRepPrim_GWedge( nativeInstance )
    {}

    property ::BRepPrim_Wedge* NativeInstance
    {
        ::BRepPrim_Wedge* get()
        {
            return static_cast<::BRepPrim_Wedge*>(_NativeInstance);
        }
    }

public:
    /// <summary>
    /// Default constructor
    /// </summary>
    BRepPrim_Wedge();
    /// <summary>
    /// Creates a  Wedge  algorithm.   <Axes> is  the axis
    /// system for the primitive.
    /// 
    /// XMin, YMin, ZMin are set to 0
    /// XMax, YMax, ZMax are set to dx, dy, dz
    /// Z2Min = ZMin
    /// Z2Max = ZMax
    /// X2Min = XMin
    /// X2Max = XMax
    /// The result is a box
    /// dx,dy,dz should be positive
    /// </summary>
    BRepPrim_Wedge(Macad::Occt::Ax2 Axes, double dx, double dy, double dz);
    /// <summary>
    /// Creates  a Wedge  primitive. <Axes> is   the  axis
    /// system for the primitive.
    /// 
    /// XMin, YMin, ZMin are set to 0
    /// XMax, YMax, ZMax are set to dx, dy, dz
    /// Z2Min = ZMin
    /// Z2Max = ZMax
    /// X2Min = ltx
    /// X2Max = ltx
    /// The result is a STEP right angular wedge
    /// dx,dy,dz should be positive
    /// ltx should not be negative
    /// </summary>
    BRepPrim_Wedge(Macad::Occt::Ax2 Axes, double dx, double dy, double dz, double ltx);
    /// <summary>
    /// Create  a Wedge primitive.   <Axes>  is  the  axis
    /// system for the primitive.
    /// 
    /// all the fields are set to the corresponding value
    /// XYZMax - XYZMin should be positive
    /// ZX2Max - ZX2Min should not be negative
    /// </summary>
    BRepPrim_Wedge(Macad::Occt::Ax2 Axes, double xmin, double ymin, double zmin, double z2min, double x2min, double xmax, double ymax, double zmax, double z2max, double x2max);
}; // class BRepPrim_Wedge

}; // namespace Occt
}; // namespace Macad
