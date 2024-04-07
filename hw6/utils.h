#ifndef UTILS_H
#define UTILS_H

#include "WordCounter.h"

#include <string>
#include <unordered_map>

std::string handle(std::string str);

void countCheck(const std::unordered_map<std::string, int>& um, const WordCounter& wc);

#endif // UTILS_H
