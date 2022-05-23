#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<string> s(n);
  cin >> s;
  int ans = big;
  rep(i, 10) {
    int t = 0;
    V<bool> done(n);
    int cnt = 0;
    while (true) {
      rep(j, n) {
        if (done[j]) continue;
        if (s[j][t % 10] - '0' == i) {
          done[j] = true;
          ++cnt;
          break;
        }
      }
      if (cnt == n) break;
      ++t;
    }
    chmin(ans, t);
  }
  wt(ans);
}
