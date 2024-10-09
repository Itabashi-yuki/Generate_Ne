#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "Gen_Ne.h"

void combine_IRI_FIRI(float *Ne_IRI, float *Ne_FIRI, int Year, int Month, int Day, int Hour, int Min){
    int FIRI_lower = int(iono_lower);
    int IRI_lower = int(iono_lower);
    int int_iono_upper = int(iono_upper);

    double *Ne_inter = new double[int_iono_upper];

    int FIRI_idx = interpolation_min - FIRI_lower;
    int IRI_idx = interpolation_min - IRI_lower;

    for(int i = FIRI_idx; i <= interpolation_max - FIRI_lower; i++){
        int idx = i - (interpolation_min - FIRI_lower);
        Ne_inter[i] = pow(10,( (interpolation_range - idx) * log10(Ne_FIRI[FIRI_idx + idx]) 
                                + idx * log10(Ne_IRI[IRI_idx + idx]) ) / interpolation_range);
    }

    for(int i = 0; i <= interpolation_min - FIRI_lower; i++){
        Ne_inter[i] = Ne_FIRI[i];
    }

    for(int i = interpolation_max - FIRI_lower + 1; i <= int_iono_upper - FIRI_lower; i++){
        int idx = i - (interpolation_min - FIRI_lower);
        Ne_inter[i] = Ne_IRI[IRI_idx + idx];
    }

    std::ofstream ofs("./data/Ne_UT" + transform_HHmm(Hour, Min) + ".dat");
    ofs << "#lat: " << lat << ", lon:" << lon << ", YYYYMMDD:" << transform_YYYYMMDD(Year, Month, Day) << std::endl;
    for (int i = 0; i <= int_iono_upper - FIRI_lower; i++) {
        ofs << FIRI_lower + i << " " << Ne_inter[i] << std::endl;
    }

    delete [] Ne_inter;

}
