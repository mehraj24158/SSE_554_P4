#include "linearSearch.hpp"
using namespace std; 


Car linear_search(vector<Car> cars, int id)
{  
    for (int i = 0; i<cars.size(); i++)
    {
        if(cars[i].id == id)
            return cars[i]; 
    }

    Car notFound;
    notFound.id = 10000;
    return notFound;
}



