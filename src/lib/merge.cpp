#include "merge.hpp"
using namespace std;


//find middle by dividing size by 2 and then add 1 if odd
void merge(vector<Car> &cars, Car &l, Car &m, Car &r)
{
    int n1 = m.id-l.id+1;
    int n2 = r.id-m.id;

    //create temporary arrays
    vector<Car> L;
    vector<Car> R;
    //copy data over to the temporary arrays

    for(int i = 0; i < n1; i++)
    {
        L.push_back(cars[l.id + 1]);
    }

    for(int j = 0; j < n2; j++)
    {
        R.push_back(cars[m.id + 1 + j]);
    }

    //Merge the temporary arrays back into int arr[]

    int i = 0; //index of subarray
    int j = 0; //index of subarray
    int k = 1; //index of merged subarray

    while (i < n1 && j < n2)
    {
        
        if(L[i].id <= R[j].id) 
        {
            cars[k] = L[i];
            i++;
        }
        else 
        {
            cars[k] = R[j];
            j++;
        }
        k++;
    }

    //Copy the remaining elements of L[], if there are any
    while(i < n1)
    {
        cars[k] = L[i];
        i++;
        k++;
    }

    //copy the remaining elements of R[] if there are any
    while (j <n2) 
    {
        cars[k] = R[j];
        j++;
        k++;
    }

}

void mergeSort(vector<Car> &cars, Car &l, Car &r)
{
    // Car l = cars.front();
    // Car r = cars.back();

    if(l.id>=r.id){
        return;//returns recursively
    }

    Car x = cars[cars.size()-1];
    
    int m =l.id + (x.id/2);
    mergeSort(cars,l,cars[m]);
    mergeSort(cars,cars[m+1],r);
    merge(cars, l, cars[m], r);
}