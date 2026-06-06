cmake_minimum_required(VERSION 3.10)
project(SimpleCalculator)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

# Основная программа (создаём цель calculator)
add_executable(calculator 
    main.cpp 
    src/calculator.cpp
)

# Тесты (создаём цель tests)
add_executable(tests 
    tests/test_calculator.cpp 
    src/calculator.cpp
)

# Теперь можно добавлять include directories для уже созданных целей
target_include_directories(calculator PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Включаем тесты
enable_testing()
add_test(NAME CalculatorTests COMMAND tests)
