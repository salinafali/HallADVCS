#ifndef DVCS_RUN_ACTION
#define DVCS_RUN_ACTION 1

#include "G4UserRunAction.hh"
#include "globals.hh"
#include "dvcsHist_Manager.hh"

class G4Run;

class dvcsRunAction : public G4UserRunAction
{
public:
  dvcsRunAction( dvcsHistManager *);
  ~dvcsRunAction();
  
public:
  void BeginOfRunAction(const G4Run*);
  void EndOfRunAction(const G4Run*);

private:
  dvcsHistManager *hist_man;
};

#endif
