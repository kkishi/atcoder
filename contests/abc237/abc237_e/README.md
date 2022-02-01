# 典型要素

* ダイクストラ法
* ポテンシャルによる負辺の除去

# 解説

楽しさを-1倍すると、負の辺があり負の閉路はないグラフにおける単一始点最短経路を求める問題になる。一般的にはBellman-Ford法を用いる必要があるが、今回の制約では間に合わない。そこで、ポテンシャルを用いて負辺を除去し、Dijkstra法を用いる事を考える。

一般的に、ポテンシャルは[Johnson's Algorithm](https://en.wikipedia.org/wiki/Johnson%27s_algorithm)で求まるが、これもBellman-Ford法を用いる必要があり、間に合わない。そこで、この問題特有の構造を利用する。天下り的ではあるが、高さの-1倍が実行可能ポテンシャルとなっている。

# 備考

ポテンシャルによる負辺の除去に関しては[\[Tutorial\] Graph Potentials, Johnson's Algorithm, and Min Cost Max Flow](https://codeforces.com/blog/entry/95823)が分かりやすい。負辺がある最小費用流問題において増加路を求めるときに、計算量を改善する文脈で用いられる。
