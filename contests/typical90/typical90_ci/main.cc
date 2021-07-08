#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "warshall_floyd.h"

void Main() {
  ints(n, p, k);
  vector a(n, vector(n, int(0)));
  cin >> a;
  auto calc = [&](int x) {
    vector d = a;
    rep(i, n) rep(j, n) if (d[i][j] == -1) d[i][j] = x;
    WarshallFloyd(d);
    int cnt = 0;
    rep(i, n) rep(j, i + 1, n) if (d[i][j] <= p)++ cnt;
    return cnt;
  };
  if (calc(p + 1) == k) {
    wt("Infinity");
    return;
  }
  int H = BinarySearch<int>(1, p + 1, [&](int x) { return calc(x) >= k; });
  if (calc(H) != k) {
    wt(0);
    return;
  }
  int L = BinarySearch<int>(H, 0, [&](int x) { return calc(x) == k; });
  wt(H - L + 1);
}
