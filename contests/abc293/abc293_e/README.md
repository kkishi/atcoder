## 典型要素

* $q|p$ のとき $p/q\ mod\ N = (p\ mod\ Nq)/q$
* 二分累乗法
* 行列累乗
* 平方分割

## 解法

### 数論 (main.cc)

$S_n = (A^X-1)/(A-1)$ だが、 $A-1$ が $M$ と互いに素でない場合が問題になる。通常なら割り算を使わない他の解法を考えることになるが、今回は特殊な制約から上手く計算できる([参照](http://techtipshoge.blogspot.com/2015/02/mod-n.html))。

### 二分累乗法 (main_doubling.cc)

式を観察すると、nが偶数の時に以下の変形ができることを利用する。

$S_n = A^0 + A^1 + ... + A^{n-1}$

$= A^0 + A^1 + ... + A^{n/2-1} + A^{n/2} \times (A^0 + A^1 + ... + A^{n/2-1})$

$= S_{n/2} + A^{n/2} \times S_{n/2}$

$= S_{n/2} \times (1 + A^{n/2})$

### 行列累乗 (main_matrix.cc)

漸化式を考えると $S_{n+1} = S_n \times A + 1$ となる。これは右辺に定数があって一見行列積で表せないように感じるが、アフィン変換と同じようなテクニックを使って行を一つ追加すると可能になる([参照](https://atcoder.jp/contests/abc293/editorial/5955))。

### 平方分割

漸化式 $S_{n+1} = S_{n} \times A + 1$ を $\sqrt{X}$ 項ごとに分割し計算する。最初の $\sqrt{X}$ (端数切り捨て)ステップは愚直に計算し、その結果を $S$ とする。 それを利用し、 $ans = 0$ から始めて $ans = ans \times A^{\sqrt{X}} + S$ と一度に $\sqrt{X}$ ステップ分計算することを $\sqrt{X}$ 回繰り返す。最後に端数 $X - \sqrt{X}^2$ ステップを愚直に計算する( $ans = ans \times A + 1$ )。

## 備考

数論解で`atcoder::modint`を使おうとして色々と困ったのでメモ。

* 合成数をmodとすること自体は可能だが、 $x / y\ mod\ m$ を計算するとき $y$ は $m$ と互いに素である必要がある。そうでないときは[このassert](https://github.com/atcoder/ac-library/blob/3c37e9147cd1a9038483125077ba57a8449c4c3a/atcoder/modint.hpp#L222)で落ちる。これは $x$ が $y$ で割り切れる状況でも要求されることに注意。
* `void atcoder::modint::set_mod(int m)`は $1 \leq m \leq 2 \times 10^9 + 1000$ の制約があるので、今回のように大きなmodを使う場合に問題となる。
