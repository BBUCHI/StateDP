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
    Context *context_;

    void init(std::vector<std::array<int,2>> goal);

    ModuleTest(int x, int y);
    ~ModuleTest();
};

ModuleTest::ModuleTest(int x, int y)
{
    x_ = x;
    y_ = y;
    context_ = new Context();
}

ModuleTest::~ModuleTest()
{
}