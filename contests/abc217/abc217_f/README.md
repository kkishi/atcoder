# 典型要素

* 区間DP
* 重複を防ぐ

# 解法

区間DPだが、良くある最適化ではなく数え上げなので、状態を重複して数えてしまわないように注意する必要がある。

## 解法1

f(l, r)を区間[l, r)に対する場合の数とする。以下の場合分けをしてより小さな問題に分割する。

* lとr-1がペアになる場合: f(l+1, r-1)を計算する。
* それ以外の場合: 必ずあるmがあって、lとmがペアになるとは限らないが、[l, m+1)と[m+1, r)の独立した区間(境界をまたぐような対は無い)に分割される。このとき、f(l, m+1)とf(m+1, r)は独立に計算できる。それぞれの計算結果をfL, fRとし、操作回数をcntL、cntRとすると、全体の値はfL * fR * (cntL + cntR) C cntR で計算できる。

一つ注意が必要で、[1 2] [3 4] [5 6]のようにペアを作れる場合、

* `f(1, 3) x f(3, 7)` => `f(1, 3) x f(3, 5) x f(5, 7)`
* `f(1, 5) x f(5, 7)` => `f(1, 3) x f(3, 5) x f(5, 7)`

のように重複して数えてしまう。これは、例えば「ある区間を分割してできた部分区間のうち、左側のものは、それ以上分割しない」というルールで回避できる。具体的にはf(l, r, isLeft)のようにbool引数を一つ足す。DP配列も3次元にすることに注意。

## 解法2 (公式解説)

f(l, r)を区間[l, r)に対する場合の数とする。lと最終的に対になる要素mを全て調べる。mを決めると、以下のより小さな問題に分割される。

* 左側区間: f(l+1, m) (l, mが取り除かれている事に注意)
* 右側区間: f(m+1, r)

計算結果の併合は解法1と同様。

解法1と違い、mを単に「区間が分割される地点」でなく、より強く「lと対になる要素」とすることで、重複が防がれる。

# 補足

サンプルが非常に弱いのでWAが出がち。MODを取るチェックすら無い。