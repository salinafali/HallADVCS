#ifndef DVCS_PRIMARY_GENERATOR_ACTION
#define DVCS_PRIMARY_GENERATOR_ACTION

#include <TRandom.h>
#include <TVector3.h>
#include "TLorentzVector.h"
#include "TGenBase.h"
#include "TGenGeo.h"
#include "TGenDVCS.h"
#include "TObject.h"


#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"
//#include "G4ThreeVector.hh"

class dvcsEventAction;
class G4ParticleGun;
class dvcsEventAction;
class G4Event;

class dvcsPrimaryGeneratorAction: public G4VUserPrimaryGeneratorAction
{
public:
  dvcsPrimaryGeneratorAction( dvcsEventAction *, G4int , G4int );
  ~dvcsPrimaryGeneratorAction();
  
  void GeneratePrimaries(G4Event *anEvent);
  
private:
  G4ParticleGun *particleGun;
  TGenDVCS *gEv;

  TVector3 *vert_pos;
  TLorentzVector *L_em_init;
  TLorentzVector *L_em_scat;
  TLorentzVector *L_em_scat_v;
  TLorentzVector *L_final_phot;
  TLorentzVector *L_final_prot;

  dvcsEventAction *ev_act;

  int ev_numb;

  int test_count1;
  int test_count2;
};

#endif
