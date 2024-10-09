#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string transform_YYYYMMDD(int Year, int Month, int Day){
    std::string YYYY = std::to_string(Year);
    std::string MM = std::to_string(Month);
    std::string DD = std::to_string(Day);

    MM.insert(0,2 - MM.length(), '0');
    DD.insert(0,2 - DD.length(), '0');

    return YYYY + MM + DD;
}

std::string transform_HHmm(int Hour, int Min){
    std::string HH = std::to_string(Hour);
    std::string mm = std::to_string(Min);

    HH.insert(0,2 - HH.length(), '0');
    mm.insert(0,2 - mm.length(), '0');

    return HH + mm;
}

double output_f10_7(int Year, int Month, int Day){
    int f107_lines {28085};
    std::ifstream ifs("f107.dat");
    std::string Data_YYYYMMDD[f107_lines];
    double f107_value[f107_lines];
    
    std::string input_YYYYMMDD = transform_YYYYMMDD(Year, Month, Day);
    std::cout << input_YYYYMMDD << std::endl;

    double output_value = 0;
    std::string line;
    for(int i = 0; i < f107_lines; i++){
        std::getline(ifs, line);
        std::istringstream iss(line);
        iss >> Data_YYYYMMDD[i];

        double check_value;
        if(iss >> check_value){
            f107_value[i] = check_value;
        } else {
            f107_value[i] = f107_value[i-1];
        }

        if( Data_YYYYMMDD[i] == input_YYYYMMDD){
            output_value = f107_value[i];
            break;
        }
    } 

    return output_value;
}