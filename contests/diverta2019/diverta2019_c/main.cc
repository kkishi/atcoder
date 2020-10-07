#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<string> s(n);
  cin >> s;
  int ans = 0;
  vector cnt(2, vector(2, 0));
  for (const string& si : s) {
    rep(i, sz(si) - 1) if (si[i] == 'A' && si[i + 1] == 'B')++ ans;
    int a = (si.back() == 'A');
    int b = (si[0] == 'B');
    cnt[a][b]++;
  }
  bool b = false;
  while (true) {
    if (b) {
      if (--cnt[1][1] >= 0) {
        ++ans;
      } else if (--cnt[1][0] >= 0) {
        ++ans;
        b = false;
      } else {
        break;
      }
    } else {
      if (--cnt[0][1] >= 0) {
        b = true;
      } else if (--cnt[1][1] >= 0) {
        b = true;
      } else {
        break;
      }
    }
  }
  wt(ans);
}
