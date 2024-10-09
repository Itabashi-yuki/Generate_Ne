# IRIとFIRIを用いた電離圏電子密度分布の取得プログラム
## 必要なライブラリ
* [AndoLab_Library](https://github.com/yoshiaki-ando/AndoLab_Library)
* [IRI2016_Cpp_Wrapper](https://github.com/yoshiaki-ando/IRI2016_Cpp_Wrapper)
* [solar-angle](https://github.com/yoshiaki-ando/solar-angle)
* [pyFIRI](https://github.com/ElsevierSoftwareX/SOFTX-D-21-00148)

## 説明
IRI(International Reference Ionosphere)とFIRI(Faraday International Reference Ionosphere)を組み合わせた電離圏電子密度分布を取得するプログラム．
下部電離圏をFIRIの分布，それより上部をIRIの分布とした分布を出力する.  
FIRIはdoy(day of year)，太陽天頂角，緯度，f10.7が引数．  
IRIは日時，緯度，経度が引数.

## 使い方
1. Year, Month, Day, Hour, MinをUTCで入力 (入力例:2024 10 9 7 5)
2. data/ ディレクトリ内にIRI.dat, FIRI.dat, Ne_****.datが作成される． 
