#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  vector t(n, vector(n, 0));
  cin >> t;
  V<int> ord(n);
  iota(all(ord), 0);
  int ans = 0;
  do {
    int dist = 0;
    rep(i, n - 1) dist += t[ord[i]][ord[i + 1]];
    dist += t[ord.back()][0];
    if (dist == k) ++ans;
  } while (next_permutation(ord.begin() + 1, ord.end()));
  wt(ans);
}
