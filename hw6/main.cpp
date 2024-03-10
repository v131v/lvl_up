#include "HashTable.h"
#include "WordCounter.h"
#include "../hw5/String.h"

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

template<class T>
T handle(const T& s) {
    T ans = "";
    for (unsigned long i = 0; i < s.length(); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            ans += s[i];
        }
        if (s[i] >= 'A' && s[i] <= 'Z') {
            ans += s[i]-'A'+'a';
        }
    }
    return ans;
}

std::ifstream& operator >>(std::ifstream& in, Word& s) {
    Word ans;

    for (char c = in.get(); !in.eof() && !isspace(c); c = in.get()) {
        if (c > 'z' || c < 'a') {
            if (c <= 'Z' && c >= 'A') {
                ans += (c-'A'+'a');
            }
            continue;
        }
        ans += c;
    }

    s = std::move(ans);

    return in;
}

WordCounter runF1(const char* name) {
    ifstream input(name);

    WordCounter count;
    Word word;

    auto start = chrono::high_resolution_clock::now();

    while (input >> word) {
        if (word == "") {
            continue;
        }

        count.inc(word);
    }

    auto finish = chrono::high_resolution_clock::now();
    auto time = finish - start;

    cout << "WordCounter init time: " << endl;
    cout << time.count() << "ns" << endl;

    input.close();
    return count;
}

unordered_map<string, int> runF2(const char* name) {
    ifstream input(name);

    unordered_map<string, int> count;
    string word;

    auto start = chrono::high_resolution_clock::now();

    while (input >> word) {
        word = handle(word);
        if (word == "") {
            continue;
        }

        count[word]++;
    }

    auto finish = chrono::high_resolution_clock::now();
    auto time = finish - start;

    cout << "UnorderedMap init time: " << endl;
    cout << time.count() << "ns" << endl;

    input.close();
    return count;
}

int getF1(const WordCounter& wc, const vector<Word>& words, const int count) {
    auto start = chrono::high_resolution_clock::now();

    int sum = 0;
    for (int i = 0; i < count; ++i) {
        sum += wc.get(words[i % words.size()]);
    }

    auto finish = chrono::high_resolution_clock::now();
    auto time = finish - start;

    cout << "WordCounter work time: " << endl;
    cout << time.count() << "ns" << endl;

    return sum;
}

int getF2(const unordered_map<string, int>& um, const vector<string>& words, const int count) {
    auto start = chrono::high_resolution_clock::now();

    int sum = 0;
    for (int i = 0; i < count; ++i) {
        auto cur = um.find(words[i % words.size()]);
        if (cur != um.end()) {
            sum += cur->second;
        }
    }

    auto finish = chrono::high_resolution_clock::now();
    auto time = finish - start;

    cout << "UnorderedMap work time: " << endl;
    cout << time.count() << "ns" << endl;

    return sum;
}

void countCheck(const unordered_map<string, int>& um, const WordCounter& wc) {
    for (const auto& x: um) {
        if (x.second != wc.get(x.first.c_str())) {
            cout << "Failed check '" << x.first << "'" << endl;
            cout << "Word counter has " << wc.get(x.first.c_str()) << endl;
            cout << "Unordered map has " << x.second << endl;
        }
    }
}

int main(int argc, char* argv[]) {
//    if (argc != 3) {
//        exit(1);
//    }

    const char* filePath = "/home/v131v/qt_projects/lvl_up/hw6/text.txt";//argv[1];
    const int maxIterCount = 10000000;//atoi(argv[2]);

    auto wc = runF1(filePath);
    auto um = runF2(filePath);

    //countCheck(um, wc);

    vector<string> words;
    vector<Word> words2;

    for (const auto& x: um) {
        if (rand() % 10 == 0) {
            words.push_back(x.first);
            words2.push_back(Word(x.first.c_str()));
        }
    }

    getF1(wc, words2, maxIterCount);
    getF2(um, words, maxIterCount);

    return 0;
}
