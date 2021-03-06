#ifndef DVCS_HISTO_MANAGER
#define DVCS_HISTO_MANAGER 1

#include <TFile.h>
#include <TTree.h>
#include "/work/halla/dvcs/disk1/salina/soft-2/TCaloEvent.h"
#include <dvcsObj_Manager.hh>

class dvcsHistManager
{
public:
  dvcsHistManager( ObjManager* );
  
  void Book();
  void Fill_Ntuple();
  void Save();
  
  void SetCaloData(double , double , double , double , double , double , int , int); //ene1, ene2, xc1, sc2, yc1, yc2, size1, size2
  void SetBeamGen(double, double, double); // kx_v, ky_v, kz_v
  void SetBeamRec(double, double, double); // kx, ky, kz
  void SetScatemGen(double, double, double); // kpx_v, kpy_v, kpz_v
  void SetScatemRec(double, double, double); // kpx, kpy, kpz
  void SetPhotGen(double, double, double, double, double, double); // kq1x_v, kq1y_v, kq1z_v, kq2x_v, kq2y_v, kq2z_v
  void SetPhotRec(double , double , double , double , double , double); // kq1x, kq2x, kq1y, kq2y, kq1z, kq2z
  void SetkineGen(double, double, double, double, double); // t, xB, Q2, phi(rad),tmin
  void SetkineRec(double , double, double, double, double); // t, xB, Q2, phi(rad),tmin
  void SetMM2( double ); // MM2
  void SetMinv( double ); // Inv mass of two photons
  void SetVertexes(double, double ); // vertex , smeared vertex
  void SetWeights(double, double, double); // PSF, crs_sum, crs_dif
  void SetRvalGen(double); // Generated R value
  void SetRvalRec(double); // Reconstructed R value
  
private:
  
  TFile *file_out;
  TTree *tr1;
  TCaloEvent *calo_ev;
  
  double m;
  double ene1; // energy of "first"  cluster in Calo
  double ene2; // energy of "second" cluster in Calo
  double xc1; // x coordinate of "first"cluster in Calo
  double xc2; // x coordinate of "second" cluster in Calo
  double yc1; // y coordinate of "first" cluster in Calo
  double yc2; // y coordinate of "second" cluster in Calo
  double mm2; //missing mass squared
  int size1; // number of blocks in "first" cluster
  int size2; // number of blocks in "second" cluster
  double psf; // Phase Spase Factor
  double kx; // x component of beam electron's momentum
  double ky; // y component of beam electron's momentum
  double kz; // z component of beam electron's momentum
  double kx_v; // x component of reconstructed beam electron's momentum
  double ky_v; // y component of reconstructed beam electron's momentum
  double kz_v; // z component of reconstructed beam electron's momentum
  double kpx; // x component of scattered electron's momentum at HRS window
  double kpy; // y component of scattered electron's momentum at HRS window
  double kpz; // z component of scattered electron's momentum at HRS window
  double kpx_v; // x component of scattered electron's momentum at interaction vertex
  double kpy_v; // y component of scattered electron's momentum at interaction vertex
  double kpz_v; // z component of scattered electron's momentum at interaction vertex
  double q1x; // x component of the 1-st photon's momentum from calo
  double q2x; // x component of the 2-nd photon's momentum from calo
  double q1y; // y component of the 1-st  photon's momentum from calo
  double q2y; // y component of the 2-nd  photon's momentum from calo
  double q1z; // z component of the 1-st  photon's momentum from calo
  double q2z; // z component of the 2-nd  photon's momentum from calo
  double q1x_v; // x component of "first" photon's momentum at interaction vertex (from generatot)
  double q2x_v; // x component of "second" photon's momentum at interaction vertex (from generatot)
  double q1y_v; // y component of "first" photon's momentum at interaction vertex (from generatot)
  double q2y_v; // y component of "second" photon's momentum at interaction vertex (from generatot)
  double q1z_v; // z component of "first" photon's momentum at interaction vertex (from generatot)
  double q2z_v; // z component of "second" photon's momentum at interaction vertex (from generatot)
  double v; // z component of interaction coordinate This is smeareed from the vz_v(generated value) by sigma = 1.2(mm)/sin(theta_HRS)
  double v_v; // z component of interaction coordinate taken from generetor
  double t; // t calculated using angles of reconstructed particles
  double tmin;//tmin calculated using angles of reconstructed particles
  double t_v; // t calculated using information of generated particles
  double tmin_v; // tmin calculated using information of generated particles 
  double xB; // xB calculated using information of reconstructed particles
  double xB_v; // xB calculated using information of generated particles
  double q2; // Q2 calculated from reconstructed electron't kinematics
  double q2_v; // Q2 calculated at interaction vertex
  double phi; // phi calculated using reconstructed particles
  double phi_v; // phi calculated at interaction vertex
  double crs_sum; // Sigma plus + Sigma minus
  double crs_dif; // Sigma plus - Sigma minus
  double rval; // r_value of HRS acceptance
  double rval_v; // r_value of HRS acceptance at production vertex
};

#endif
