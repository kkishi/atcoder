#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(t);
  V<string> s(n);
  cin >> s;
  V<int> ans;
  rep(i, n) {
    const string& e = s[i];
    int l = 0, r = sz(e) - 1;
    int L = 0, R = sz(t) - 1;
    while (l <= r && L <= R) {
      if (e[l] == t[L]) {
        ++l, ++L;
        continue;
      }
      if (e[r] == t[R]) {
        --r, --R;
        continue;
      }
      break;
    }
    if (l >= r && L >= R) {
      ans.eb(i + 1);
    }
  }
  wt(sz(ans));
  wt(ans);
}
