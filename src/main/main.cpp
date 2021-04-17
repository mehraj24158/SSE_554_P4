#include <iostream>
#include <thread>
#include <algorithm>
#include <random>
#include "src/lib/car.hpp"
#include "src/lib/operations.hpp"
#include "src/lib/bubble.hpp"
#include "src/lib/insertion.hpp"
#include "src/lib/merge.hpp"
#include "src/lib/linearSearch.hpp"
#include "src/lib/binarySearch.hpp"



int main() 
{
    if (__cplusplus == 201703L) std::cout << "C++17\n";
    else if (__cplusplus == 201402L) std::cout << "C++14\n";
    else if (__cplusplus == 201103L) std::cout << "C++11\n";
    else if (__cplusplus == 199711L) std::cout << "C++98\n";
    else std::cout << "pre-standard C++\n";
}