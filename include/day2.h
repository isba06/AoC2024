#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <sstream>
#include <cmath>
#include <array>


namespace Day2 {

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec){
    std::for_each(vec.begin(), vec.end(), [&](int x) {
        os << x << ' ';
    });
    return os;
}

enum Trend {
    none = 0,
    increase, // возрастание
    decrease, // убывание
    mixed
};

bool checkTrendRule(const std::vector<int> & arr) {
    Trend trend = none;
    auto prev = arr.begin();
    auto next = arr.begin() + 1;
    *prev < *next ? trend = increase : trend = decrease;
    while(next != arr.end()){
        switch(trend) {
            case increase:
                if(*prev >= *next)
                    trend = mixed;
                
                if((*prev + 1 != *next) && ( *prev + 2 != *next)  && (*prev + 3 != *next)) {
                    return false;
                }
                break;
            case decrease:
                if(*prev <= *next)
                    trend = mixed;

                if((*prev - 1 != *next) && ( *prev - 2 != *next)  && (*prev - 3 != *next)) {
                    return false;
                }
                break;
            case mixed:
                std::cout << "mixed\n";
                return false;
            case none:
                std::cout << "none!\n";
                break;
        }
        prev = next;
        ++next;
    }
    return true;
}

int run() {
    std::ifstream file("../inputs/input2.txt");
    if(!file){
        std::cerr << "file not found\n";
        return 1;
    }
    std::string line;
    int num, count = 0;
    while(std::getline(file, line)) {
        std::vector<int> arr;
        std::istringstream istr(line);
        while(istr >> num){
            arr.push_back(num);
        }
        if(Day2::checkTrendRule(arr)){
            ++count;
        }
    }
    return count;
}

} //namespace Day2