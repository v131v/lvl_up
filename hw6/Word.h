#ifndef WORD_H
#define WORD_H

class Word {
private:
    unsigned long _capacity = minCap;
    unsigned long _length = 0;
    char* _data = nullptr;
    unsigned long long _hash = 0;

public:
    static constexpr unsigned long long hashBase = 31;
    static constexpr unsigned long long hashMod = 1e9+7;
    static constexpr unsigned long minCap = 10;

    Word();
    Word(const char* s);
    Word(const Word& other);
    Word(Word&& other);

    ~Word();

    void swap(Word& other) noexcept;

    friend bool operator == (const Word& a, const Word& b);
    friend bool operator != (const Word& a, const Word& b);
    friend Word operator + (const Word& a, const Word& b);

    Word& operator += (const Word& other);
    Word& operator += (char c);

    Word& operator = (const Word& other);
    Word& operator = (Word&& other);

    char& operator [] (int i);
    const char& operator [] (int i) const;

    unsigned long length() const;

    unsigned long capacity() const;

    const char* c_str() const;

    unsigned long long hash() const;
};

bool operator == (const Word& a, const Word& b);
bool operator != (const Word& a, const Word& b);
Word operator + (const Word& a, const Word& b);

#endif // WORD_H
