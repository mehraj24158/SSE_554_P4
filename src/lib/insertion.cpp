#include "insertion.hpp"
using namespace std;


void insertionSort(vector<Car> &cars)
{
    int i, j;
    Car key;

    for (i = 1; i < cars.size(); i++)
    {
        key = cars[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && cars[j].id > key.id)
        {   
            cars[j+1] = cars[j];
            j = j - 1;
        }
        cars[j + 1] = key;
    }
}