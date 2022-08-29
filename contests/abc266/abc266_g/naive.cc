#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(r, g, b, k);
  string s = string(r, 'R') + string(g, 'G') + string(b, 'B');
  sort(s);
  int ans = 0;
  do {
    int cnt = 0;
    rep(i, sz(s) - 1) if (s[i] == 'R' && s[i + 1] == 'G')++ cnt;
    if (cnt == k) ++ans;
  } while (next_permutation(all(s)));
  wt(ans);
}
