#include "gtest/gtest.h"
#include <thread>
#include <stack>
#include <queue>
#include <algorithm>
#include <random>
#include <mutex>
#include <shared_mutex>
#include "src/lib/car.hpp"
#include "src/lib/engine.hpp"
#include "src/lib/frame.hpp"
#include "src/lib/tire.hpp"
#include "src/lib/operations.hpp"
#include "src/lib/bubble.hpp"
#include "src/lib/insertion.hpp"
#include "src/lib/linearSearch.hpp"
#include "src/lib/binarySearch.hpp"

// Uncomment this to make sure google test fails corectly
// TEST(fail_this_test, fail){
//     ASSERT_EQ(0, 1);
// };


TEST(EmptyCar, EngineInstall){
    Car one;
    Car* P = &one;
    std::thread engine(EngineInstaller, std::ref(P));
    engine.join();
    ASSERT_TRUE(&P->engine != NULL);
};

TEST(EmptyCar, FrameInstall){
    Car one;
    Car* P = &one;
    std::thread frame(FrameInstaller, std::ref(P));
    frame.join();
    ASSERT_TRUE(&P->frame != NULL);
};

TEST(EmptyCar, TireInstall){
    Car one;
    Car* P = &one;
    std::thread tire(TireInstaller, std::ref(P));
    tire.join();
    ASSERT_TRUE(&P->tire!= NULL);
    ASSERT_TRUE(P->tire.size()==4) << P->tire.size() << " Number of tires";
};

TEST(EmptyCar, CompleteInstall){
    Car one;
    Car* P = &one;
    std::thread engine(EngineInstaller, std::ref(P));
    std::thread frame(FrameInstaller, std::ref(P));
    std::thread tire(TireInstaller, std::ref(P));
    engine.join();
    frame.join();
    tire.join();
    ASSERT_TRUE(&P->engine != NULL);
    ASSERT_TRUE(&P->frame != NULL);
    ASSERT_TRUE(&P->tire!= NULL);
    ASSERT_TRUE(P->tire.size()==4) << P->tire.size() << " Number of tires";
};

TEST(EmptyCar, VectorCompleteInstall){
    std::vector<Car> cars;

    for(int i = 0; i<10; i++)
    {
        Car one;
        cars.push_back(one);
    }
    
    std::thread engine(EngineInstallerVect, std::ref(cars));
    std::thread frame(FrameInstallerVect, std::ref(cars));
    std::thread tire(TireInstallerVect, std::ref(cars));

    engine.join();
    frame.join();
    tire.join();

    for(Car c: cars)
    {
        ASSERT_TRUE(&c.engine != NULL);
        ASSERT_TRUE(&c.frame != NULL);
        ASSERT_TRUE(&c.tire!= NULL);
        ASSERT_TRUE(c.tire.size()==4) << c.tire.size() << " Number of tires";
    }
};

// Fixture, contains 100 default cars
// use Test_F(Inventory, Test-name) to use

class Inventory: public ::testing::Test 
{
    protected:
        std::vector<Car> cars;
        std::vector<Car> shuffled_cars;

        virtual void SetUp()
        { 
            for(int i = 0; i<100; i++)
            {
                Car c;
                c.price = 20000*(i+1);
                c.id = i;
                cars.push_back(c);
            }
            std::thread engine(EngineInstallerVect, std::ref(cars));
            std::thread frame(FrameInstallerVect, std::ref(cars));
            std::thread tire(TireInstallerVect, std::ref(cars));

            engine.join();
            frame.join();
            tire.join();

            for(Car c:cars)
            {
                shuffled_cars.push_back(c);
            }
            auto rng = std::default_random_engine {};
            std::shuffle(shuffled_cars.begin(), shuffled_cars.end(), rng);
        }    

        virtual void TearDown()
        {
            cars.clear();
        }
};

TEST_F(Inventory, init)
{
    for(int i = 0; i<cars.size(); i++)
    {
        ASSERT_EQ(cars[i].id, i) <<" Expected "<< i << " but actual is " << cars[0].id << " "; 
    }
};

// Recall new cars with a stack
TEST_F(Inventory, Stack_Recall)
{
    std::stack<Car> recall_stack;

    // Manufactured car records are stored in stack
    for(Car c : cars)
    {
        recall_stack.push(c);
    }

    // Recall last 3 cars
    for(int i = 0; i<3; i++)
    {
        Car c = recall_stack.top();
        ASSERT_EQ(c.id, cars.size()-1-i) << "Actual Car ID = " << c.id << ", Expected Car ID " << 5-i;
        recall_stack.pop();
    }
};

// Ship cars off the assembly line with a shipping queue
TEST_F(Inventory, Shipping_Queue)
{
    std::queue<Car> car_queue;

    // Order information is stored in a Queue
    for(Car c : cars)
    {
        car_queue.push(c);
    }

    std::stack<Car> delivered_list;

    // Track first 3 shipped cars
    for(int i = 0; i<3; i++)
    {
        delivered_list.push(car_queue.front());
        car_queue.pop();
        Car c = delivered_list.top();
        ASSERT_EQ(c.id, i) << "Actual Car ID = " << c.id << ", Expected Car ID " << i;

    }
};

// Sort Cars by their min price
TEST_F(Inventory, Heap_Sort)
{
    std::make_heap(shuffled_cars.begin(), shuffled_cars.end(), greater_than_car_price());
    ASSERT_EQ(shuffled_cars.front().price, 20000);
    pop_heap(shuffled_cars.begin(), shuffled_cars.end(), greater_than_car_price());
    ASSERT_EQ(shuffled_cars.front().price, 40000);
};

// Sort Cars by their min price
TEST_F(Inventory, Bubble_Sort)
{
    bubbleSort(shuffled_cars);
    ASSERT_EQ(shuffled_cars[0].id, 0) << "Expected 0 but found " << shuffled_cars[0].id;
    ASSERT_EQ(shuffled_cars[99].id, 99)<< "Expected 99 but found " << shuffled_cars[99].id;
    ASSERT_EQ(shuffled_cars[50].id, 50)<< "Expected 50 but found " << shuffled_cars[50].id;
};

TEST_F(Inventory, Insertion_Sort)
{
    insertionSort(shuffled_cars);
    ASSERT_EQ(shuffled_cars[0].id, 0) << "Expected 0 but found " << shuffled_cars[0].id;
    ASSERT_EQ(shuffled_cars[99].id, 99) << "Expected 99 but found " << shuffled_cars[99].id;
    ASSERT_EQ(shuffled_cars[50].id, 50) << "Expected 50 but found " << shuffled_cars[50].id;
};

TEST_F(Inventory, Linear_Search)
{
    Car a = linear_search(cars, 0);
    ASSERT_EQ(a.id, 0);

    Car b = linear_search(cars, 57);
    ASSERT_EQ(b.id, 57);

    Car c = linear_search(cars, 99);
    ASSERT_EQ(c.id, 99);
};

TEST_F(Inventory, Binary_Search)
{
    Car a = binarySearch(cars, cars.front().id, cars.back().id, 0);
    ASSERT_EQ(a.id, 0);

    Car b = binarySearch(cars, cars.front().id, cars.back().id, 57);
    ASSERT_EQ(b.id, 57);

    Car c = binarySearch(cars, cars.front().id, cars.back().id, 99);
    ASSERT_EQ(c.id, 99);
};

TEST(Shared_Lock, Reader)
{
    // create a shared resource 
    Car shared_resource;

    // create threads
    std::vector<std::thread> threads;

    for(int i = 0; i < 5; i++)
    {
        threads.push_back(std::thread(Validate, std::ref(shared_resource)));
    }

    // all validation threads can run at once, because they are read only with a shared lock
    for(std::thread &t : threads)
    {
        t.join();
    }

    // No errors from multiple threads acting on the same shared resource
    // Test passes
};

TEST(Scoped_Lock, deadlock_prevention)
{
    // Scoped locks are utilized to prevent deadlock from occuring
    // locks multiple threads without deadlock

    std::vector<std::thread> threads;
    for (int i = 0; i < 10; i++) 
    {
        threads.push_back(std::thread(no_dead_lock));
    }

    for (std::thread &t : threads) 
    {
        t.join();
    }
    // No system deadlock or exceptions
    // code passes
}
TEST (IDIncrement, lock_guard)
{ 
    std::vector <std::thread> threads;
    for(int i = 0; i < 100; i++)
    { 
        threads.push_back(std::thread(IDIcrement)); 

    } 
    for(std::thread &t : threads){ 
        t.join(); 
    }
}

TEST (unique_Increment, unique_lock)
{ 
    std::vector<std::thread> threads; 
    for(int i = 0; i< 100; i++)
    { 
        threads.push_back(std::thread(unique_Increment));
    }
    for(std::thread &t: threads)
    { 
        t.join(); 
    }
}
// Lock MIKAE
// Unlock MIKAE
// Std::Lock_guard <std::mutex>  // Talk about RAII  Usman 
// Std::Unique_lock                       // writer	Usman
// Std::Shared_lock                       // reader   Mehraj
// Std:: scoped_lock 		  // clean lock Mehraj 
// Conditional Variable
// Std::conditional_variable   MIKAE 