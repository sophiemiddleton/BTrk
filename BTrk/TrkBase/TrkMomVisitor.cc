//--------------------------------------------------------------------------
// File and Version Information:
//
// Description:
//
//
// Environment:
//      Software developed for the BaBar Detector at the SLAC B-Factory.
//
// Author(s): Justin Albert, Steve Schaffner, added Cosmics S. Middleton (2020)
//
//------------------------------------------------------------------------
#include "BTrk/BaBar/BaBar.hh"
#include "BTrk/TrkBase/TrkMomVisitor.hh"
#include "BTrk/TrkBase/TrkSimpTraj.hh"


//------------------------------------------------------------------------
TrkMomVisitor::~TrkMomVisitor() {
//------------------------------------------------------------------------
}

//------------------------------------------------------------------------
TrkMomVisitor::TrkMomVisitor(const TrkSimpTraj& theTraj) {
//------------------------------------------------------------------------
	theTraj.visitAccept(this);
}

//------------------------------------------------------------------------
void
TrkMomVisitor::trkVisitHelixTraj(const HelixTraj* theTraj) {
//------------------------------------------------------------------------
// set the "array"

  _ht = theTraj;
  _ct = 0;
  _nt = 0;
  _cos = 0;
}

//------------------------------------------------------------------------
void
TrkMomVisitor::trkVisitCircleTraj(const TrkCircleTraj* theTraj) {
//------------------------------------------------------------------------
// set the "array"

  _ht = 0;
  _ct = theTraj;
  _nt = 0;
  _cos =0;
}

//------------------------------------------------------------------------
void
TrkMomVisitor::trkVisitNeutTraj(const NeutTraj* theTraj) {
//------------------------------------------------------------------------
// set the "array"

  _ht = 0;
  _ct = 0;
  _nt = theTraj;
  _cos = 0;
}

//------------------------------------------------------------------------
void
TrkMomVisitor::trkVisitCosmicLineTraj(const CosmicLineTraj* theTraj) {
//------------------------------------------------------------------------
// set the "array"

  _ht = 0;
  _ct = 0;
  _nt = 0;
  _cos = theTraj;
}

