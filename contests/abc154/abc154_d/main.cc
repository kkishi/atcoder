#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(N, K);
  V<int> p(N);
  cin >> p;
  auto exp = [&p](int i) { return p[i] * (p[i] + 1) / 2 / (double)(p[i]); };
  double sum = 0;
  rep(i, K) sum += exp(i);
  double ans = sum;
  rep(i, K, N) {
    sum -= exp(i - K);
    sum += exp(i);
    chmax(ans, sum);
  }
  wt(ans);
}
