#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  int N = n;
  auto F = [](int n, int m) {
    if (n < m) return int(0);
    int p = 1, q = 1;
    rep(i, m) {
      p *= n - i;
      q *= m - i;
      int g = gcd(p, q);
      p /= g;
      q /= g;
    }
    assert(q == 1);
    return p;
  };
  auto C = [&F, &N](int n, int m) {
    int f = F(n, m);
    int ng = 0;
    ng += F(n - N, m) * 3;
    ng -= F(n - N * 2, m) * 3;
    return f - ng;
  };
  int x = 3;
  while (true) {
    int cnt = C(x - 1, 2);
    if (cnt >= k) break;
    k -= cnt;
    ++x;
  }
  dbg(x, k);
  int I = 1;
  chmax(I, x - 2 * n);
  dbg(I);
  while (true) {
    // int cnt = F(x - I - 1, 1);
    int cnt;
    {
      int J = 1;
      int K = x - (I + J);
      dbg(J, K);
      if (K > n) {
        J += K - n;
        K = n;
      }
      cnt = (K - J) + 1;
    }
    // dbg(I, cnt);
    if (cnt >= k) break;
    k -= cnt;
    ++I;
  }
  int J = 1;
  int K = x - (I + J);
  if (K > n) {
    J += K - n;
    K = n;
  }
  J += k - 1;
  K -= k - 1;
  wt(I, J, K);
}
