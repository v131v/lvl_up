#include <stdio.h>
#include <string.h>

struct String {
    char *data;
    int size;
    int capacity;
};

String* NewString(const char* init) {
    String* str = new String;
    str->size = strlen(init);
    str->capacity = str->size + 1;
    str->data = new char[str->capacity];
    memcpy(str->data, init, str->capacity);
    return str;
}

void DeleteString(String* str) {
    delete[] str->data;
    delete str;
}

void PrintString(String* str) {
    for (int i = 0; i < str->size; ++i) {
        printf("%c", str->data[i]);
    }
}

String* AppendString(String* str, const char* add) {
    const int len = strlen(add);

    if (str->size + len >= str->capacity) {
        const char* lastStrData = str->data;
        str->capacity = str->size + len + 1;
        str->data = new char[str->capacity];

        memcpy(str->data, lastStrData, str->size);
        delete[] lastStrData;
    }

    memcpy(str->data + str->size, add, len);
    str->size += len;
    str->data[str->size] = '\0';

    return str;
}

void SaveStringAs(String* str, const char* fileName) {
    FILE* file = fopen(fileName, "w");
    fwrite(str->data, str->size, 1, file);
    fclose(file);
}

String* ReadStringFrom(const char* fileName) {
    FILE* file = fopen(fileName, "r");

    fseek(file, 0, SEEK_END);
    const int stringSize = ftell(file);

    char* data = new char[stringSize + 1];
    fseek(file, 0, SEEK_SET);
    fread(data, stringSize, 1, file);
    data[stringSize] = '\0';

    String* str = NewString(data);

    delete[] data;
    fclose(file);
    return str;
}

int main()
{
    const char* fileName = "str.txt";
    String* str = NewString("hello");
    str = AppendString(str, " worl");
    PrintString(str);
    SaveStringAs(str, fileName);
    DeleteString(str);

    String* str2 = ReadStringFrom(fileName);
    PrintString(str2);
    DeleteString(str2);

    return 0;
}
