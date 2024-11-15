#include <iostream>
#include <cstring>

int main(){
    unsigned char arr[5] = {1, 2, 3, 4, '\0'};
    std::cout << "Size of arr: " << sizeof(arr) << std::endl;
    std::cout << "Length of arr: " << strlen((char*)arr) << std::endl;
    return 0;
}