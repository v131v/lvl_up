#ifndef WORD_H
#define WORD_H

class Word {
private:
    unsigned long _cap = 0;
    unsigned long _len = 0;
    char* _str = nullptr;
    mutable unsigned long long _hash = 0;

public:
    static constexpr unsigned long long hashBase = 31;
    static constexpr unsigned long long hashMod = 1e9+7;
    static constexpr unsigned long minCap = 46;

    Word();
    Word(const char c);
    Word(const char* s);
    Word(const Word& b);
    Word(Word&& b);

    ~Word();

    bool operator ==(const Word& b) const;
    bool operator !=(const Word& b) const;

    Word&& operator +(const Word& b) const;
    Word& operator +=(const Word& b);

    Word& operator =(const Word& b);
    Word& operator =(Word&& b);

    char& operator [](int i);
    const char& operator [](int i) const;

    unsigned long length() const;

    unsigned long capacity() const;

    void shrinkToFit();

    const char* c_str() const;

    unsigned long long hash() const;
};

#endif // WORD_H
