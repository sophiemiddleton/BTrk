//--------------------------------------------------------------------------
// File and Version Information:
//
// Description:  TrkMomVisitor is an implementation of the Visitor pattern
//      for use in calculating momenta for different types of
//      trajectories.  (See the book _Design Patterns_ or one of the
//      authors for a definition of the Visitor pattern.) 
//
// Environment:
//      Software developed for the BaBar Detector at the SLAC B-Factory.
//
// Author(s): Justin Albert, Steve Schaffner
//
//------------------------------------------------------------------------
#ifndef TrkMomVisitor_HH
#define TrkMomVisitor_HH

#include "BTrk/TrkBase/TrkVisitor.hh"
#include "BTrk/TrkBase/CosmicLineTraj.hh"

class TrkSimpTraj;
class HelixTraj;
class TrkCircleTraj;
class NeutTraj;
class CosmicLineTraj;

// Class interface //
class TrkMomVisitor : public CosmicTrkVisitor {

public:

  TrkMomVisitor(const TrkSimpTraj&);

  virtual ~TrkMomVisitor();

  // ******************
  // data member access
  // ******************

  const HelixTraj*       helix() const      {return _ht;}
  const TrkCircleTraj*   circle() const     {return _ct;}
  const NeutTraj*        neut() const       {return _nt;}   
  const CosmicLineTraj*  cosmic() const     {return _cos;}   

  //********************************
  // The visitor functions:
  //********************************

  virtual void trkVisitHelixTraj(const HelixTraj*);
  virtual void trkVisitCircleTraj(const TrkCircleTraj*);
  virtual void trkVisitNeutTraj(const NeutTraj*);
  virtual void trkVisitCosmicLineTraj(const CosmicLineTraj*);

private:

  const HelixTraj*      _ht;
  const TrkCircleTraj*  _ct;
  const NeutTraj*       _nt;
  const CosmicLineTraj*  _cos;

};

#endif
