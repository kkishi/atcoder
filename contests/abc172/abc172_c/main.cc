#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n, m, k);
  vector<int> a(n), b(m);
  cin >> a >> b;

  vector<int> sa(n + 1), sb(m + 1);
  rep(i, n) sa[i + 1] = sa[i] + a[i];
  rep(i, m) sb[i + 1] = sb[i] + b[i];

  int ans = 0;
  rep(i, n + 1) {
    int j =
        BinarySearch<int>(0, m + 1, [&](int x) { return k >= sa[i] + sb[x]; });
    if (k < sa[i] + sb[j]) break;
    chmax(ans, i + j);
  }
  wt(ans);
}
