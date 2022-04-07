#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> s(n);
  cin >> s;
  int ans = 0;
  V<bool> v(n);
  rep(i, 1, n) {
    int l = 0, r = n - 1;
    int sum = 0;
    while (true) {
      l += i;
      r -= i;
      if (l >= n - 1 || l == r || v[l] || v[r] || r < i) break;
      v[l] = true;
      v[r] = true;
      sum += s[l] + s[r];
      chmax(ans, sum);
    }
    while (true) {
      l -= i;
      r += i;
      if (l == 0) break;
      v[l] = false;
      v[r] = false;
    }
  }
  wt(ans);
}
