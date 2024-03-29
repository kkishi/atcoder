## 解法

### 準備

$a$ と $b$ の最大公約数を $g$ とすると $a = p \times g$ 、 $b = q \times g$ と表される。操作を $x$ 回繰り返して $a = (p - x) \times g$ 、 $b = (q - x) \times g$ となったときに $g' = gcd(a,b) \neq g$ であるとすると、明らかに $g \mid g'$ である。従って常に $a, b$ の代わりに $p, q$ を用いてよい。

### 操作の高速化

一般に $gcd(p, q) = gcd(p, q - p)$ であり、 $q - p$ は操作によって変化しない事に注意すると、 $gcd(p, q)$ としてありうる数は $q - p$ の約数のみである。したがって、 $p$ を1ずつ減らしていくときどの約数ではじめに割り切れるかを全探索すればよい。またこの全探索では素因数を調べれば十分である。

### 計算量

最大公約数が変化するたびに $a, b$ が2以上の数で割られるため、 $O( \sqrt{N} log N)$ となる。
