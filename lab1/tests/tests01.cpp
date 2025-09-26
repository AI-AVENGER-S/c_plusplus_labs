#include <gtest/gtest.h>
#include <stdexcept>
#include "../include/closest_to_bound.h"

using namespace std;
// Основные тесты
TEST(test_01, basic_test_set) {
    ASSERT_EQ(closest_to_bound(3, 10), 9);
    ASSERT_EQ(closest_to_bound(5, 23), 20);
    ASSERT_EQ(closest_to_bound(7, 100), 98);
    ASSERT_EQ(closest_to_bound(2, 11), 10);
}

// Краевые случаи с границей
TEST(test_02, basic_test_set) {
    // Граница равна делителю
    ASSERT_EQ(closest_to_bound(5, 5), 5);
    ASSERT_EQ(closest_to_bound(1, 1), 1);
    
    // Граница чуть больше делителя
    ASSERT_EQ(closest_to_bound(10, 11), 10);
    ASSERT_EQ(closest_to_bound(100, 101), 100);
}

// Тесты с делителем 1
TEST(test_03, basic_test_set) {
    ASSERT_EQ(closest_to_bound(1, 1), 1);
    ASSERT_EQ(closest_to_bound(1, 100), 100);
    ASSERT_EQ(closest_to_bound(1, 999), 999);
}

// Тесты с большими числами
TEST(test_04, basic_test_set) {
    ASSERT_EQ(closest_to_bound(1000, 123456), 123000);
    ASSERT_EQ(closest_to_bound(999, 1000000), 999999);
    ASSERT_EQ(closest_to_bound(1024, 1048576), 1048576);
}

// Тесты на исключения для неположительных параметров
TEST(test_05, basic_test_set) {
    EXPECT_THROW(closest_to_bound(0, 10), invalid_argument);
    EXPECT_THROW(closest_to_bound(-5, 10), invalid_argument);
    EXPECT_THROW(closest_to_bound(5, -10), invalid_argument);
    EXPECT_THROW(closest_to_bound(-5, -10), invalid_argument);
    EXPECT_THROW(closest_to_bound(0, 0), invalid_argument);
}

// Тесты на исключения когда невозможно найти N > 0
TEST(test_06, basic_test_set) {
    EXPECT_THROW(closest_to_bound(10, 5), runtime_error);
    EXPECT_THROW(closest_to_bound(100, 50), runtime_error);
    EXPECT_THROW(closest_to_bound(7, 3), runtime_error);
    EXPECT_THROW(closest_to_bound(5, 4), runtime_error);
    EXPECT_THROW(closest_to_bound(10, 9), runtime_error);
    EXPECT_THROW(closest_to_bound(2, 1), runtime_error);
}

// Тесты с делителем больше границы
TEST(test_07, basic_test_set) {
    EXPECT_THROW(closest_to_bound(20, 15), runtime_error);
    EXPECT_THROW(closest_to_bound(100, 50), runtime_error);
    EXPECT_THROW(closest_to_bound(1000, 999), runtime_error);
}

// Тесты с границей 1
TEST(test_08, basic_test_set) {
    ASSERT_EQ(closest_to_bound(1, 1), 1);
    EXPECT_THROW(closest_to_bound(2, 1), runtime_error);
    EXPECT_THROW(closest_to_bound(3, 1), runtime_error);
}

// Тесты на точное деление
TEST(test_09, basic_test_set) {
    ASSERT_EQ(closest_to_bound(2, 8), 8);
    ASSERT_EQ(closest_to_bound(4, 16), 16);
    ASSERT_EQ(closest_to_bound(10, 100), 100);
    ASSERT_EQ(closest_to_bound(25, 100), 100);
}

// Тесты с последовательными значениями
TEST(test_10, basic_test_set) {
    EXPECT_THROW(closest_to_bound(3, 1), runtime_error);
    EXPECT_THROW(closest_to_bound(3, 2), runtime_error);
    ASSERT_EQ(closest_to_bound(3, 3), 3);
    ASSERT_EQ(closest_to_bound(3, 4), 3);
    ASSERT_EQ(closest_to_bound(3, 5), 3);
    ASSERT_EQ(closest_to_bound(3, 6), 6);
    ASSERT_EQ(closest_to_bound(3, 7), 6);
    ASSERT_EQ(closest_to_bound(3, 8), 6);
    ASSERT_EQ(closest_to_bound(3, 9), 9);
}

// Тесты с минимальными валидными значениями
TEST(test_11, basic_test_set) {
    ASSERT_EQ(closest_to_bound(1, 1), 1);
    ASSERT_EQ(closest_to_bound(2, 2), 2);
    ASSERT_EQ(closest_to_bound(3, 3), 3);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}