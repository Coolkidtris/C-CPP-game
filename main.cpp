#include <iostream>

char name[256];

int main(){
    std::cout << "What is your name?\n";
    std::cin >> name;
    std::cout << "Hello," << name;
    return 0;
}