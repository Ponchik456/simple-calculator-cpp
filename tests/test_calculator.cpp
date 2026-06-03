#define NOMINMAX
#include "../include/calculator.h"
#include <cassert>
#include <iostream>
#include <stdexcept>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace calc;

void setupRussianConsole() {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
}

void testAdd() {
    assert(add(2, 3) == 5);
    assert(add(-1, 1) == 0);
    assert(add(0, 0) == 0);
    assert(add(2.5, 3.5) == 6.0);
    std::cout << "✓ Тест сложения пройден\n";
}

void testSubtract() {
    assert(subtract(5, 3) == 2);
    assert(subtract(0, 5) == -5);
    assert(subtract(-3, -2) == -1);
    std::cout << "✓ Тест вычитания пройден\n";
}

void testMultiply() {
    assert(multiply(4, 5) == 20);
    assert(multiply(0, 100) == 0);
    assert(multiply(-3, 4) == -12);
    assert(multiply(2.5, 2) == 5.0);
    std::cout << "✓ Тест умножения пройден\n";
}

void testDivide() {
    assert(divide(10, 2) == 5);
    assert(divide(7, 2) == 3.5);
    assert(divide(-6, 3) == -2);
    
    bool exceptionThrown = false;
    try {
        divide(5, 0);
    } catch (const std::invalid_argument&) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);
    std::cout << "✓ Тест деления пройден\n";
}

void testPower() {
    assert(power(2, 3) == 8);
    assert(power(5, 0) == 1);
    assert(power(2, 1) == 2);
    assert(power(2.5, 2) == 6.25);
    
    bool exceptionThrown = false;
    try {
        power(2, -1);
    } catch (const std::invalid_argument&) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);
    std::cout << "✓ Тест возведения в степень пройден\n";
}

void testFactorial() {
    assert(factorial(0) == 1);
    assert(factorial(1) == 1);
    assert(factorial(5) == 120);
    assert(factorial(10) == 3628800);
    
    bool exceptionThrown = false;
    try {
        factorial(-5);
    } catch (const std::invalid_argument&) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);
    std::cout << "✓ Тест факториала пройден\n";
}

void testIsPrime() {
    assert(isPrime(2) == true);
    assert(isPrime(3) == true);
    assert(isPrime(17) == true);
    assert(isPrime(1) == false);
    assert(isPrime(4) == false);
    assert(isPrime(100) == false);
    assert(isPrime(97) == true);
    std::cout << "✓ Тест проверки простоты пройден\n";
}

int main() {
    setupRussianConsole();
    
    std::cout << "\n=== ЗАПУСК ТЕСТОВ ===\n\n";
    
    testAdd();
    testSubtract();
    testMultiply();
    testDivide();
    testPower();
    testFactorial();
    testIsPrime();
    
    std::cout << "\n=== ВСЕ ТЕСТЫ ПРОЙДЕНЫ! (7/7) ===\n";
    return 0;
}