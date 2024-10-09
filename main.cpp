#include <iostream>
#include <fstream>
#include <string>
#include <solar_direction.h>
#include "Gen_Ne.h"

int main(){
    int Year, Month, Day, Hour, Min;
    int Doy;
    double Double_Hour;

    /* 日付の入力, 各表記方法に変換 */
    input(Year, Month, Day, Hour, Min);
    Doy = MMDD_to_Doy(Month, Day);
    Double_Hour = Hour + Min / 60.0;

    /* 太陽天頂角，方位角の計算 */
    double zenith, azim;
    AndoLab::solar_direction(lat, lon, Doy, Double_Hour, &zenith, &azim);

    double f10_7 = output_f10_7(Year, Month, Day);
    std::ofstream ofs_tmp("input_tmp.dat");
    ofs_tmp << transform_YYYYMMDD(Year, Month, Day) + "_" + transform_HHmm(Hour, Min) << " " << Doy << " " << zenith << " " << lat << " " << f10_7 << std::endl;
    ofs_tmp.close();
    /* IRIによる電子密度分布の取得 */
    float *Ne_IRI = new float [Nr_iono];
    Gen_IRI(Ne_IRI, Year, Month, Day, Hour, Min);

    /* FIRIによる電子密度分布の取得 */
    /* main_firi.pyを実行して得られたdatファイルから取得 */
    std::system("python3 main_firi.py");
    float *Ne_FIRI = new float [Nr_iono];
    float *Alt_FIRI = new float [Nr_iono];

    std::ifstream ifs_FIRI("data/FIRI.dat");
    std::string line;
    std::getline(ifs_FIRI, line); /* headerを読み飛ばす */
    for(int i = 0; i < Nr_iono; i++){
        ifs_FIRI >> Alt_FIRI[i] >> Ne_FIRI[i];
    }

    combine_IRI_FIRI(Ne_IRI, Ne_FIRI, Year, Month, Day, Hour, Min);

    return 0;
}