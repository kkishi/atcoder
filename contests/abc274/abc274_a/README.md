# 典型要素

有理数の丸め

# 解法１・round

`round(x*1000)/1000`

TODO: 正しい理由

# 解法２・format指定子

`printf("%.3f", x);`もしくは`cout << fixed << setprecision(3) << x;`

TODO: 正しい理由

# 解法３・整数

`(10000*b/a+5)/10`
