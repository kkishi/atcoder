# 典型要素

* オイラーツアーを用いた木DP
* マージテク

# 解法

余事象を数える。それぞれの色について、その色以外の点からなる部分木のそれぞれの大きさがわかればよい。

1を根とする根付き木として考える。それぞれの点iについて、iの子それぞれと連結する、iと異なる色からなる部分木のサイズを求めたい。これは次の量を考えると再帰的に計算できる。

* `size[i]`: iを根とする部分木の大きさ
* `dp[i][j]`: iを根とする部分木に含まれる点であって、色jである点を祖先に持つ点の数

dpを効率よく計算するには次の方法がある。

## マージテク

一度のDFSで全ての色についてdpを計算する。dpはmapで管理しマージテクで併合すればよい。

## オイラーツアー

色ごとにdpを計算する。オイラーツアーを用いると、直接繋がっていない点集合に関して木DPができる。

# 備考

サイズnの木上の単純パスの数は、u<=vを満たすペアu,vの数と一致するため、`n*(n+1)/2`。

オイラーツアーの結果を用いると、`size[node]`は`out[node]-in[node]`で求まる。

オイラーツアーを用いて木DPをするとき`in[node]`でトポロジカルソートできる。
