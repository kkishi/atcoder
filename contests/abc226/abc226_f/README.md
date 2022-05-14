# 典型要素

* 置換は巡回置換に分解される
* 分割数（計算量の見積もり）
* 全探索
* 組み合わせ

# 解法

置換の位数がスコアとなっている。これは、巡回置換に分解したときのサイズの最小公倍数となる。

それぞれの置換を、どのようなサイズの巡回置換に分解されるかで特徴づけることを考える。50の分割数は204226と小さいので、全ての場合を愚直に列挙できる。それぞれの場合について、そのように分割される置換の数を次のように数え上げる。

* `L_i`個のボールが入っている箱が`C_i`個ある。これは、長さ`L_i`のサイクルが`C_i`個あることと対応する。
* ボールは区別できる。また、同じ箱に入っているボールは円順列になっていて順序がある。
* 同じ大きさの箱は区別できない。

* ボールに番号をつける方法は全部でN!通りある。
* 箱が区別できないことによる重複を箱の大きさごとにC_i!で割り調整する。
* 同じ円順列による重複を箱ごとにL_iで割ることで調整する。