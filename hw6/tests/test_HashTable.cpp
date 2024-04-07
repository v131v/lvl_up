#include "../HashTable.h"
#include "../PrimeNumberGenerator.h"

#include <gtest/gtest.h>

TEST(HashTable, Init) {
    PrimeNumberGenerator gen(1e7);

    HashTable ht(&gen);

    EXPECT_EQ(ht.size(), 0);
    EXPECT_EQ(ht.capacity(), 13);
}

TEST(HashTable, Inc) {
    PrimeNumberGenerator gen(1e7);

    HashTable ht(&gen);

    ht.inc("aboba");
    EXPECT_EQ(ht.get("aboba")->count, 1);

    ht.inc("aboba");
    ht.inc("aboba");
    EXPECT_EQ(ht.get("aboba")->count, 3);
}

TEST(HashTable, Rebelance) {
    PrimeNumberGenerator gen(1e7);

    HashTable ht(&gen);
    const unsigned long cap = 13;

    Word w;

    for (unsigned long i = 0; i < cap; ++i) {
        w += char(i+'a');
        ht.inc(w);
    }

    w += char(cap+'a');
    ht.inc(w);

    const unsigned long newCap = gen.upperBound(cap * 2);

    EXPECT_EQ(ht.size(), cap + 1);
    EXPECT_EQ(ht.capacity(), newCap);

    w = "";

    for (unsigned long i = 0; i < cap + 1; ++i) {
        w += char(i+'a');
        int cnt = ht.get(w)->count;
        EXPECT_EQ(cnt, 1);
    }
}
