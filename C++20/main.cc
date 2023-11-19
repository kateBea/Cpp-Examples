/************************************************************************
 * @file main.cc
 * @author kate
 * @brief entry point for CPP 20 examples
 * @version 1.0
 * @date 2023-11-19
 * 
 * @copyright Copyright (c) 2023
 * *********************************************************************/

#include <templated_lambda/example1.hh>

int main(int, char**) {
    using namespace examples;

    auto example{ templated_lambda::example1() };
    example.run();
    
    return 0;
}