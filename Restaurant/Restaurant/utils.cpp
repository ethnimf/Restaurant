#include "utils.h"
#include <iostream>
#include <limits>

namespace Utils {
    int getIntInput(const std::string& prompt) {
        int value;
        while (true) {
            std::cout << prompt;
            std::cin >> value;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Введите цифру." << std::endl;
            }
            else {
                break;
            }
        }
        return value;
    }

    std::string getStringInput(const std::string& prompt) {
        std::string value;
        std::cout << prompt;
        std::cin >> value;
        return value;
    }
}
