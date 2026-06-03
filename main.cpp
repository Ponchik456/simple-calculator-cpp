#define NOMINMAX
#include "include/calculator.h"
#include <iostream>
#include <string>
#include <limits>

#ifdef _WIN32
#include <windows.h>
#endif

void setupRussianConsole() {
#ifdef _WIN32
    // Устанавливаем кодировку 65001 (UTF-8)
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    
    // Включаем поддержку Unicode в консоли
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
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

int main() {
    setupRussianConsole();
    
    int choice;
    double a, b;
    int n;
    
    while (true) {
        showMenu();
        std::cin >> choice;
        
        if (choice == 0) {
            std::cout << "До свидания!\n";
            break;
        }
        
        try {
            switch (choice) {
                case 1:
                    std::cout << "Введите два числа: ";
                    std::cin >> a >> b;
                    std::cout << "Результат: " << calc::add(a, b) << "\n";
                    break;
                case 2:
                    std::cout << "Введите два числа: ";
                    std::cin >> a >> b;
                    std::cout << "Результат: " << calc::subtract(a, b) << "\n";
                    break;
                case 3:
                    std::cout << "Введите два числа: ";
                    std::cin >> a >> b;
                    std::cout << "Результат: " << calc::multiply(a, b) << "\n";
                    break;
                case 4:
                    std::cout << "Введите два числа: ";
                    std::cin >> a >> b;
                    std::cout << "Результат: " << calc::divide(a, b) << "\n";
                    break;
                case 5:
                    std::cout << "Введите основание и целую степень: ";
                    std::cin >> a >> n;
                    std::cout << "Результат: " << calc::power(a, n) << "\n";
                    break;
                case 6:
                    std::cout << "Введите неотрицательное целое число: ";
                    std::cin >> n;
                    std::cout << n << "! = " << calc::factorial(n) << "\n";
                    break;
                case 7:
                    std::cout << "Введите целое число: ";
                    std::cin >> n;
                    std::cout << n << (calc::isPrime(n) ? " является простым" : " не является простым") << "\n";
                    break;
                default:
                    std::cout << "Неверный выбор! Попробуйте снова.\n";
            }
        } catch (const std::exception& e) {
            std::cout << "Ошибка: " << e.what() << "\n";
        }
        
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    
    return 0;
}