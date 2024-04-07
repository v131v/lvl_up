#include "../Word.h"

#include <gtest/gtest.h>

TEST(WordEmpty, Compare) {
    Word w;

    EXPECT_EQ((w == ""), true);
}

TEST(WordEmpty, Init) {
    Word w;

    EXPECT_EQ(w.hash(), 0);
    EXPECT_EQ(w.size(), 0);
    EXPECT_EQ(w.capacity(), 12);
}

TEST(Word, Hash_a) {
    Word w = "a";
    const unsigned long hash = 1;

    EXPECT_EQ(w.hash(), hash);
}

TEST(Word, Hash_b) {
    Word w = "b";
    const unsigned long hash = 2;

    EXPECT_EQ(w.hash(), hash);
}

TEST(Word, Hash_ab) {
    Word w = "ab";
    const unsigned long hash = 1 * Word::hashBase + 2;

    EXPECT_EQ(w.hash(), hash);
}

TEST(Word, Hash_acdbaa) {
    Word w = "acdbaa";
    const unsigned long hash = (
        (
            (
                (
                    1 * Word::hashBase + 3
                ) * Word::hashBase + 4
            ) * Word::hashBase + 2
        ) * Word::hashBase + 1
    ) * Word::hashBase + 1;

    EXPECT_EQ(w.hash(), hash);
}

TEST(Word, Hash_Mod) {
    Word w = "zzzzzz";
    unsigned long hash = 26;

    for (unsigned long i = 0; i < w.size() - 1; ++i) {
        hash *= Word::hashBase;
        hash += 26;
        hash %= Word::hashMod;
    }

    EXPECT_EQ(w.hash(), hash);
}

TEST(Word, Hash_Addition) {
    Word w = "aa";
    w += "b";
    Word w2 = "aab";

    EXPECT_EQ(w.hash(), w2.hash());
}
