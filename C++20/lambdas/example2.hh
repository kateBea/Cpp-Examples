/************************************************************************
 * @file main.cc
 * @author kate
 * @brief simple usage of lambdas perfect capture
 * @version 1.0
 * @date 2023-11-19
 * 
 * @copyright Copyright (c) 2023
 * *********************************************************************/

#if !defined(CPP_EXAMPLES_CPP20_LAMBDAS_EXAMPL2)
#define CPP_EXAMPLES_CPP20_LAMBDAS_EXAMPL2

#include <algorithm>
#include <iostream>
#include <utility>
#include <functional>
#include <thread>
#include <vector>

#include <common/runnable.hh>

namespace examples::lambdas {
    class example2 : public runnable {
    public:
        auto run() -> void override {
            std::vector<std::thread> threads{};

            // std::cout is not thread safe
            auto print{ []<typename T>(const T& value) -> void { std::cout << value << '\n'; } };

            for (std::size_t count{}; count < 4; ++count) {
                threads.emplace_back(make_task(print, count));
            }

            for (auto& thread : threads) {
                thread.join();
            }
        }

    private:
        template<typename FunctionType, typename... Args>
        static auto make_task(FunctionType&& func, Args&&... args) -> std::function<void()> {
            auto task{
                [func = std::forward<FunctionType>(func), ...args = std::forward<Args>(args)]
                <typename... Args>
                () -> void {
                    func(std::move(args)...);
                }
            };

            return std::function<void()>{ task };
        }
    };
}

#endif