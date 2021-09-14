# 解法

ある葉でゲームが終わるとすると結果はある一意の整数に定まる。それぞれの葉に対応する値はDFSを一度すると求まるので、それを用いてDPをすればよい。

multisetの中央値を求めるには例えば以下の方法がある。

* multisetを二つ持ち、それぞれのサイズが均等になるように調整しながら、片方には小さい値・もう片方には大きい値が入るようにする。
* `__gnu_pbds::tree::find_by_order`を使う。
* Binary Trie (Bitwise Trie)を使う。

# 備考

[cLayのtwoMultisets構造体](https://atcoder.jp/contests/abc218/submissions/25757951)が興味深い。中央値だけでなく、一般にK番目に大きい値を取得できる。insertではmultisetのサイズを調整しないが、K番目の値の取得時に小さい方を担当するmultisetのサイズをKにする。Kが単調に変化するなら計算量を小さく保てる。
