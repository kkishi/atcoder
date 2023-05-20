#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> b(a);
  sort(b);
  int ans = big;
  Fix([&](auto rec, int depth, int cnt) -> void {
    if (depth == n) {
      chmin(ans, cnt);
    } else {
      if (a[depth] == b[depth]) {
        rec(depth + 1, cnt);
      } else {
        rep(i, depth + 1, n) {
          if (a[i] == b[depth]) {
            swap(a[depth], a[i]);
            rec(depth + 1, cnt + 1);
            swap(a[depth], a[i]);
          }
        }
      }
    }
  })(0, 0);
  wt(ans);
}
