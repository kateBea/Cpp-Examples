#include <algorithm>
#include <common/runnable.hh>
#include <iostream>
#include <vector>

namespace examples::templated_lambda {
    class example1 : public runnable {
    public:
        auto run() -> void override {
            // compute max value from two
            auto max{
                []<typename Type>( const Type& first, const Type& second ) -> Type {
                    return second < first ? first : second;
                }
            };

            std::cout << "lambda max(4.5, 6.7): " << max( 4.5, 6.7 ) << std::endl;

            // display list of elements from range
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