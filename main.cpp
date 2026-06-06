#include "include/calculator.h"
#include <iostream>
#include <string>
#include <limits>
#include <sstream>

#ifdef _WIN32
#include <windows.h>
#endif

void setupConsole() {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
}

void showMenu() {
    std::cout << "\n========== КАЛЬКУЛЯТОР ==========\n";
    std::cout << "1. Сложение (+)\n";
    std::cout << "2. Вычитание (-)\n";
    std::cout << "3. Умножение (*)\n";
    std::cout << "4. Деление (/)\n";
    std::cout << "5. Возведение в степень (^)\n";
    std::cout << "6. Факториал (!)\n";
    std::cout << "7. Проверка числа на простоту\n";
    std::cout << "0. Выход\n";
    std::cout << "================================\n";
    std::cout << "Выберите операцию: ";
}

bool readDouble(double& value) {
    std::cin >> value;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000000, '\n');
        return false;
    }
    return true;
}

bool readInt(int& value) {
    std::cin >> value;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000000, '\n');
        return false;
    }
    return true;
}

int main() {
    setupConsole();
    
    int choice;
    double a, b;
    int n;
    
    while (true) {
        showMenu();
        
        if (!readInt(choice)) {
            std::cout << "Ошибка: неверный ввод. Пожалуйста, введите число от 0 до 7.\n";
            continue;
        }
        
        if (choice == 0) {
            std::cout << "До свидания!\n";
            break;
        }
        
        try {
            switch (choice) {
                case 1:
                    std::cout << "Введите два числа: ";
                    if (!readDouble(a) || !readDouble(b)) {
                        std::cout << "Ошибка: неверный формат числа.\n";
                        break;
                    }
                    std::cout << "Результат: " << calc::add(a, b) << "\n";
                    break;
                case 2:
                    std::cout << "Введите два числа: ";
                    if (!readDouble(a) || !readDouble(b)) {
                        std::cout << "Ошибка: неверный формат числа.\n";
                        break;
                    }
                    std::cout << "Результат: " << calc::subtract(a, b) << "\n";
                    break;
                case 3:
                    std::cout << "Введите два числа: ";
                    if (!readDouble(a) || !readDouble(b)) {
                        std::cout << "Ошибка: неверный формат числа.\n";
                        break;
                    }
                    std::cout << "Результат: " << calc::multiply(a, b) << "\n";
                    break;
                case 4:
                    std::cout << "Введите два числа: ";
                    if (!readDouble(a) || !readDouble(b)) {
                        std::cout << "Ошибка: неверный формат числа.\n";
                        break;
                    }
                    std::cout << "Результат: " << calc::divide(a, b) << "\n";
                    break;
                case 5:
                    std::cout << "Введите основание и целую степень: ";
                    if (!readDouble(a) || !readInt(n)) {
                        std::cout << "Ошибка: неверный формат числа.\n";
                        break;
                    }
                    std::cout << "Результат: " << calc::power(a, n) << "\n";
                    break;
                case 6:
                    std::cout << "Введите неотрицательное целое число: ";
                    if (!readInt(n)) {
                        std::cout << "Ошибка: неверный формат числа.\n";
                        break;
                    }
                    std::cout << n << "! = " << calc::factorial(n) << "\n";
                    break;
                case 7:
                    std::cout << "Введите целое число: ";
                    if (!readInt(n)) {
                        std::cout << "Ошибка: неверный формат числа.\n";
                        break;
                    }
                    std::cout << n << (calc::isPrime(n) ? " является простым" : " не является простым") << "\n";
                    break;
                default:
                    std::cout << "Неверный выбор! Введите число от 0 до 7.\n";
            }
        } catch (const std::exception& e) {
            std::cout << "Ошибка: " << e.what() << "\n";
        }
        
        std::cin.clear();
        std::cin.ignore(1000000, '\n');
    }
    
    return 0;
}
