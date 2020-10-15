
#include <iostream> 
#include <vector> 
#include <array> 
#include "ModuleTest.h"

using namespace std;

int main() {
  vector<array<int,2>> goal;
  goal.push_back({1,0});
  goal.push_back({2,0});
  goal.push_back({2,1});
  ModuleTest *m1 = new ModuleTest(0,0);
  ModuleTest *m2 = new ModuleTest(0,1);
  ModuleTest *m3 = new ModuleTest(1,1);
  CodeTest();
  return 0;
}