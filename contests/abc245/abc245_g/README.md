# 典型要素

K最短路

# 解法

1番目と2番目に短い経路が計算できればよい。ダイクストラ法を少し工夫すると計算できる。良く使われる、キューに入れる時点で枝狩りをする実装だとやりづらいので、素朴な実装（キューから取り出した時点で弾く）から書き換えるとよい。