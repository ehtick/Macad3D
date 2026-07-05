// Generated wrapper code for package BRepPrim

#include "OcctPCH.h"
#include "BRepPrim.h"

using namespace System::Runtime::InteropServices; // for class Marshal

#include "BRep.h"
#include "TopoDS.h"
#include "gp.h"
#include "Geom.h"
#include "Geom2d.h"


//---------------------------------------------------------------------
//  Class  BRepPrim_Builder
//---------------------------------------------------------------------

Macad::Occt::BRepPrim_Builder::BRepPrim_Builder()
    : Macad::Occt::BaseClass<::BRepPrim_Builder>(BaseClass::InitMode::Uninitialized)
{
    _NativeInstance = new ::BRepPrim_Builder();
}

Macad::Occt::BRepPrim_Builder::BRepPrim_Builder(Macad::Occt::BRep_Builder^ B)
    : Macad::Occt::BaseClass<::BRepPrim_Builder>(BaseClass::InitMode::Uninitialized)
{
    _NativeInstance = new ::BRepPrim_Builder(*(::BRep_Builder*)B->NativeInstance);
}

Macad::Occt::BRep_Builder^ Macad::Occt::BRepPrim_Builder::Builder()
{
    ::BRep_Builder* _result = new ::BRep_Builder();
    *_result = (::BRep_Builder)((::BRepPrim_Builder*)_NativeInstance)->Builder();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::BRep_Builder(_result);
}

void Macad::Occt::BRepPrim_Builder::MakeShell(Macad::Occt::TopoDS_Shell^ S)
{
    ((::BRepPrim_Builder*)_NativeInstance)->MakeShell(*(::TopoDS_Shell*)S->NativeInstance);
}

void Macad::Occt::BRepPrim_Builder::MakeFace(Macad::Occt::TopoDS_Face^ F, Macad::Occt::Pln P)
{
    pin_ptr<Macad::Occt::Pln> pp_P = &P;
    ((::BRepPrim_Builder*)_NativeInstance)->MakeFace(*(::TopoDS_Face*)F->NativeInstance, *(gp_Pln*)pp_P);
}

void Macad::Occt::BRepPrim_Builder::MakeWire(Macad::Occt::TopoDS_Wire^ W)
{
    ((::BRepPrim_Builder*)_NativeInstance)->MakeWire(*(::TopoDS_Wire*)W->NativeInstance);
}

void Macad::Occt::BRepPrim_Builder::MakeDegeneratedEdge(Macad::Occt::TopoDS_Edge^ E)
{
    ((::BRepPrim_Builder*)_NativeInstance)->MakeDegeneratedEdge(*(::TopoDS_Edge*)E->NativeInstance);
}

void Macad::Occt::BRepPrim_Builder::MakeEdge(Macad::Occt::TopoDS_Edge^ E, Macad::Occt::gp_Lin^ L)
{
    ((::BRepPrim_Builder*)_NativeInstance)->MakeEdge(*(::TopoDS_Edge*)E->NativeInstance, *(::gp_Lin*)L->NativeInstance);
}

void Macad::Occt::BRepPrim_Builder::MakeEdge(Macad::Occt::TopoDS_Edge^ E, Macad::Occt::gp_Circ^ C)
{
    ((::BRepPrim_Builder*)_NativeInstance)->MakeEdge(*(::TopoDS_Edge*)E->NativeInstance, *(::gp_Circ*)C->NativeInstance);
}

void Macad::Occt::BRepPrim_Builder::SetPCurve(Macad::Occt::TopoDS_Edge^ E, Macad::Occt::TopoDS_Face^ F, Macad::Occt::gp_Lin2d^ L)
{
    ((::BRepPrim_Builder*)_NativeInstance)->SetPCurve(*(::TopoDS_Edge*)E->NativeInstance, *(::TopoDS_Face*)F->NativeInstance, *(::gp_Lin2d*)L->NativeInstance);
}

void Macad::Occt::BRepPrim_Builder::SetPCurve(Macad::Occt::TopoDS_Edge^ E, Macad::Occt::TopoDS_Face^ F, Macad::Occt::gp_Lin2d^ L1, Macad::Occt::gp_Lin2d^ L2)
{
    ((::BRepPrim_Builder*)_NativeInstance)->SetPCurve(*(::TopoDS_Edge*)E->NativeInstance, *(::TopoDS_Face*)F->NativeInstance, *(::gp_Lin2d*)L1->NativeInstance, *(::gp_Lin2d*)L2->NativeInstance);
}

void Macad::Occt::BRepPrim_Builder::SetPCurve(Macad::Occt::TopoDS_Edge^ E, Macad::Occt::TopoDS_Face^ F, Macad::Occt::gp_Circ2d^ C)
{
    ((::BRepPrim_Builder*)_NativeInstance)->SetPCurve(*(::TopoDS_Edge*)E->NativeInstance, *(::TopoDS_Face*)F->NativeInstance, *(::gp_Circ2d*)C->NativeInstance);
}

void Macad::Occt::BRepPrim_Builder::MakeVertex(Macad::Occt::TopoDS_Vertex^ V, Macad::Occt::Pnt P)
{
    pin_ptr<Macad::Occt::Pnt> pp_P = &P;
    ((::BRepPrim_Builder*)_NativeInstance)->MakeVertex(*(::TopoDS_Vertex*)V->NativeInstance, *(gp_Pnt*)pp_P);
}

void Macad::Occt::BRepPrim_Builder::ReverseFace(Macad::Occt::TopoDS_Face^ F)
{
    ((::BRepPrim_Builder*)_NativeInstance)->ReverseFace(*(::TopoDS_Face*)F->NativeInstance);
}

void Macad::Occt::BRepPrim_Builder::AddEdgeVertex(Macad::Occt::TopoDS_Edge^ E, Macad::Occt::TopoDS_Vertex^ V, double P, bool direct)
{
    ((::BRepPrim_Builder*)_NativeInstance)->AddEdgeVertex(*(::TopoDS_Edge*)E->NativeInstance, *(::TopoDS_Vertex*)V->NativeInstance, P, direct);
}

void Macad::Occt::BRepPrim_Builder::AddEdgeVertex(Macad::Occt::TopoDS_Edge^ E, Macad::Occt::TopoDS_Vertex^ V, double P1, double P2)
{
    ((::BRepPrim_Builder*)_NativeInstance)->AddEdgeVertex(*(::TopoDS_Edge*)E->NativeInstance, *(::TopoDS_Vertex*)V->NativeInstance, P1, P2);
}

void Macad::Occt::BRepPrim_Builder::SetParameters(Macad::Occt::TopoDS_Edge^ E, Macad::Occt::TopoDS_Vertex^ V, double P1, double P2)
{
    ((::BRepPrim_Builder*)_NativeInstance)->SetParameters(*(::TopoDS_Edge*)E->NativeInstance, *(::TopoDS_Vertex*)V->NativeInstance, P1, P2);
}

void Macad::Occt::BRepPrim_Builder::AddWireEdge(Macad::Occt::TopoDS_Wire^ W, Macad::Occt::TopoDS_Edge^ E, bool direct)
{
    ((::BRepPrim_Builder*)_NativeInstance)->AddWireEdge(*(::TopoDS_Wire*)W->NativeInstance, *(::TopoDS_Edge*)E->NativeInstance, direct);
}

void Macad::Occt::BRepPrim_Builder::AddFaceWire(Macad::Occt::TopoDS_Face^ F, Macad::Occt::TopoDS_Wire^ W)
{
    ((::BRepPrim_Builder*)_NativeInstance)->AddFaceWire(*(::TopoDS_Face*)F->NativeInstance, *(::TopoDS_Wire*)W->NativeInstance);
}

void Macad::Occt::BRepPrim_Builder::AddShellFace(Macad::Occt::TopoDS_Shell^ Sh, Macad::Occt::TopoDS_Face^ F)
{
    ((::BRepPrim_Builder*)_NativeInstance)->AddShellFace(*(::TopoDS_Shell*)Sh->NativeInstance, *(::TopoDS_Face*)F->NativeInstance);
}

void Macad::Occt::BRepPrim_Builder::CompleteEdge(Macad::Occt::TopoDS_Edge^ E)
{
    ((::BRepPrim_Builder*)_NativeInstance)->CompleteEdge(*(::TopoDS_Edge*)E->NativeInstance);
}

void Macad::Occt::BRepPrim_Builder::CompleteWire(Macad::Occt::TopoDS_Wire^ W)
{
    ((::BRepPrim_Builder*)_NativeInstance)->CompleteWire(*(::TopoDS_Wire*)W->NativeInstance);
}

void Macad::Occt::BRepPrim_Builder::CompleteFace(Macad::Occt::TopoDS_Face^ F)
{
    ((::BRepPrim_Builder*)_NativeInstance)->CompleteFace(*(::TopoDS_Face*)F->NativeInstance);
}

void Macad::Occt::BRepPrim_Builder::CompleteShell(Macad::Occt::TopoDS_Shell^ S)
{
    ((::BRepPrim_Builder*)_NativeInstance)->CompleteShell(*(::TopoDS_Shell*)S->NativeInstance);
}



//---------------------------------------------------------------------
//  Class  BRepPrim_OneAxis
//---------------------------------------------------------------------

void Macad::Occt::BRepPrim_OneAxis::SetMeridianOffset(double MeridianOffset)
{
    ((::BRepPrim_OneAxis*)_NativeInstance)->SetMeridianOffset(MeridianOffset);
}

void Macad::Occt::BRepPrim_OneAxis::SetMeridianOffset()
{
    ((::BRepPrim_OneAxis*)_NativeInstance)->SetMeridianOffset(0.0);
}

Macad::Occt::Ax2 Macad::Occt::BRepPrim_OneAxis::Axes()
{
    ::gp_Ax2 _nativeResult = ((::BRepPrim_OneAxis*)_NativeInstance)->Axes();
    return Macad::Occt::Ax2(_nativeResult);
}

void Macad::Occt::BRepPrim_OneAxis::Axes(Macad::Occt::Ax2 A)
{
    pin_ptr<Macad::Occt::Ax2> pp_A = &A;
    ((::BRepPrim_OneAxis*)_NativeInstance)->Axes(*(gp_Ax2*)pp_A);
}

double Macad::Occt::BRepPrim_OneAxis::Angle()
{
    double _result = ((::BRepPrim_OneAxis*)_NativeInstance)->Angle();
    return _result;
}

void Macad::Occt::BRepPrim_OneAxis::Angle(double A)
{
    ((::BRepPrim_OneAxis*)_NativeInstance)->Angle(A);
}

double Macad::Occt::BRepPrim_OneAxis::VMin()
{
    double _result = ((::BRepPrim_OneAxis*)_NativeInstance)->VMin();
    return _result;
}

void Macad::Occt::BRepPrim_OneAxis::VMin(double V)
{
    ((::BRepPrim_OneAxis*)_NativeInstance)->VMin(V);
}

double Macad::Occt::BRepPrim_OneAxis::VMax()
{
    double _result = ((::BRepPrim_OneAxis*)_NativeInstance)->VMax();
    return _result;
}

void Macad::Occt::BRepPrim_OneAxis::VMax(double V)
{
    ((::BRepPrim_OneAxis*)_NativeInstance)->VMax(V);
}

Macad::Occt::TopoDS_Face^ Macad::Occt::BRepPrim_OneAxis::MakeEmptyLateralFace()
{
    ::TopoDS_Face* _result = new ::TopoDS_Face();
    *_result = ((::BRepPrim_OneAxis*)_NativeInstance)->MakeEmptyLateralFace();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Face(_result);
}

Macad::Occt::TopoDS_Edge^ Macad::Occt::BRepPrim_OneAxis::MakeEmptyMeridianEdge(double Ang)
{
    ::TopoDS_Edge* _result = new ::TopoDS_Edge();
    *_result = ((::BRepPrim_OneAxis*)_NativeInstance)->MakeEmptyMeridianEdge(Ang);
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Edge(_result);
}

void Macad::Occt::BRepPrim_OneAxis::SetMeridianPCurve(Macad::Occt::TopoDS_Edge^ E, Macad::Occt::TopoDS_Face^ F)
{
    ((::BRepPrim_OneAxis*)_NativeInstance)->SetMeridianPCurve(*(::TopoDS_Edge*)E->NativeInstance, *(::TopoDS_Face*)F->NativeInstance);
}

Macad::Occt::Pnt2d Macad::Occt::BRepPrim_OneAxis::MeridianValue(double V)
{
    ::gp_Pnt2d _nativeResult = ((::BRepPrim_OneAxis*)_NativeInstance)->MeridianValue(V);
    return Macad::Occt::Pnt2d(_nativeResult);
}

bool Macad::Occt::BRepPrim_OneAxis::MeridianOnAxis(double V)
{
    bool _result = ((::BRepPrim_OneAxis*)_NativeInstance)->MeridianOnAxis(V);
    return _result;
}

bool Macad::Occt::BRepPrim_OneAxis::MeridianClosed()
{
    bool _result = ((::BRepPrim_OneAxis*)_NativeInstance)->MeridianClosed();
    return _result;
}

bool Macad::Occt::BRepPrim_OneAxis::VMaxInfinite()
{
    bool _result = ((::BRepPrim_OneAxis*)_NativeInstance)->VMaxInfinite();
    return _result;
}

bool Macad::Occt::BRepPrim_OneAxis::VMinInfinite()
{
    bool _result = ((::BRepPrim_OneAxis*)_NativeInstance)->VMinInfinite();
    return _result;
}

bool Macad::Occt::BRepPrim_OneAxis::HasTop()
{
    bool _result = ((::BRepPrim_OneAxis*)_NativeInstance)->HasTop();
    return _result;
}

bool Macad::Occt::BRepPrim_OneAxis::HasBottom()
{
    bool _result = ((::BRepPrim_OneAxis*)_NativeInstance)->HasBottom();
    return _result;
}

bool Macad::Occt::BRepPrim_OneAxis::HasSides()
{
    bool _result = ((::BRepPrim_OneAxis*)_NativeInstance)->HasSides();
    return _result;
}

Macad::Occt::TopoDS_Shell^ Macad::Occt::BRepPrim_OneAxis::Shell()
{
    ::TopoDS_Shell* _result = new ::TopoDS_Shell();
    *_result = (::TopoDS_Shell)((::BRepPrim_OneAxis*)_NativeInstance)->Shell();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Shell(_result);
}

Macad::Occt::TopoDS_Face^ Macad::Occt::BRepPrim_OneAxis::LateralFace()
{
    ::TopoDS_Face* _result = new ::TopoDS_Face();
    *_result = (::TopoDS_Face)((::BRepPrim_OneAxis*)_NativeInstance)->LateralFace();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Face(_result);
}

Macad::Occt::TopoDS_Face^ Macad::Occt::BRepPrim_OneAxis::TopFace()
{
    ::TopoDS_Face* _result = new ::TopoDS_Face();
    *_result = (::TopoDS_Face)((::BRepPrim_OneAxis*)_NativeInstance)->TopFace();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Face(_result);
}

Macad::Occt::TopoDS_Face^ Macad::Occt::BRepPrim_OneAxis::BottomFace()
{
    ::TopoDS_Face* _result = new ::TopoDS_Face();
    *_result = (::TopoDS_Face)((::BRepPrim_OneAxis*)_NativeInstance)->BottomFace();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Face(_result);
}

Macad::Occt::TopoDS_Face^ Macad::Occt::BRepPrim_OneAxis::StartFace()
{
    ::TopoDS_Face* _result = new ::TopoDS_Face();
    *_result = (::TopoDS_Face)((::BRepPrim_OneAxis*)_NativeInstance)->StartFace();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Face(_result);
}

Macad::Occt::TopoDS_Face^ Macad::Occt::BRepPrim_OneAxis::EndFace()
{
    ::TopoDS_Face* _result = new ::TopoDS_Face();
    *_result = (::TopoDS_Face)((::BRepPrim_OneAxis*)_NativeInstance)->EndFace();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Face(_result);
}

Macad::Occt::TopoDS_Wire^ Macad::Occt::BRepPrim_OneAxis::LateralWire()
{
    ::TopoDS_Wire* _result = new ::TopoDS_Wire();
    *_result = (::TopoDS_Wire)((::BRepPrim_OneAxis*)_NativeInstance)->LateralWire();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Wire(_result);
}

Macad::Occt::TopoDS_Wire^ Macad::Occt::BRepPrim_OneAxis::LateralStartWire()
{
    ::TopoDS_Wire* _result = new ::TopoDS_Wire();
    *_result = (::TopoDS_Wire)((::BRepPrim_OneAxis*)_NativeInstance)->LateralStartWire();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Wire(_result);
}

Macad::Occt::TopoDS_Wire^ Macad::Occt::BRepPrim_OneAxis::LateralEndWire()
{
    ::TopoDS_Wire* _result = new ::TopoDS_Wire();
    *_result = (::TopoDS_Wire)((::BRepPrim_OneAxis*)_NativeInstance)->LateralEndWire();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Wire(_result);
}

Macad::Occt::TopoDS_Wire^ Macad::Occt::BRepPrim_OneAxis::TopWire()
{
    ::TopoDS_Wire* _result = new ::TopoDS_Wire();
    *_result = (::TopoDS_Wire)((::BRepPrim_OneAxis*)_NativeInstance)->TopWire();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Wire(_result);
}

Macad::Occt::TopoDS_Wire^ Macad::Occt::BRepPrim_OneAxis::BottomWire()
{
    ::TopoDS_Wire* _result = new ::TopoDS_Wire();
    *_result = (::TopoDS_Wire)((::BRepPrim_OneAxis*)_NativeInstance)->BottomWire();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Wire(_result);
}

Macad::Occt::TopoDS_Wire^ Macad::Occt::BRepPrim_OneAxis::StartWire()
{
    ::TopoDS_Wire* _result = new ::TopoDS_Wire();
    *_result = (::TopoDS_Wire)((::BRepPrim_OneAxis*)_NativeInstance)->StartWire();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Wire(_result);
}

Macad::Occt::TopoDS_Wire^ Macad::Occt::BRepPrim_OneAxis::AxisStartWire()
{
    ::TopoDS_Wire* _result = new ::TopoDS_Wire();
    *_result = (::TopoDS_Wire)((::BRepPrim_OneAxis*)_NativeInstance)->AxisStartWire();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Wire(_result);
}

Macad::Occt::TopoDS_Wire^ Macad::Occt::BRepPrim_OneAxis::EndWire()
{
    ::TopoDS_Wire* _result = new ::TopoDS_Wire();
    *_result = (::TopoDS_Wire)((::BRepPrim_OneAxis*)_NativeInstance)->EndWire();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Wire(_result);
}

Macad::Occt::TopoDS_Wire^ Macad::Occt::BRepPrim_OneAxis::AxisEndWire()
{
    ::TopoDS_Wire* _result = new ::TopoDS_Wire();
    *_result = (::TopoDS_Wire)((::BRepPrim_OneAxis*)_NativeInstance)->AxisEndWire();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Wire(_result);
}

Macad::Occt::TopoDS_Edge^ Macad::Occt::BRepPrim_OneAxis::AxisEdge()
{
    ::TopoDS_Edge* _result = new ::TopoDS_Edge();
    *_result = (::TopoDS_Edge)((::BRepPrim_OneAxis*)_NativeInstance)->AxisEdge();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Edge(_result);
}

Macad::Occt::TopoDS_Edge^ Macad::Occt::BRepPrim_OneAxis::StartEdge()
{
    ::TopoDS_Edge* _result = new ::TopoDS_Edge();
    *_result = (::TopoDS_Edge)((::BRepPrim_OneAxis*)_NativeInstance)->StartEdge();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Edge(_result);
}

Macad::Occt::TopoDS_Edge^ Macad::Occt::BRepPrim_OneAxis::EndEdge()
{
    ::TopoDS_Edge* _result = new ::TopoDS_Edge();
    *_result = (::TopoDS_Edge)((::BRepPrim_OneAxis*)_NativeInstance)->EndEdge();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Edge(_result);
}

Macad::Occt::TopoDS_Edge^ Macad::Occt::BRepPrim_OneAxis::StartTopEdge()
{
    ::TopoDS_Edge* _result = new ::TopoDS_Edge();
    *_result = (::TopoDS_Edge)((::BRepPrim_OneAxis*)_NativeInstance)->StartTopEdge();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Edge(_result);
}

Macad::Occt::TopoDS_Edge^ Macad::Occt::BRepPrim_OneAxis::StartBottomEdge()
{
    ::TopoDS_Edge* _result = new ::TopoDS_Edge();
    *_result = (::TopoDS_Edge)((::BRepPrim_OneAxis*)_NativeInstance)->StartBottomEdge();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Edge(_result);
}

Macad::Occt::TopoDS_Edge^ Macad::Occt::BRepPrim_OneAxis::EndTopEdge()
{
    ::TopoDS_Edge* _result = new ::TopoDS_Edge();
    *_result = (::TopoDS_Edge)((::BRepPrim_OneAxis*)_NativeInstance)->EndTopEdge();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Edge(_result);
}

Macad::Occt::TopoDS_Edge^ Macad::Occt::BRepPrim_OneAxis::EndBottomEdge()
{
    ::TopoDS_Edge* _result = new ::TopoDS_Edge();
    *_result = (::TopoDS_Edge)((::BRepPrim_OneAxis*)_NativeInstance)->EndBottomEdge();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Edge(_result);
}

Macad::Occt::TopoDS_Edge^ Macad::Occt::BRepPrim_OneAxis::TopEdge()
{
    ::TopoDS_Edge* _result = new ::TopoDS_Edge();
    *_result = (::TopoDS_Edge)((::BRepPrim_OneAxis*)_NativeInstance)->TopEdge();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Edge(_result);
}

Macad::Occt::TopoDS_Edge^ Macad::Occt::BRepPrim_OneAxis::BottomEdge()
{
    ::TopoDS_Edge* _result = new ::TopoDS_Edge();
    *_result = (::TopoDS_Edge)((::BRepPrim_OneAxis*)_NativeInstance)->BottomEdge();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Edge(_result);
}

Macad::Occt::TopoDS_Vertex^ Macad::Occt::BRepPrim_OneAxis::AxisTopVertex()
{
    ::TopoDS_Vertex* _result = new ::TopoDS_Vertex();
    *_result = (::TopoDS_Vertex)((::BRepPrim_OneAxis*)_NativeInstance)->AxisTopVertex();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Vertex(_result);
}

Macad::Occt::TopoDS_Vertex^ Macad::Occt::BRepPrim_OneAxis::AxisBottomVertex()
{
    ::TopoDS_Vertex* _result = new ::TopoDS_Vertex();
    *_result = (::TopoDS_Vertex)((::BRepPrim_OneAxis*)_NativeInstance)->AxisBottomVertex();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Vertex(_result);
}

Macad::Occt::TopoDS_Vertex^ Macad::Occt::BRepPrim_OneAxis::TopStartVertex()
{
    ::TopoDS_Vertex* _result = new ::TopoDS_Vertex();
    *_result = (::TopoDS_Vertex)((::BRepPrim_OneAxis*)_NativeInstance)->TopStartVertex();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Vertex(_result);
}

Macad::Occt::TopoDS_Vertex^ Macad::Occt::BRepPrim_OneAxis::TopEndVertex()
{
    ::TopoDS_Vertex* _result = new ::TopoDS_Vertex();
    *_result = (::TopoDS_Vertex)((::BRepPrim_OneAxis*)_NativeInstance)->TopEndVertex();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Vertex(_result);
}

Macad::Occt::TopoDS_Vertex^ Macad::Occt::BRepPrim_OneAxis::BottomStartVertex()
{
    ::TopoDS_Vertex* _result = new ::TopoDS_Vertex();
    *_result = (::TopoDS_Vertex)((::BRepPrim_OneAxis*)_NativeInstance)->BottomStartVertex();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Vertex(_result);
}

Macad::Occt::TopoDS_Vertex^ Macad::Occt::BRepPrim_OneAxis::BottomEndVertex()
{
    ::TopoDS_Vertex* _result = new ::TopoDS_Vertex();
    *_result = (::TopoDS_Vertex)((::BRepPrim_OneAxis*)_NativeInstance)->BottomEndVertex();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Vertex(_result);
}



//---------------------------------------------------------------------
//  Class  BRepPrim_Revolution
//---------------------------------------------------------------------

Macad::Occt::BRepPrim_Revolution::BRepPrim_Revolution(Macad::Occt::Ax2 A, double VMin, double VMax, Macad::Occt::Geom_Curve^ M, Macad::Occt::Geom2d_Curve^ PM)
    : Macad::Occt::BRepPrim_OneAxis(BaseClass::InitMode::Uninitialized)
{
    pin_ptr<Macad::Occt::Ax2> pp_A = &A;
    _NativeInstance = new ::BRepPrim_Revolution(*(gp_Ax2*)pp_A, VMin, VMax, Handle(::Geom_Curve)(M->NativeInstance), Handle(::Geom2d_Curve)(PM->NativeInstance));
}

Macad::Occt::TopoDS_Face^ Macad::Occt::BRepPrim_Revolution::MakeEmptyLateralFace()
{
    ::TopoDS_Face* _result = new ::TopoDS_Face();
    *_result = ((::BRepPrim_Revolution*)_NativeInstance)->MakeEmptyLateralFace();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Face(_result);
}

Macad::Occt::TopoDS_Edge^ Macad::Occt::BRepPrim_Revolution::MakeEmptyMeridianEdge(double Ang)
{
    ::TopoDS_Edge* _result = new ::TopoDS_Edge();
    *_result = ((::BRepPrim_Revolution*)_NativeInstance)->MakeEmptyMeridianEdge(Ang);
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Edge(_result);
}

Macad::Occt::Pnt2d Macad::Occt::BRepPrim_Revolution::MeridianValue(double V)
{
    ::gp_Pnt2d _nativeResult = ((::BRepPrim_Revolution*)_NativeInstance)->MeridianValue(V);
    return Macad::Occt::Pnt2d(_nativeResult);
}

void Macad::Occt::BRepPrim_Revolution::SetMeridianPCurve(Macad::Occt::TopoDS_Edge^ E, Macad::Occt::TopoDS_Face^ F)
{
    ((::BRepPrim_Revolution*)_NativeInstance)->SetMeridianPCurve(*(::TopoDS_Edge*)E->NativeInstance, *(::TopoDS_Face*)F->NativeInstance);
}



//---------------------------------------------------------------------
//  Class  BRepPrim_Cone
//---------------------------------------------------------------------

Macad::Occt::BRepPrim_Cone::BRepPrim_Cone(double Angle, Macad::Occt::Ax2 Position, double Height, double Radius)
    : Macad::Occt::BRepPrim_Revolution(BaseClass::InitMode::Uninitialized)
{
    pin_ptr<Macad::Occt::Ax2> pp_Position = &Position;
    _NativeInstance = new ::BRepPrim_Cone(Angle, *(gp_Ax2*)pp_Position, Height, Radius);
}

Macad::Occt::BRepPrim_Cone::BRepPrim_Cone(double Angle, Macad::Occt::Ax2 Position, double Height)
    : Macad::Occt::BRepPrim_Revolution(BaseClass::InitMode::Uninitialized)
{
    pin_ptr<Macad::Occt::Ax2> pp_Position = &Position;
    _NativeInstance = new ::BRepPrim_Cone(Angle, *(gp_Ax2*)pp_Position, Height, 0.0);
}

Macad::Occt::BRepPrim_Cone::BRepPrim_Cone(double Angle)
    : Macad::Occt::BRepPrim_Revolution(BaseClass::InitMode::Uninitialized)
{
    _NativeInstance = new ::BRepPrim_Cone(Angle);
}

Macad::Occt::BRepPrim_Cone::BRepPrim_Cone(double Angle, Macad::Occt::Pnt Apex)
    : Macad::Occt::BRepPrim_Revolution(BaseClass::InitMode::Uninitialized)
{
    pin_ptr<Macad::Occt::Pnt> pp_Apex = &Apex;
    _NativeInstance = new ::BRepPrim_Cone(Angle, *(gp_Pnt*)pp_Apex);
}

Macad::Occt::BRepPrim_Cone::BRepPrim_Cone(double Angle, Macad::Occt::Ax2 Axes)
    : Macad::Occt::BRepPrim_Revolution(BaseClass::InitMode::Uninitialized)
{
    pin_ptr<Macad::Occt::Ax2> pp_Axes = &Axes;
    _NativeInstance = new ::BRepPrim_Cone(Angle, *(gp_Ax2*)pp_Axes);
}

Macad::Occt::BRepPrim_Cone::BRepPrim_Cone(double R1, double R2, double H)
    : Macad::Occt::BRepPrim_Revolution(BaseClass::InitMode::Uninitialized)
{
    _NativeInstance = new ::BRepPrim_Cone(R1, R2, H);
}

Macad::Occt::BRepPrim_Cone::BRepPrim_Cone(Macad::Occt::Pnt Center, double R1, double R2, double H)
    : Macad::Occt::BRepPrim_Revolution(BaseClass::InitMode::Uninitialized)
{
    pin_ptr<Macad::Occt::Pnt> pp_Center = &Center;
    _NativeInstance = new ::BRepPrim_Cone(*(gp_Pnt*)pp_Center, R1, R2, H);
}

Macad::Occt::BRepPrim_Cone::BRepPrim_Cone(Macad::Occt::Ax2 Axes, double R1, double R2, double H)
    : Macad::Occt::BRepPrim_Revolution(BaseClass::InitMode::Uninitialized)
{
    pin_ptr<Macad::Occt::Ax2> pp_Axes = &Axes;
    _NativeInstance = new ::BRepPrim_Cone(*(gp_Ax2*)pp_Axes, R1, R2, H);
}

Macad::Occt::TopoDS_Face^ Macad::Occt::BRepPrim_Cone::MakeEmptyLateralFace()
{
    ::TopoDS_Face* _result = new ::TopoDS_Face();
    *_result = ((::BRepPrim_Cone*)_NativeInstance)->MakeEmptyLateralFace();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Face(_result);
}



//---------------------------------------------------------------------
//  Class  BRepPrim_Cylinder
//---------------------------------------------------------------------

Macad::Occt::BRepPrim_Cylinder::BRepPrim_Cylinder(Macad::Occt::Ax2 Position, double Radius, double Height)
    : Macad::Occt::BRepPrim_Revolution(BaseClass::InitMode::Uninitialized)
{
    pin_ptr<Macad::Occt::Ax2> pp_Position = &Position;
    _NativeInstance = new ::BRepPrim_Cylinder(*(gp_Ax2*)pp_Position, Radius, Height);
}

Macad::Occt::BRepPrim_Cylinder::BRepPrim_Cylinder(double Radius)
    : Macad::Occt::BRepPrim_Revolution(BaseClass::InitMode::Uninitialized)
{
    _NativeInstance = new ::BRepPrim_Cylinder(Radius);
}

Macad::Occt::BRepPrim_Cylinder::BRepPrim_Cylinder(Macad::Occt::Pnt Center, double Radius)
    : Macad::Occt::BRepPrim_Revolution(BaseClass::InitMode::Uninitialized)
{
    pin_ptr<Macad::Occt::Pnt> pp_Center = &Center;
    _NativeInstance = new ::BRepPrim_Cylinder(*(gp_Pnt*)pp_Center, Radius);
}

Macad::Occt::BRepPrim_Cylinder::BRepPrim_Cylinder(Macad::Occt::Ax2 Axes, double Radius)
    : Macad::Occt::BRepPrim_Revolution(BaseClass::InitMode::Uninitialized)
{
    pin_ptr<Macad::Occt::Ax2> pp_Axes = &Axes;
    _NativeInstance = new ::BRepPrim_Cylinder(*(gp_Ax2*)pp_Axes, Radius);
}

Macad::Occt::BRepPrim_Cylinder::BRepPrim_Cylinder(double R, double H)
    : Macad::Occt::BRepPrim_Revolution(BaseClass::InitMode::Uninitialized)
{
    _NativeInstance = new ::BRepPrim_Cylinder(R, H);
}

Macad::Occt::BRepPrim_Cylinder::BRepPrim_Cylinder(Macad::Occt::Pnt Center, double R, double H)
    : Macad::Occt::BRepPrim_Revolution(BaseClass::InitMode::Uninitialized)
{
    pin_ptr<Macad::Occt::Pnt> pp_Center = &Center;
    _NativeInstance = new ::BRepPrim_Cylinder(*(gp_Pnt*)pp_Center, R, H);
}

Macad::Occt::TopoDS_Face^ Macad::Occt::BRepPrim_Cylinder::MakeEmptyLateralFace()
{
    ::TopoDS_Face* _result = new ::TopoDS_Face();
    *_result = ((::BRepPrim_Cylinder*)_NativeInstance)->MakeEmptyLateralFace();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Face(_result);
}



//---------------------------------------------------------------------
//  Class  BRepPrim_FaceBuilder
//---------------------------------------------------------------------

Macad::Occt::BRepPrim_FaceBuilder::BRepPrim_FaceBuilder()
    : Macad::Occt::BaseClass<::BRepPrim_FaceBuilder>(BaseClass::InitMode::Uninitialized)
{
    _NativeInstance = new ::BRepPrim_FaceBuilder();
}

Macad::Occt::BRepPrim_FaceBuilder::BRepPrim_FaceBuilder(Macad::Occt::BRep_Builder^ B, Macad::Occt::Geom_Surface^ S)
    : Macad::Occt::BaseClass<::BRepPrim_FaceBuilder>(BaseClass::InitMode::Uninitialized)
{
    _NativeInstance = new ::BRepPrim_FaceBuilder(*(::BRep_Builder*)B->NativeInstance, Handle(::Geom_Surface)(S->NativeInstance));
}

Macad::Occt::BRepPrim_FaceBuilder::BRepPrim_FaceBuilder(Macad::Occt::BRep_Builder^ B, Macad::Occt::Geom_Surface^ S, double UMin, double UMax, double VMin, double VMax)
    : Macad::Occt::BaseClass<::BRepPrim_FaceBuilder>(BaseClass::InitMode::Uninitialized)
{
    _NativeInstance = new ::BRepPrim_FaceBuilder(*(::BRep_Builder*)B->NativeInstance, Handle(::Geom_Surface)(S->NativeInstance), UMin, UMax, VMin, VMax);
}

void Macad::Occt::BRepPrim_FaceBuilder::Init(Macad::Occt::BRep_Builder^ B, Macad::Occt::Geom_Surface^ S)
{
    ((::BRepPrim_FaceBuilder*)_NativeInstance)->Init(*(::BRep_Builder*)B->NativeInstance, Handle(::Geom_Surface)(S->NativeInstance));
}

void Macad::Occt::BRepPrim_FaceBuilder::Init(Macad::Occt::BRep_Builder^ B, Macad::Occt::Geom_Surface^ S, double UMin, double UMax, double VMin, double VMax)
{
    ((::BRepPrim_FaceBuilder*)_NativeInstance)->Init(*(::BRep_Builder*)B->NativeInstance, Handle(::Geom_Surface)(S->NativeInstance), UMin, UMax, VMin, VMax);
}

Macad::Occt::TopoDS_Face^ Macad::Occt::BRepPrim_FaceBuilder::Face()
{
    ::TopoDS_Face* _result = new ::TopoDS_Face();
    *_result = (::TopoDS_Face)((::BRepPrim_FaceBuilder*)_NativeInstance)->Face();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Face(_result);
}

Macad::Occt::TopoDS_Edge^ Macad::Occt::BRepPrim_FaceBuilder::Edge(int I)
{
    ::TopoDS_Edge* _result = new ::TopoDS_Edge();
    *_result = (::TopoDS_Edge)((::BRepPrim_FaceBuilder*)_NativeInstance)->Edge(I);
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Edge(_result);
}

Macad::Occt::TopoDS_Vertex^ Macad::Occt::BRepPrim_FaceBuilder::Vertex(int I)
{
    ::TopoDS_Vertex* _result = new ::TopoDS_Vertex();
    *_result = (::TopoDS_Vertex)((::BRepPrim_FaceBuilder*)_NativeInstance)->Vertex(I);
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Vertex(_result);
}



//---------------------------------------------------------------------
//  Class  BRepPrim_GWedge
//---------------------------------------------------------------------

Macad::Occt::BRepPrim_GWedge::BRepPrim_GWedge()
    : Macad::Occt::BaseClass<::BRepPrim_GWedge>(BaseClass::InitMode::Uninitialized)
{
    _NativeInstance = new ::BRepPrim_GWedge();
}

Macad::Occt::BRepPrim_GWedge::BRepPrim_GWedge(Macad::Occt::BRepPrim_Builder^ B, Macad::Occt::Ax2 Axes, double dx, double dy, double dz)
    : Macad::Occt::BaseClass<::BRepPrim_GWedge>(BaseClass::InitMode::Uninitialized)
{
    pin_ptr<Macad::Occt::Ax2> pp_Axes = &Axes;
    _NativeInstance = new ::BRepPrim_GWedge(*(::BRepPrim_Builder*)B->NativeInstance, *(gp_Ax2*)pp_Axes, dx, dy, dz);
}

Macad::Occt::BRepPrim_GWedge::BRepPrim_GWedge(Macad::Occt::BRepPrim_Builder^ B, Macad::Occt::Ax2 Axes, double dx, double dy, double dz, double ltx)
    : Macad::Occt::BaseClass<::BRepPrim_GWedge>(BaseClass::InitMode::Uninitialized)
{
    pin_ptr<Macad::Occt::Ax2> pp_Axes = &Axes;
    _NativeInstance = new ::BRepPrim_GWedge(*(::BRepPrim_Builder*)B->NativeInstance, *(gp_Ax2*)pp_Axes, dx, dy, dz, ltx);
}

Macad::Occt::BRepPrim_GWedge::BRepPrim_GWedge(Macad::Occt::BRepPrim_Builder^ B, Macad::Occt::Ax2 Axes, double xmin, double ymin, double zmin, double z2min, double x2min, double xmax, double ymax, double zmax, double z2max, double x2max)
    : Macad::Occt::BaseClass<::BRepPrim_GWedge>(BaseClass::InitMode::Uninitialized)
{
    pin_ptr<Macad::Occt::Ax2> pp_Axes = &Axes;
    _NativeInstance = new ::BRepPrim_GWedge(*(::BRepPrim_Builder*)B->NativeInstance, *(gp_Ax2*)pp_Axes, xmin, ymin, zmin, z2min, x2min, xmax, ymax, zmax, z2max, x2max);
}

Macad::Occt::Ax2 Macad::Occt::BRepPrim_GWedge::Axes()
{
    ::gp_Ax2 _nativeResult = ((::BRepPrim_GWedge*)_NativeInstance)->Axes();
    return Macad::Occt::Ax2(_nativeResult);
}

double Macad::Occt::BRepPrim_GWedge::GetXMin()
{
    double _result = ((::BRepPrim_GWedge*)_NativeInstance)->GetXMin();
    return _result;
}

double Macad::Occt::BRepPrim_GWedge::GetYMin()
{
    double _result = ((::BRepPrim_GWedge*)_NativeInstance)->GetYMin();
    return _result;
}

double Macad::Occt::BRepPrim_GWedge::GetZMin()
{
    double _result = ((::BRepPrim_GWedge*)_NativeInstance)->GetZMin();
    return _result;
}

double Macad::Occt::BRepPrim_GWedge::GetZ2Min()
{
    double _result = ((::BRepPrim_GWedge*)_NativeInstance)->GetZ2Min();
    return _result;
}

double Macad::Occt::BRepPrim_GWedge::GetX2Min()
{
    double _result = ((::BRepPrim_GWedge*)_NativeInstance)->GetX2Min();
    return _result;
}

double Macad::Occt::BRepPrim_GWedge::GetXMax()
{
    double _result = ((::BRepPrim_GWedge*)_NativeInstance)->GetXMax();
    return _result;
}

double Macad::Occt::BRepPrim_GWedge::GetYMax()
{
    double _result = ((::BRepPrim_GWedge*)_NativeInstance)->GetYMax();
    return _result;
}

double Macad::Occt::BRepPrim_GWedge::GetZMax()
{
    double _result = ((::BRepPrim_GWedge*)_NativeInstance)->GetZMax();
    return _result;
}

double Macad::Occt::BRepPrim_GWedge::GetZ2Max()
{
    double _result = ((::BRepPrim_GWedge*)_NativeInstance)->GetZ2Max();
    return _result;
}

double Macad::Occt::BRepPrim_GWedge::GetX2Max()
{
    double _result = ((::BRepPrim_GWedge*)_NativeInstance)->GetX2Max();
    return _result;
}

void Macad::Occt::BRepPrim_GWedge::Open(Macad::Occt::BRepPrim_Direction d1)
{
    ((::BRepPrim_GWedge*)_NativeInstance)->Open((::BRepPrim_Direction)d1);
}

void Macad::Occt::BRepPrim_GWedge::Close(Macad::Occt::BRepPrim_Direction d1)
{
    ((::BRepPrim_GWedge*)_NativeInstance)->Close((::BRepPrim_Direction)d1);
}

bool Macad::Occt::BRepPrim_GWedge::IsInfinite(Macad::Occt::BRepPrim_Direction d1)
{
    bool _result = ((::BRepPrim_GWedge*)_NativeInstance)->IsInfinite((::BRepPrim_Direction)d1);
    return _result;
}

Macad::Occt::TopoDS_Shell^ Macad::Occt::BRepPrim_GWedge::Shell()
{
    ::TopoDS_Shell* _result = new ::TopoDS_Shell();
    *_result = (::TopoDS_Shell)((::BRepPrim_GWedge*)_NativeInstance)->Shell();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Shell(_result);
}

bool Macad::Occt::BRepPrim_GWedge::HasFace(Macad::Occt::BRepPrim_Direction d1)
{
    bool _result = ((::BRepPrim_GWedge*)_NativeInstance)->HasFace((::BRepPrim_Direction)d1);
    return _result;
}

Macad::Occt::TopoDS_Face^ Macad::Occt::BRepPrim_GWedge::Face(Macad::Occt::BRepPrim_Direction d1)
{
    ::TopoDS_Face* _result = new ::TopoDS_Face();
    *_result = (::TopoDS_Face)((::BRepPrim_GWedge*)_NativeInstance)->Face((::BRepPrim_Direction)d1);
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Face(_result);
}

Macad::Occt::Pln Macad::Occt::BRepPrim_GWedge::Plane(Macad::Occt::BRepPrim_Direction d1)
{
    ::gp_Pln _nativeResult = ((::BRepPrim_GWedge*)_NativeInstance)->Plane((::BRepPrim_Direction)d1);
    return Macad::Occt::Pln(_nativeResult);
}

bool Macad::Occt::BRepPrim_GWedge::HasWire(Macad::Occt::BRepPrim_Direction d1)
{
    bool _result = ((::BRepPrim_GWedge*)_NativeInstance)->HasWire((::BRepPrim_Direction)d1);
    return _result;
}

Macad::Occt::TopoDS_Wire^ Macad::Occt::BRepPrim_GWedge::Wire(Macad::Occt::BRepPrim_Direction d1)
{
    ::TopoDS_Wire* _result = new ::TopoDS_Wire();
    *_result = (::TopoDS_Wire)((::BRepPrim_GWedge*)_NativeInstance)->Wire((::BRepPrim_Direction)d1);
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Wire(_result);
}

bool Macad::Occt::BRepPrim_GWedge::HasEdge(Macad::Occt::BRepPrim_Direction d1, Macad::Occt::BRepPrim_Direction d2)
{
    bool _result = ((::BRepPrim_GWedge*)_NativeInstance)->HasEdge((::BRepPrim_Direction)d1, (::BRepPrim_Direction)d2);
    return _result;
}

Macad::Occt::TopoDS_Edge^ Macad::Occt::BRepPrim_GWedge::Edge(Macad::Occt::BRepPrim_Direction d1, Macad::Occt::BRepPrim_Direction d2)
{
    ::TopoDS_Edge* _result = new ::TopoDS_Edge();
    *_result = (::TopoDS_Edge)((::BRepPrim_GWedge*)_NativeInstance)->Edge((::BRepPrim_Direction)d1, (::BRepPrim_Direction)d2);
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Edge(_result);
}

Macad::Occt::gp_Lin^ Macad::Occt::BRepPrim_GWedge::Line(Macad::Occt::BRepPrim_Direction d1, Macad::Occt::BRepPrim_Direction d2)
{
    ::gp_Lin* _result = new ::gp_Lin();
    *_result = ((::BRepPrim_GWedge*)_NativeInstance)->Line((::BRepPrim_Direction)d1, (::BRepPrim_Direction)d2);
    return _result==nullptr ? nullptr : gcnew Macad::Occt::gp_Lin(_result);
}

bool Macad::Occt::BRepPrim_GWedge::HasVertex(Macad::Occt::BRepPrim_Direction d1, Macad::Occt::BRepPrim_Direction d2, Macad::Occt::BRepPrim_Direction d3)
{
    bool _result = ((::BRepPrim_GWedge*)_NativeInstance)->HasVertex((::BRepPrim_Direction)d1, (::BRepPrim_Direction)d2, (::BRepPrim_Direction)d3);
    return _result;
}

Macad::Occt::TopoDS_Vertex^ Macad::Occt::BRepPrim_GWedge::Vertex(Macad::Occt::BRepPrim_Direction d1, Macad::Occt::BRepPrim_Direction d2, Macad::Occt::BRepPrim_Direction d3)
{
    ::TopoDS_Vertex* _result = new ::TopoDS_Vertex();
    *_result = (::TopoDS_Vertex)((::BRepPrim_GWedge*)_NativeInstance)->Vertex((::BRepPrim_Direction)d1, (::BRepPrim_Direction)d2, (::BRepPrim_Direction)d3);
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Vertex(_result);
}

Macad::Occt::Pnt Macad::Occt::BRepPrim_GWedge::Point(Macad::Occt::BRepPrim_Direction d1, Macad::Occt::BRepPrim_Direction d2, Macad::Occt::BRepPrim_Direction d3)
{
    ::gp_Pnt _nativeResult = ((::BRepPrim_GWedge*)_NativeInstance)->Point((::BRepPrim_Direction)d1, (::BRepPrim_Direction)d2, (::BRepPrim_Direction)d3);
    return Macad::Occt::Pnt(_nativeResult);
}

bool Macad::Occt::BRepPrim_GWedge::IsDegeneratedShape()
{
    bool _result = ((::BRepPrim_GWedge*)_NativeInstance)->IsDegeneratedShape();
    return _result;
}



//---------------------------------------------------------------------
//  Class  BRepPrim_Sphere
//---------------------------------------------------------------------

Macad::Occt::BRepPrim_Sphere::BRepPrim_Sphere(double Radius)
    : Macad::Occt::BRepPrim_Revolution(BaseClass::InitMode::Uninitialized)
{
    _NativeInstance = new ::BRepPrim_Sphere(Radius);
}

Macad::Occt::BRepPrim_Sphere::BRepPrim_Sphere(Macad::Occt::Pnt Center, double Radius)
    : Macad::Occt::BRepPrim_Revolution(BaseClass::InitMode::Uninitialized)
{
    pin_ptr<Macad::Occt::Pnt> pp_Center = &Center;
    _NativeInstance = new ::BRepPrim_Sphere(*(gp_Pnt*)pp_Center, Radius);
}

Macad::Occt::BRepPrim_Sphere::BRepPrim_Sphere(Macad::Occt::Ax2 Axes, double Radius)
    : Macad::Occt::BRepPrim_Revolution(BaseClass::InitMode::Uninitialized)
{
    pin_ptr<Macad::Occt::Ax2> pp_Axes = &Axes;
    _NativeInstance = new ::BRepPrim_Sphere(*(gp_Ax2*)pp_Axes, Radius);
}

Macad::Occt::TopoDS_Face^ Macad::Occt::BRepPrim_Sphere::MakeEmptyLateralFace()
{
    ::TopoDS_Face* _result = new ::TopoDS_Face();
    *_result = ((::BRepPrim_Sphere*)_NativeInstance)->MakeEmptyLateralFace();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Face(_result);
}



//---------------------------------------------------------------------
//  Class  BRepPrim_Torus
//---------------------------------------------------------------------

Macad::Occt::BRepPrim_Torus::BRepPrim_Torus(Macad::Occt::Ax2 Position, double Major, double Minor)
    : Macad::Occt::BRepPrim_Revolution(BaseClass::InitMode::Uninitialized)
{
    pin_ptr<Macad::Occt::Ax2> pp_Position = &Position;
    _NativeInstance = new ::BRepPrim_Torus(*(gp_Ax2*)pp_Position, Major, Minor);
}

Macad::Occt::BRepPrim_Torus::BRepPrim_Torus(double Major, double Minor)
    : Macad::Occt::BRepPrim_Revolution(BaseClass::InitMode::Uninitialized)
{
    _NativeInstance = new ::BRepPrim_Torus(Major, Minor);
}

Macad::Occt::BRepPrim_Torus::BRepPrim_Torus(Macad::Occt::Pnt Center, double Major, double Minor)
    : Macad::Occt::BRepPrim_Revolution(BaseClass::InitMode::Uninitialized)
{
    pin_ptr<Macad::Occt::Pnt> pp_Center = &Center;
    _NativeInstance = new ::BRepPrim_Torus(*(gp_Pnt*)pp_Center, Major, Minor);
}

Macad::Occt::TopoDS_Face^ Macad::Occt::BRepPrim_Torus::MakeEmptyLateralFace()
{
    ::TopoDS_Face* _result = new ::TopoDS_Face();
    *_result = ((::BRepPrim_Torus*)_NativeInstance)->MakeEmptyLateralFace();
    return _result==nullptr ? nullptr : gcnew Macad::Occt::TopoDS_Face(_result);
}



//---------------------------------------------------------------------
//  Class  BRepPrim_Wedge
//---------------------------------------------------------------------

Macad::Occt::BRepPrim_Wedge::BRepPrim_Wedge()
    : Macad::Occt::BRepPrim_GWedge(BaseClass::InitMode::Uninitialized)
{
    _NativeInstance = new ::BRepPrim_Wedge();
}

Macad::Occt::BRepPrim_Wedge::BRepPrim_Wedge(Macad::Occt::Ax2 Axes, double dx, double dy, double dz)
    : Macad::Occt::BRepPrim_GWedge(BaseClass::InitMode::Uninitialized)
{
    pin_ptr<Macad::Occt::Ax2> pp_Axes = &Axes;
    _NativeInstance = new ::BRepPrim_Wedge(*(gp_Ax2*)pp_Axes, dx, dy, dz);
}

Macad::Occt::BRepPrim_Wedge::BRepPrim_Wedge(Macad::Occt::Ax2 Axes, double dx, double dy, double dz, double ltx)
    : Macad::Occt::BRepPrim_GWedge(BaseClass::InitMode::Uninitialized)
{
    pin_ptr<Macad::Occt::Ax2> pp_Axes = &Axes;
    _NativeInstance = new ::BRepPrim_Wedge(*(gp_Ax2*)pp_Axes, dx, dy, dz, ltx);
}

Macad::Occt::BRepPrim_Wedge::BRepPrim_Wedge(Macad::Occt::Ax2 Axes, double xmin, double ymin, double zmin, double z2min, double x2min, double xmax, double ymax, double zmax, double z2max, double x2max)
    : Macad::Occt::BRepPrim_GWedge(BaseClass::InitMode::Uninitialized)
{
    pin_ptr<Macad::Occt::Ax2> pp_Axes = &Axes;
    _NativeInstance = new ::BRepPrim_Wedge(*(gp_Ax2*)pp_Axes, xmin, ymin, zmin, z2min, x2min, xmax, ymax, zmax, z2max, x2max);
}


