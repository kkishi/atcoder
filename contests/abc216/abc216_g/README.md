# 典型要素

* 双対
* 牛ゲー
* 数列をグラフとしてみる

# 解説

[公式](https://atcoder.jp/contests/abc216/editorial/2474)

# 解法

天下り的だが、以下の変形をする。

* 0を最大化する(双対)
* Aの0と1を反転した数列A'を考え、A'の累積和である数列Bを考える

すると、問題の制約から以下の不等式が成り立つ必要がある。それぞれ牛ゲーの不等式の形をしているので、最短経路問題に帰着される。Bの添字に対応したn+1個の点を持つグラフにおいて、0からnに向かう最短距離を求めればよい。

* `L R X` ⇒ `B[R]-B[L-1] <= R-(L-1)-X` ⇒ L-1からRに長さR-(L-1)-Xの辺をはる
* `B[i]<=B[i+1]` ⇒ `B[i]-B[i+1] <= 0` ⇒ i+1からiに長さ0の辺をはる
* `B[i+1]<=B[i]+1` ⇒ `B[i+1]-B[i] <= 1` ⇒ iからi+1に長さ1の辺をはる

# 補足

牛ゲー自体は負辺があっても良いが、その場合はBellman–Ford法を使うなどする必要がある。今回は負辺が無いので、ダイクストラ法が使える。

1の最小化 ⇔ 0の最大化 ⇔ 最短経路問題 と双対を2回使うのが面白い。