# 典型要素

累積和によるDPの高速化

# 解法

`dp[i] = Aの先頭i項からなる部分問題の解`とすると、O(N^2)でdp[n]が計算できる。さらにmaxの項とminの項とを分けて考えると、dp[i-1]の計算とdp[i]の計算とで共通している部分を再利用することでO(N)に高速化できる。
