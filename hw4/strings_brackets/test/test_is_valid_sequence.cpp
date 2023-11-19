#include "../is_valid_sequence.h"

#include <gtest/gtest.h>
#include <string.h>

TEST(IS_VALID_SEQUENCE, VALID_NO_NESTED) {
    const char *str = "()()()";

    ASSERT_TRUE(isValidSequence(str));
}

TEST(IS_VALID_SEQUENCE, VALID_NESTED) {
    const char *str = "()(())((()))";

    ASSERT_TRUE(isValidSequence(str));
}

TEST(IS_VALID_SEQUENCE, NOT_VALID_NO_NESTED) {
    const char *str = "()()(";

    ASSERT_FALSE(isValidSequence(str));
}

TEST(IS_VALID_SEQUENCE, NOT_VALID_NO_NESTED_SAME_COUNT) {
    const char *str = ")(";

    ASSERT_FALSE(isValidSequence(str));
}

TEST(IS_VALID_SEQUENCE, NOT_VALID_NESTED) {
    const char *str = "(()";

    ASSERT_FALSE(isValidSequence(str));
}

TEST(IS_VALID_SEQUENCE, NOT_VALID_NESTED_SAME_COUNT) {
    const char *str = "(()))(";

    ASSERT_FALSE(isValidSequence(str));
}
