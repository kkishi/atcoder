#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<string> a(n);
  cin >> a;
  const int N = 3000;
  V<bitset<N>> b(n);
  rep(i, n) rep(j, i) b[i][j] = a[i][j] - '0';
  int ans = 0;
  rep(i, n) rep(j, i) if (a[i][j] == '1') ans += (b[i] & b[j]).count();
  wt(ans);
}
