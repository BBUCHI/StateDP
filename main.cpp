#include <iostream> 
#include <vector> 
#include <array> 
#include "ModuleTest.h"
//#include "DPState.h"

using namespace std;

int main() {
  //Forme initiale
  vector<array<int,2>> init;
  init.push_back({0,0});
  init.push_back({0,1});
  init.push_back({1,1});

  //Forme objectif
  vector<array<int,2>> goal;
  goal.push_back({1,0});
  goal.push_back({2,0});
  goal.push_back({2,1});

  //Les modules (automatiser depuis FI)
  ModuleTest *m1 = new ModuleTest(0,0);
  ModuleTest *m2 = new ModuleTest(0,1);
  ModuleTest *m3 = new ModuleTest(1,1);

  m1->context_->Request();
  m1->context_->Request();
  m1->context_->Request();
  cout << "FIN.";
  return 0;
}

//virtual bool ClearanceTrans(State *state){return false;};
//virtual bool RunTrans(State *state){return false;};