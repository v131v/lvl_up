#ifndef STRING_H
#define STRING_H

class String {
private:
    char* str = nullptr;
    int len = 0;

public:
    String(const char* s);

    String(String&& b);

    ~String();

    bool operator==(const String& b) const;

    bool operator!=(const String& b) const;

    String operator+(const String& b) const;

    String& operator+=(const String& b);

    char& operator[](int i) const;

    int length() const;

    void print() const;
};

#endif // STRING_H
