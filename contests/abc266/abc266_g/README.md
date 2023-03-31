## 典型要素

* 連続する必要のある複数要素をまとめて一要素に言い換える
* 挿入する順序を工夫する
* 包除原理（対称性に着目して $O(2^N)$ を $O(N)$ にする)

## 解法

どちらの解法でもまず連続するRGを表すXという文字がK個あると言い換える。RとGはKずつ減らす。

### 挿入する順序を工夫(main.cc)

始めにRBXを並べる。これらは自由に並べられ、[同じものを含む順列](https://examist.jp/mathematics/baainokazu/onajimono-jyunretu/)として $(R+B+X)!/(R! \times B! \times X!)$ で数えられる。並べた結果のXをRGに戻したRGB列から元のRBX列が一意に定まる事に注意。

次にGをRの右を避けるようにして挿入する。G個の区別できないものをB+X+1箇所から選んで挿入するので、重複組み合わせのようにしてG個のボールをB+X個の仕切りで区切ると考えて ${ {B+X+G} \choose {B+X} }$ で数えられる。ここでも並べた結果のRGB列から元のRGBX列が一意に定まる事に注意。

### 包除原理(main_iep.cc)

Xを作った後に余ったRとGからRGが一つも作られない並べ方を数えたい。これは、全体(全てのありうるRGBX列(元のRGB列でない事に注意))から余事象(1つ以上RGがある)を引けばよい。

余事象を求めるには包除をする。RGBX列のうち「i個目の要素がRでi+1個目の要素がG」を満たす文字列の集合 $A_i$ を考えて、これらの和集合を求めればよい。

これを素朴に包除しようとすると以下が問題になる。

* $A_i$ の積集合は $2^{R+G+B+X-1}$ 通りあるので、間に合わない。
* i番目とi+1番目の条件が独立してないので、「j箇所をRGと決め、他は自由に並べる方法をまとめて数える」などをするのが難しい。

ここで以下の事実を利用する。

> 「j箇所をRGと決め、他は自由に並べる方法」の数は、「新たに文字Yをj個作りRGをそれぞれj個ずつ減らして出来たRGBXY列を自由に並べる」数に等しい。

これは前者の各並び方に対応する後者が存在することから分かる。以上から「Aをi個選んで作られる積集合の要素数」がO(1)で求まり、包除が間に合う。

#### 具体例

R=3, G=3, B=0, K=1 の場合を具体的に示す。RGB列の並べ方は $6!/(3! \times 3!) = 20$ 通りあり、そのうち条件を満たすのは9通りある。

| RGB列  | i=RG? | o |
|--------|-------|---|
| GGGRRR | xxxxx | 0 |
| GGRGRR | xxoxx | 1 |
| GGRRGR | xxxox | 1 |
| GGRRRG | xxxxo | 1 |
| GRGGRR | xoxxx | 1 |
| GRGRGR | xoxox | 2 |
| GRGRRG | xoxxo | 2 |
| GRRGGR | xxoxx | 1 |
| GRRGRG | xxoxo | 2 |
| GRRRGG | xxxox | 1 |
| RGGGRR | oxxxx | 1 |
| RGGRGR | oxxox | 2 |
| RGGRRG | oxxxo | 2 |
| RGRGGR | oxoxx | 2 |
| RGRGRG | oxoxo | 3 |
| RGRRGG | oxxox | 2 |
| RRGGGR | xoxxx | 1 |
| RRGGRG | xoxxo | 2 |
| RRGRGG | xoxox | 2 |
| RRRGGG | xxoxx | 1 |

次にRGBX列で考える。並べ方は $5!/(2! \times 2! \times 1!) = 30$ 通りある。

| RGBX列| i=RG?| o|
|-------|------|---|
| GGRRX | xxxx | 0 |
| GGRXR | xxxx | 0 |
| GGXRR | xxxx | 0 |
| GRGRX | xoxx | 1 |
| GRGXR | xoxx | 1 |
| GRRGX | xxox | 1 |
| GRRXG | xxxx | 0 |
| GRXGR | xxxx | 0 |
| GRXRG | xxxo | 1 |
| GXGRR | xxxx | 0 |
| GXRGR | xxox | 1 |
| GXRRG | xxxo | 1 |
| RGGRX | oxxx | 1 |
| RGGXR | oxxx | 1 |
| RGRGX | oxox | 2 |
| RGRXG | oxxx | 1 |
| RGXGR | oxxx | 1 |
| RGXRG | oxxo | 2 |
| RRGGX | xoxx | 1 |
| RRGXG | xoxx | 1 |
| RRXGG | xxxx | 0 |
| RXGGR | xxxx | 0 |
| RXGRG | xxxo | 1 |
| RXRGG | xxox | 1 |
| XGGRR | xxxx | 0 |
| XGRGR | xxox | 1 |
| XGRRG | xxxo | 1 |
| XRGGR | xoxx | 1 |
| XRGRG | xoxo | 2 |
| XRRGG | xxox | 1 |

素朴に包除すると、

$A_1 = \\{RGGRX, RGGXR, RGRGX, RGRXG, RGXGR, RGXRG\\}$ `o???`

$A_2 = \\{GRGRX, GRGXR, RRGGX, RRGXG, XRGGR, XRGRG\\}$ `?o??`

$A_3 = \\{GRRGX, GXRGR, RGRGX, RXRGG, XGRGR, XRRGG\\}$ `??o?`

$A_4 = \\{GRXRG, GXRRG, RGXRG, RXGRG, XGRRG, XRGRG\\}$ `???o`

$A_1 \bigcup A_2 = \\{\\}$ `oo??`

$A_1 \bigcup A_3 = \\{RGRGX\\}$ `o?o?`

$A_1 \bigcup A_4 = \\{RGXRG\\}$ `o??o`

$A_2 \bigcup A_3 = \\{\\}$ `?oo?`

$A_2 \bigcup A_4 = \\{XRGRG\\}$ `?o?o`

$A_3 \bigcup A_4 = \\{\\}$ `??oo`

から

$余事象 = 6+6+6+6-(0+1+1+0+1+0) = 21$

従って、 $全体-余事象=30-21=9$

最後にまとめて数えられる事を確認する。

* Aから1つ選んだ積集合の要素数の和: RGXYの並び替えで24通り
* Aから2つ選んだ積集合の要素数の和: XYYの並び替えで3通り

## 備考

`RGがK個以上ある`のような除原理だと解くのは難しい。
