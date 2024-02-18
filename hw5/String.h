#ifndef STRING_H
#define STRING_H

class String {
private:
    unsigned long _cap = 0;
    unsigned long _len = 0;
    char* _str = nullptr;

public:
    String();
    String(const char c);
    String(const char* s);
    String(const String& b);
    String(String&& b);

    ~String();

    bool operator ==(const String& b) const;
    bool operator !=(const String& b) const;

    String operator +(const String& b) const;
    String& operator +=(const String& b);

    String& operator =(const String& b);
    String& operator =(String&& b);

    char& operator [](int i);
    const char& operator [](int i) const;

    unsigned long length() const;

    unsigned long capacity() const;

    void shrinkToFit();

    const char* c_str() const;
};

#endif // STRING_H
