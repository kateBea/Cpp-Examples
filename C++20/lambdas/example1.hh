/************************************************************************
 * @file main.cc
 * @author kate
 * @brief simple usage of lambda templates to print a range of elements
 * @version 1.0
 * @date 2023-11-19
 * *********************************************************************/

#if !defined(CPP_EXAMPLES_CPP20_LAMBDAS_EXAMPL1)
#define CPP_EXAMPLES_CPP20_LAMBDAS_EXAMPL1

#include <algorithm>
#include <iostream>
#include <vector>

#include <common/runnable.hh>

namespace examples::lambdas {
    class example1 : public runnable {
    public:
        auto run() -> void override {
            auto display{
                []<typename ForwardIt>( ForwardIt first, ForwardIt last ) {
                    for ( ; first != last; ++first )
                        std::cout << *first << std::endl;
                }
            };

            std::vector elements{ 6, 1, 22, 2, 3, -44, 15, -4, -1, 4, 5, 7, -11, 9, 10, 11 };
            sort( elements.begin(), elements.end(), std::greater<int>{} ); // ADL
            display( elements.begin(), elements.end() );
        }
    };
}

#endif