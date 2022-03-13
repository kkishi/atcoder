#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n, q);
  strings(s);
  V<char> t(q), d(q);
  rep(i, q) cin >> t[i] >> d[i];
  int ans = n;
  rep(2) {
    auto ok = [&](int i) {
      rep(j, q) {
        if (t[j] == s[i]) {
          d[j] == 'L' ? --i : ++i;
          if (i < 0) return true;
          if (i >= n) return false;
        }
      }
      return false;
    };
    ans -= BinarySearch<int>(-1, n, ok) + 1;
    reverse(s);
    rep(i, q) d[i] = 'L' + 'R' - d[i];
  }
  wt(ans);
}
