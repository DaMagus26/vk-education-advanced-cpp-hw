#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <chrono>
//#include "parsedata.hpp"

const std::filesystem::path data_path = "../data/title.basics.tsv";

template<class Out>
void split(const std::string& str, Out os, const char sep='\t') {
    typedef std::string::const_iterator iter;
    auto not_sep = [sep](const char c) { return c != sep; };
    auto is_sep = [sep](const char c) { return c == sep; };

    iter i = str.begin();
    while (i != str.end()) {
        i = std::find_if(i, str.end(), not_sep);
        iter j = std::find_if(i, str.end(), is_sep);
        if (i != str.end()) {
            *os++ = std::string(i, j);
        }
        i = j;
    }
}

int main() {
    std::cout << data_path << std::endl;
    std::ifstream input(data_path);
    if (input) {
        std::string line;
        long int width = 0;
        int counter = 0;
        bool flag = false;
        auto start = std::chrono::high_resolution_clock::now();
        while (getline(input, line)) {
            std::vector<std::string> words;
            std::vector<std::string> genres;
            getline(input, line);
            split(line, std::back_inserter(words));
            split(words.back(), std::back_inserter(genres), ',');

            if (counter % 100000 == 0) {
                std::cout << "Parsed " << counter << " lines..." << std::endl;
            }
//            for (const auto& x: genres) {
//                std::cout << x << " ";
//            }
            counter++;
            width = words.size();
            if (width != 9) {
                flag = true;
            }
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
        std::cout << "Total rows: " << counter << std::endl;
        std::cout << "Total time (seconds): " << duration.count() << std::endl;
        return 0;
    } else {
        std::cerr << "Invalid path: " << data_path << std::endl;
        return -1;
    }
}
