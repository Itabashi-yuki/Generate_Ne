#include <iostream>
#include <fstream>
#include <iri2016.h>
#include "Gen_Ne.h"

void Gen_IRI(float *Ne, int Year, int Month, int Day, int Hour, int Min){
    AndoLab::iri2016 a;

    a.set_coord(lat, lon);
    a.set_datetime(Year, Month, Day, Hour, Min);
    a.set_height(iono_lower, iono_upper, 1.0f);

    a.get_Ne(Ne);

    std::ofstream ofs("data/IRI.dat");
    ofs << "#lat:" << lat << ", lon:" << lon << std::endl; 
    for(int i = 0; i < Nr_iono; i++){
        ofs << i+int(iono_lower) << " " << Ne[i] << std::endl;
    }
    ofs.close();
}