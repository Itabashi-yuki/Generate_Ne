# doy   : Day of Year 1-365 
# chi   : 太陽天頂角 0-130[deg]
# lat   : 緯度 0-60[deg]
# f10_7 : F10.7 75-200

from pyfiri.firi import firi2018
import numpy as np
import sys

input_filename = 'input_tmp.dat'

with open(input_filename, 'r') as file:
    line = file.readline().strip()
    date, doy, chi, lat, f10_7 = map(float, line.split())

# FIRIモデルの初期化とデータ取得
model = firi2018()

profile = model.get_profile(doy=doy, chi=chi, lat=lat, f10_7=f10_7)
data = profile.values

# データを1次元に変換
data_1d = data.flatten()

# 高度の列の値を生成（55.0から150.0まで1.0ずつ増加）
column1 = np.arange(55.0, 151.0, 1.0)
combined_data = np.column_stack((column1, data_1d))

filename = './data/FIRI.dat'

# ヘッダーの作成
header = f'# YYYYMMDDHHmm: {date} DOY: {doy}, CHI: {chi}, LAT: {lat}, F10.7: {f10_7}\n'

with open(filename, 'w') as file:
    file.write(header)  # ヘッダーの書き込み
    np.savetxt(file, combined_data, fmt=['%.1f', '%e'], delimiter=' ', header='', comments='')

