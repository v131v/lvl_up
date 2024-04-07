#include "WordCounter.h"
#include "utils.h"

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>
#include <chrono>
#include <functional>

using namespace std;

template <class T>
T printTimeAndReturn(const function<T()> &f) {
    auto start = chrono::high_resolution_clock::now();
    T ans = f();
    auto finish = chrono::high_resolution_clock::now();
    auto time = finish - start;
    cout << time.count() << "ns";
    return ans;
}

template <class T>
void printTime(const function<T()> &f) {
    auto start = chrono::high_resolution_clock::now();
    f();
    auto finish = chrono::high_resolution_clock::now();
    auto time = finish - start;
    cout << time.count() << "ns";
}

template <class T>
T withInputFile(const char* name, const function<T(istream&)> &f) {
    ifstream input(name);
    T ans = f(input);
    input.close();
    return ans;
}

template <class T>
T init(const char* filePath, const function<T(istream&)> &f) {
    return printTimeAndReturn<T>([&]() {
        return withInputFile<T>(filePath, f);
    });;
}

int main(int argc, char* argv[]) {
//    if (argc != 4) {
//        exit(1);
//    }

    const char* filePath = "/home/v131v/qt_projects/lvl_up/hw6/text.txt";//argv[1];
    const int maxIterCount = 10000000;//atoi(argv[2]);
    const char* targetWord = "/home/v131v/qt_projects/lvl_up/hw6/text.txt";//argv[3];

    WordCounter wc = init<WordCounter>(filePath, [](istream &input) {
        WordCounter counter;
        Word word;

        while (input >> word) {
            if (word == "") {
                continue;
            }

            counter.inc(word);
        }

        cout << "WordCounter initialize complete:" << endl;

        return counter;
    });

    unordered_map<string, int> um = init<unordered_map<string, int>>(filePath, [](istream &input) {
        unordered_map<string, int> counter;
        string word;

        while (input >> word) {
            word = handle(word);
            if (word == "") {
                continue;
            }

            counter[word]++;
        }

        return counter;
    });

    countCheck(um, wc);

    printTime<void>([&wc, targetWord]() {
        for (int i = 0; i < maxIterCount; ++i) {
            wc.get(targetWord);
        }

        cout << "WordCounter get:" << endl;
    });

    printTime<void>([&um, targetWord]() {
        for (int i = 0; i < maxIterCount; ++i) {
            um[targetWord];
        }

        cout << "UnorderedMap get:" << endl;
    });

    return 0;
}
