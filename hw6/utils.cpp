#include "utils.h"
#include "WordCounter.h"

#include <string>
#include <algorithm>
#include <unordered_map>
#include <iostream>

std::string handle(std::string str) {
    str.erase(std::remove_if(str.begin(), str.end(), [](unsigned char c) {
        return !std::isalpha(c);
    }), str.end());
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c){
        return std::tolower(c);
    });
    return str;
}

void countCheck(const std::unordered_map<std::string, int>& um, const WordCounter& wc) {
    for (const auto& x: um) {
        if (x.second != wc.get(x.first.c_str())) {
            std::cout << "Failed check '" << x.first << "'" << std::endl;
            std::cout << "Word counter has " << wc.get(x.first.c_str()) << std::endl;
            std::cout << "Unordered map has " << x.second << std::endl;
        }
    }
}

