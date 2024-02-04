#include "../../String.h"

#include <gtest/gtest.h>

#include <gtest/gtest.h>

TEST(StringTest, ConstructorAndEquality) {
    String s1("hello");
    String s2("world");
    String s3("hello");

    EXPECT_EQ(s1, s3);
    EXPECT_NE(s1, s2);
}

TEST(StringTest, ConcatenationOperator) {
    String s1("hello");
    String s2("world");
    String result = s1 + s2;

    EXPECT_EQ(result, "helloworld");
}

TEST(StringTest, ConcatenationAssignmentOperator) {
    String s1("hello");
    String s2("world");

    s1 += s2;

    EXPECT_EQ(s1, "helloworld");
}

TEST(StringTest, LengthMethod) {
    String s1("hello");
    String s2("world123");
    String empty("");

    EXPECT_EQ(s1.length(), 5);
    EXPECT_EQ(s2.length(), 8);
    EXPECT_EQ(empty.length(), 0);
}

TEST(StringTest, MoveConstructor) {
    String s1("hello");

    String s2(std::move(s1));

    EXPECT_EQ(s2, "hello");
}
