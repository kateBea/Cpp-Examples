/************************************************************************
 * @file main.cc
 * @author kate
 * @brief entry point for CPP 20 examples
 * @version 1.0
 * @date 2023-11-19
 * *********************************************************************/

#include <lambdas/example1.hh>
#include <lambdas/example2.hh>

int main(int, char**) {
    using namespace examples;

    auto example{ lambdas::example2() };
    example.run();
    
    return 0;
}