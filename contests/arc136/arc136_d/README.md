# 典型要素

* 多次元累積和
* 包除原理
* 高速ゼータ変換

# 解法

次のような6次元累積和を効率良く計算できればよい:

`sum[i][j][k][l][m][n] = 1桁目がi以下、2桁目がj以下、…であるような要素の数`

## [解法1](main.cc):

二次元の場合と同様に、包除原理を用いて累積和を計算する。おそらく想定解ではないが実際は間に合う。

参考:
* <https://twitter.com/googol_S0/status/1497936324065918976>
* <https://twitter.com/toku4388/status/1497942385388851203>

## [解法2](main_zeta.cc):

高速ゼータ変換をする。[ゼータ変換・メビウス変換を理解する](https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5)が分かりやすい。

参考:
* <https://twitter.com/googol_S0/status/1497936324065918976>
