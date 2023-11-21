/************************************************************************
 * @file main.cc
 * @author kate
 * @brief simple usage of structured bindings to print the employees of a std::unordered_set
 * @version 1.0
 * @date 2023-11-21
 * *********************************************************************/

#if !defined(CPP_EXAMPLES_CPP17_DECLARATIONS_EXAMPLE1)
#define CPP_EXAMPLES_CPP17_DECLARATIONS_EXAMPLE1

#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <unordered_map>

#include <Common/runnable.hh>

namespace examples::declarations {
    class example1 : public runnable {
    public:
        auto run() -> void override {
            std::unordered_map<std::int32_t, employee> employees{};

            employees.try_emplace(1, "Jordan", 200);
            employees.try_emplace(2, "Kaylen", 400);
            employees.try_emplace(3, "Maria", 560);
            employees.try_emplace(4, "Jorge", 100);
            employees.try_emplace(5, "Daniel", 1);

            for (const auto& [identifier, employee] : employees) {
                std::cout << identifier << " [ " << employee.name() << ", " << employee.salary() << " ]\n";
            }
        }

    private:
        class employee {
        public:
            explicit employee(std::string_view str, double salary = 0.0)
                :   m_name{ str }, m_salary{ salary }
            {   }

            employee(const employee& other) = default;

            [[nodiscard]] auto name() const -> const std::string& { return m_name; }
            [[nodiscard]] auto salary() const -> double { return m_salary; }

            auto set_name(std::string_view newName) -> void { m_name = newName; }
            auto set_salary(double newSalary) -> void { m_salary = newSalary < 0.0 ? m_salary : newSalary; }

        private:
            std::string m_name{};
            double m_salary{};
        };
    };
}

#endif