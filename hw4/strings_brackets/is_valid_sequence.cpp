#include "is_valid_sequence.h"

bool isValidSequence(const char *str) {

    int cnt = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '(' && str[i] != ')') {
            return false;
        }

        if (str[i] == '(') {
            cnt++;
        }

        if (str[i] == ')') {
            cnt--;
        }

        if (cnt < 0) {
            break;
        }
    }

    if (cnt != 0) {
        return false;
    }
    return true;
}
