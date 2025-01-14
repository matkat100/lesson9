#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

template <typename T>
int compare(const T& a, const T& b) 
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

template <typename T>
void bubbleSort(T arr[], const int size)
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>

void printArray(const T arr[], const int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

#endif
