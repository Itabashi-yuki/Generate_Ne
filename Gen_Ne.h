#include <string>

/* えびの */
constexpr double lat { 32.067650 };
constexpr double lon { 130.828978 };
constexpr float iono_lower { 55.f };
constexpr float iono_upper { 300.f };
constexpr int FIRI_iono_upper { 150 };
const int Nr_iono { int(iono_upper) - int(iono_lower) };

constexpr int interpolation_min { 140 }; /*[km]*/
constexpr int interpolation_max { 150 }; /*[km]*/
const int interpolation_range {interpolation_max - interpolation_min};

void input(int &, int &, int &, int &, int &);
int MMDD_to_Doy(int Month, int Day);
void Gen_IRI(float *Ne, int, int, int, int, int);
void combine_IRI_FIRI(float *Ne_IRI, float *Ne_FIRI, int, int , int, int, int);
std::string transform_YYYYMMDD(int Year, int Month, int Day);
std::string transform_HHmm(int Hour, int Min);
double output_f10_7(int Year, int Month, int Day);