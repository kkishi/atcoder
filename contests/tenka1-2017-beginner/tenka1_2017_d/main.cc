#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  int ans = 0;
  rep(i, n) if ((a[i] | k) == k) ans += b[i];

  rep(i, 30) {
    int u = (k >> i) << i;
    u &= u - 1;
    int um = (((1 << 30) - 1) >> i) << i;
    if ((um & k) == 0) break;
    int sum = 0;
    // dbg(bitset<30>(u).to_string());
    // dbg(bitset<30>(um).to_string());
    rep(j, n) if (((a[j] & um) | u) == u) sum += b[j];
    // dbg(sum);
    chmax(ans, sum);
  }
  wt(ans);
}
