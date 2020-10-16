#include <iostream>
#include <vector>
#include <array>
#include "DPState.h"

class ModuleTest
{
private:
    /* data */
public:
    int x_;
    int y_;
    State *state_;

    void init(std::vector<std::array<int,2>> goal);

    ModuleTest(int x, int y);
    ~ModuleTest();
};

ModuleTest::ModuleTest(int x, int y)
{
    x_ = x;
    y_ = y;
    state_ = new StNotSet();
}

ModuleTest::~ModuleTest()
{
}

void ModuleTest::init(std::vector<std::array<int,2>> goal){
    if(state_->HasConverged(x_, y_, goal)){
        
    }
}