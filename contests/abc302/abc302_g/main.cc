#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  each(e, a)-- e;
  V<int> b(a);
  sort(b);

  vector idx(4, vector(4, V<int>()));
  rep(i, n) idx[a[i]][b[i]].eb(i);

  VV<V<int>> perms(5);
  V<int> perm;
  Fix([&](auto rec) -> void {
    rep(i, 4) {
      if (count(all(perm), i) == 0) {
        perm.eb(i);
        perms[sz(perm)].eb(perm);
        rec();
        perm.pop_back();
      }
    }
  })();

  int ans = 0;
  rep(len, 2, 5) each(e, perms[len]) {
    while (true) {
      bool ok = true;
      rep(i, len) {
        int x = e[i];
        int y = e[(i + 1) % len];
        if (idx[x][y].empty()) {
          ok = false;
          break;
        }
      }
      if (!ok) break;
      ans += len - 1;
      V<int> v;
      rep(i, len) {
        int x = e[i];
        int y = e[(i + 1) % len];
        int z = idx[x][y].back();
        idx[x][y].pop_back();
        v.eb(z);
      }
      rep(i, sz(v) - 1) swap(a[v[i]], a[v[i + 1]]);
    }
  }
  wt(ans);
}
