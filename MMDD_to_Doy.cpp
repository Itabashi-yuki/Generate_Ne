int MMDD_to_Doy(int Month, int Day){
    int Doy;
    /* 月始まりにおける累積日数(うるう年は考慮していない) */
    int Day_accum[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

    Doy = Day_accum[Month - 1] + Day;
    
    return Doy;
}