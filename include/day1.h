#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <sstream>
#include <cmath>


namespace Day1 {

int run() {
    std::ifstream file("../inputs/input1.txt");
    if(!file){
        std::cerr << "file not found\n";
        return 0;
    }
    std::string line, f, s;

    std::multiset<int> first, second;
    while(std::getline(file, line)) {
        std::istringstream istr(line);
        istr >> f >> s;
        first.insert(std::stoi(f));
        second.insert(std::stoi(s));
    }
    file.close();

    std::size_t sum = 0;
    int first_value = 0, second_value = 0;
    auto it_f = first.begin();
    auto it_s = second.begin();
    while(it_f != first.end() || it_s != second.end()){
        if(it_f != first.end()) {
            first_value = *it_f;
            ++it_f;
        }
        if(it_s != second.end()) {
            second_value = *it_s;
            ++it_s;
        }
        sum += std::abs(first_value - second_value);
    }

    return sum;
}

} // namespace