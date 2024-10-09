#include <iostream>
#include "Gen_Ne.h"

void input(int &Year, int &Month, int &Day, int &Hour, int &Min){
    std::cout << "Year : ";
    std::cin >> Year;

    std::cout << "Month : ";
    std::cin >> Month;
    
    std::cout << "Day : ";
    std::cin >> Day;
    
    std::cout << "Hour : ";
    std::cin >> Hour;
    
    std::cout << "Min : ";
    std::cin >> Min;
    std::cout << std::endl;
}