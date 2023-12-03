#include "../print_binary.h"

#include <gtest/gtest.h>

TEST(GetBinaryTest, PositiveNumbers) {
    char result1[65] = ""; // предполагаем максимальную длину бинарной строки
    getBinary(10, result1);
    EXPECT_STREQ("0000000000000000000000000000000000000000000000000000000000001010", result1);

    char result2[65] = "";
    getBinary(27, result2);
    EXPECT_STREQ("0000000000000000000000000000000000000000000000000000000000011011", result2);
}

TEST(GetBinaryTest, NegativeNumbers) {
    char result1[65] = "";
    getBinary(-15, result1);
    EXPECT_STREQ("1111111111111111111111111111111111111111111111111111111111110001", result1);

    char result2[65] = "";
    getBinary(-8, result2);
    EXPECT_STREQ("1111111111111111111111111111111111111111111111111111111111111000", result2);
}

TEST(GetBinaryTest, Zero) {
    char result[64] = "";
    getBinary(0, result);
    EXPECT_STREQ("0000000000000000000000000000000000000000000000000000000000000000", result);
}

// Тест для больших чисел
TEST(GetBinaryTest, LargeNumbers) {
    char result[256] = ""; // предполагаем большую длину для больших чисел
    getBinary(123456789012345, result);
    EXPECT_STREQ("0000000000000000011100000100100010000110000011011101111101111001", result);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
