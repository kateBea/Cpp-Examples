/************************************************************************
 * @file runnable.hh
 * @author kate
 * @brief common interface for examples
 * @version 1.0
 * @date 2023-11-19
 * 
 * @copyright Copyright (c) 2023
 * *********************************************************************/

namespace examples {
    class runnable {
    public:
        virtual auto run() -> void = 0;
    };
}