//Author: S Middleton
//Date: Nov 2019
//Purpose: To allow cosmic fitting to be compatible with Kalman/BTrk

#ifndef COSMICLINETRAJ_HH
#define COSMICLINETRAJ_HH

#include "BTrk/TrkBase/TrkDifTraj.hh"
#include "BTrk/TrkBase/TrkKalDeriv.hh"
#include "BTrk/TrkBase/TrkParams.hh"
#include "BTrk/BbrGeom/HepPoint.h"
#include "BTrk/TrkBase/CosmicLineParams.hh" 
#include "BTrk/TrkBase/TrkVisitor.hh"
#include <vector>

class TrkVisitor;
#include "CLHEP/Matrix/Vector.h"
#include "CLHEP/Matrix/SymMatrix.h"
#include <iosfwd>

#include "BTrk/TrkBase/TrkSimpTraj.hh"
class CosmicLineParams;

class CosmicLineTraj : public TrkSimpTraj {
public:

  enum ParIndex {d0Index=0, phi0Index, thetaIndex, z0Index,  NHLXPRM};

  CosmicLineTraj(const CLHEP::HepVector&,const CLHEP::HepSymMatrix&, double lowlim=-99999.,
	    double hilim=99999., const HepPoint& refpoint = _theOrigin);
  CosmicLineTraj(const CosmicLineParams&, double lowlim=-99999.,
	    double hilim=99999., const HepPoint& refpoint = _theOrigin);
  CosmicLineTraj(const TrkParams&, double lowlim=-99999.,
	    double hilim=99999., const HepPoint& refpoint = _theOrigin);
  CosmicLineTraj( const CosmicLineTraj&  );  
  CosmicLineTraj* clone() const;

  virtual ~CosmicLineTraj();

  CosmicLineTraj& operator=(const CosmicLineTraj&);
  virtual HepPoint   position(double fltLen)  const;
  virtual CLHEP::Hep3Vector direction(double fltLen) const;
  virtual CLHEP::Hep3Vector delDirect(double)        const;
  virtual void       getInfo(double fltLen, HepPoint& pos, 
			     CLHEP::Hep3Vector& dir) const;
  virtual void       getInfo(double fltLen, HepPoint& , CLHEP::Hep3Vector& dir, 
			     CLHEP::Hep3Vector& delDir) const;
  virtual void       getDFInfo(double fltLen, DifPoint& , DifVector& dir, 
			       DifVector& delDir) const;
  virtual void       getDFInfo2(double fltLen, DifPoint& pos, DifVector& 
			       dir) const;

  virtual double distTo1stError(double s, double tol, int pathDir) const;
  virtual double distTo2ndError(double s, double tol, int pathDir) const;

  double curvature( double fltLen) const;

  CLHEP::HepMatrix derivDeflect(double fltlen,deflectDirection idir) const;
  CLHEP::HepMatrix derivDisplace(double fltlen,deflectDirection idir) const;
  CLHEP::HepMatrix derivPFract(double fltlen) const;

  double d0() const {return parameters()->parameter()[d0Index];}
  double phi0() const{  return parameters()->parameter()[phi0Index]; }
  double theta() const {return parameters()->parameter()[thetaIndex]; }
  double z0() const {  return parameters()->parameter()[z0Index]; }
 
  virtual void visitAccept(TrkVisitor* vis) const;
  virtual void               print(std::ostream& os) const;
  virtual void 		     printAll(std::ostream& os) const;

  double z( const double& ) const;
  double zFlight(double zpos, double POCAz) const;
  double angle(const double& f) const;
  double mom() const{return _mommentum;};
  void set_mom(double p){ _mommentum = p;}

  TranslateParams paramFunction()const {return CosmicLineTraj::paramFunc;}
  void invertParams(TrkParams* newparams, std::vector<bool>& flags) const; 
  private:
	double _mommentum;
	// the real point translation function
  static void paramFunc(const HepPoint& oldpoint,const HepPoint& newpoint,
                        const CLHEP::HepVector& oldpar,const CLHEP::HepSymMatrix& oldcov,
                        CLHEP::HepVector& newpar,CLHEP::HepSymMatrix& newcov,
			double fltlen);

};
#endif
