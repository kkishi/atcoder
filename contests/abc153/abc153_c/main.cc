#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(N, K);
  V<int> H(N);
  cin >> H;
  sort(all(H));
  int ans = 0;
  rep(i, N - K) ans += H[i];
  wt(ans);
}
