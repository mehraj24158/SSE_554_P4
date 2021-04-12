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
    std::vector<Car> cars;
    for(int i = 0; i<10; i++)
    {
        Car c;
        // c.price = rand() % 15000 + 20000;
        c.price = 20000*(i+1);
        c.id = rand() % 10 + i;
        cars.push_back(c);
    }
    std::thread engine(EngineInstallerVect, std::ref(cars));
    std::thread frame(FrameInstallerVect, std::ref(cars));
    std::thread tire(TireInstallerVect, std::ref(cars));

    engine.join();
    frame.join();
    tire.join();

    for(Car c: cars)
    {
        std::cout << c.id << " ";
    }
    std::cout << " Initial Car Vector" << endl;

    auto rng = std::default_random_engine {};
    std::shuffle(cars.begin(), cars.end(), rng);

    // std::make_heap(cars.begin(), cars.end(), greater_than_car_price());
    // std::cout << "The minimum element of heap is : ";  
    // std::cout << cars.front().price << endl; 
    // std::cout << "The maximum element of heap is : ";  
    // std::cout << cars.back().price << endl; 
    for(Car c: cars)
    {
        std::cout << c.id << " ";
    }

    std::cout << " Shuffled Car Vector" << endl;


    // Car c = linear_search(cars, 1);
    Car c = binarySearch(cars, cars.front().id, cars.back().id, 13);

    std::cout << c.id << " Sorted Car Vector" << endl;

    // mergeSort(cars, cars.front(), cars.back());
    // bubbleSort(cars);
    // insertionSort(cars);
    // for(Car c: cars)
    // {
    //     std::cout << c.id << " ";
    // }
    // std::cout << " Sorted Car Vector" << endl;



}