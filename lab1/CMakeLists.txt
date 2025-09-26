cmake_minimum_required(VERSION 3.10)
project(c_plusplus_labs)

# Находим установленный googletest
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

# Основная программа
add_executable(lab1 main.cpp src/closest_to_bound.cpp)
target_include_directories(lab1 PUBLIC include)

# Тесты
add_executable(tests tests/tests01.cpp src/closest_to_bound.cpp)
target_include_directories(tests PUBLIC include)
target_link_libraries(tests GTest::gtest_main Threads::Threads)

# Чтобы исполняемые файлы были в корне build
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})