/************************************************************************
 * @file main.cc
 * @author kate
 * @brief entry point for CPP 20 examples
 * @version 1.0
 * @date 2023-11-19
 * *********************************************************************/

#include <declarations/example1.hh>

int main(int, char**) {
    using namespace examples;

    auto example{ declarations::example1() };
    example.run();
    return 0;
}