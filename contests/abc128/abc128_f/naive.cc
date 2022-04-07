#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> s(n);
  cin >> s;
  int ans = 0;
  rep(a, 1, n) {
    rep(b, 1, a) {
      chmax(ans, [&]() -> int {
        int sum = 0;
        V<bool> v(n);
        int pos = 0;
        while (true) {
          pos += a;
          if (pos == n - 1) break;
          if (pos >= n) return 0;
          if (v[pos]) return 0;
          v[pos] = true;
          sum += s[pos];
          pos -= b;
          if (v[pos]) return 0;
          v[pos] = true;
          sum += s[pos];
        }
        return sum;
      }());
    }
  }
  wt(ans);
}
