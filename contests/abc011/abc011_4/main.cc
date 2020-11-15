#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, d, x, y);
  x = abs(x);
  y = abs(y);
  if (x % d || y % d) {
    wt(0);
    return;
  }
  x /= d;
  y /= d;
  int z = n - (x + y);
  if (z < 0 || z % 2) {
    wt(0);
    return;
  }
  V<double> fact(n + 1);  // log of factorial
  rep(i, 1, n + 1) fact[i] = fact[i - 1] + log(i);
  double ans = 0;
  double denom = log(2) * 2 * n;  // log(4^n)
  for (int i = 0; i * 2 <= z; ++i) {
    int a = x + i;
    int b = i;
    int j = (z - i * 2) / 2;
    int c = y + j;
    int d = j;
    ans += exp(fact[n] - (fact[a] + fact[b] + fact[c] + fact[d]) - denom);
  }
  wt(ans);
}
