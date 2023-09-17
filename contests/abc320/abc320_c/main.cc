#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(m);
  V<string> s(3);
  cin >> s;
  int ans = big;
  rep(i, m) rep(j, m) rep(k, m) if (s[0][i] == s[1][j] && s[1][j] == s[2][k]) {
    V<int> v = {i, j, k};
    sort(v);
    do {
      int t = -1;
      each(e, v) {
        ++t;
        int rem = t % m;
        if (e < rem) {
          t += m - rem;
          rem = 0;
        }
        t += e - rem;
      }
      chmin(ans, t);
    } while (next_permutation(all(v)));
  }
  if (ans == big) ans = -1;
  wt(ans);
}
