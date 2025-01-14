#include "BSNode.hpp"
#include <iostream>
#include <string>

int main()
{
    int intArr[15] = { 6, 2, 8, 3, 5, 9, 6, 1, 7, 4, 10, 12, 15, 14, 13 };
    std::string strArr[15] = { "apple" , "cherry", "banana",  "date", "grape", "fig", "honeydew", "kiwi", "lemon", "mango", "elderberry","nectarine", "orange", "pear"};
    std::cout << "Array ints: ";
    for (int i = 0; i < 15; ++i) 
    {
        std::cout << intArr[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Array strings: ";
    for (int i = 0; i < 15; ++i) 
    {
        std::cout << strArr[i] << " ";
    }
    std::cout << "\n";
    BSNode<int> bs(intArr[0]);
    for (int i = 1; i < 15; ++i) 
    {
        bs.insert(intArr[i]);
    }
    BSNode<std::string> bs2(strArr[0]);
    for (int i = 1; i < 15; ++i) 
    {
        bs2.insert(strArr[i]);
    }
    std::cout << "Sorted ints tree: ";
    bs.printNodes();
    std::cout << "\n";
    std::cout << "Sorted strings tree: ";
    bs2.printNodes();
    std::cout << "\n";
    return 0;
}
