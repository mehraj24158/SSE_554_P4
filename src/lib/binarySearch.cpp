#include "binarySearch.hpp"
using namespace std; 

// binarySearch(cars, cars.front().id, cars.back().id, 0)

Car binarySearch(vector<Car> cars, int l, int r, int id)
{   
    if (r >= l) 
    {
        int mid = l + (r - l) / 2;
  
        // If the element is present at the middle
        // itself
        if (cars[mid].id == id)
            return cars[mid];
  
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (cars[mid].id > id)
            return binarySearch(cars, l, mid - 1, id);
  
        // Else the element can only be present
        // in right subarray
        return binarySearch(cars, mid + 1, r, id);
    }
  
    // We reach here when element is not
    // present in array
    Car notFound;
    notFound.id = 10000;
    return notFound;
}