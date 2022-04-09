# 解法

操作1では転倒数が高々1増える。操作2は操作1の逆操作を繰り返すことで実現できるので、転倒している要素を覚えておいて、それぞれの操作2において必要なものを効率よく見つられればよい。

ここで転倒しているペア全てを素朴に整数の組で管理すると、与えられた区間に含まれる要素を効率よく見つけるのは難しい。そこで、次の事実を利用して転倒しているペアを巧妙に管理する。

*  隣り合う要素のペアであって転倒しているものの集合をSとする。
*  与えられた区間に含まれるSの要素は効率よく見つけられる。
*  隣り合う要素のペアをswapしたことによるSの変化は、Aの要素を高々4つ見ることで管理できる。