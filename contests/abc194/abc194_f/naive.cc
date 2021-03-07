#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  strings(n);
  const int N = sz(n);
  V<int> v;
  each(e, n) {
    if (isdigit(e)) {
      v.pb(e - '0');
    } else {
      v.pb(e - 'A' + 10);
    }
  }
  int x = 0;
  rep(i, N)(x *= 16) += v[i];
  ints(k);
  int ans = 0;
  rep(i, 1, x + 1) {
    set<int> cnt;
    V<int> v;
    int j = i;
    while (j) {
      cnt.insert(j % 16);
      v.pb(j % 16);
      j /= 16;
    }
    if (sz(cnt) == k) {
      reverse(all(v));
      dbg(v);
      ++ans;
    }
  }
  wt(ans);
}
