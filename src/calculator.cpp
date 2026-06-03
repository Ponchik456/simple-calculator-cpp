#include "calculator.h"
#include <stdexcept>
#include <cmath>

namespace calc {

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("На 0 делить низя");
    }
    return a / b;
}

double power(double base, int exp) {
    if (exp < 0) {
        throw std::invalid_argument("Степень отрицательная");
    }
    double result = 1.0;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}

long long factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("Факториал отрицательного числа, низя так");
    }
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    int limit = static_cast<int>(std::sqrt(n)) + 1;
    for (int i = 3; i <= limit; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

}