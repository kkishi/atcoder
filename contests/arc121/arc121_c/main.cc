#include <bits/stdc++.h>

#include "atcoder.h"

void Solve() {
  ints(n);
  V<int> p(n);
  cin >> p;
  V<int> P = p;
  V<int> ans;
  int t = 1;
  auto swp = [&](int i) {
    assert(even(t) == even(i + 1));
    ans.pb(i + 1);
    swap(p[i], p[i + 1]);
    ++t;
  };
  rrep(val, 1, n + 1) {
    // p[val:] is sorted
    int I;
    rep(i, n) if (p[i] == val) I = i;
    int i = I;
    if (i + 1 == val) continue;
    dbg(val, i, t);
    if (even(t) != even(i + 1)) {
      bool swapped = false;
      rep(j, n - 1) {
        if (even(t) != even(j + 1)) continue;
        if (j + 1 >= val) break;
        if (!(j + 1 < i || i < j)) continue;
        dbg(t, j);
        swp(j);
        swapped = true;
        break;
      }
      if (!swapped && val > 3) {
        swp(i - 1);
        swp(i);
        --i;
        swapped = true;
      }
      if (!swapped) {
        dbg("deadlock");
        dbg(val, t, p);
        rep(i, 3, n) assert(p[i] == i + 1);
        while (true) {
          if (p[0] == 1 && p[1] == 2 && p[2] == 3) break;
          if (even(t)) {
            swp(1);
          } else {
            swp(0);
          }
        }
        dbg(p);
        break;
      }
    }
    rep(j, i, val - 1) { swp(j); }
    dbg(t, p);
  }
  wt(sz(ans));
  wt(ans);

  // Validate
  assert(sz(ans) <= n * n);
  each(e, ans) swap(P[e - 1], P[e]);
  rep(i, n) assert(P[i] == i + 1);
}

void Main() {
  ints(t);
  rep(t) Solve();
}
