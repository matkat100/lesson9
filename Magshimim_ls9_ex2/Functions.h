#ifndef FUNCTIONS_H
#define FUNCTIONS_H
using namespace std;

template <typename T> int compare(const T& a, const T& b)
{
    if (a > b)
    {
        return 1;
    }
    else if (a < b) 
    {
        return -1;
    }
    else 
    {
        return 0;
    }
}

template <typename T> int bubbleSort(T& arr, const T& size)
{
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

#endif 
