#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m, q);
  V<int> w(n), v(n);
  rep(i, n) cin >> w[i] >> v[i];
  V<int> x(m);
  cin >> x;
  rep(q) {
    ints(l, r);
    --l, --r;
    V<int> box;
    rep(i, m) {
      if (l <= i && i <= r) continue;
      box.pb(x[i]);
    }
    sort(box);
    int ans = 0;
    V<int> used(n);
    each(e, box) {
      int vm = 0;
      int vi = -1;
      rep(i, n) if (!used[i] && e >= w[i] && chmax(vm, v[i])) vi = i;
      if (vi == -1) continue;
      used[vi] = true;
      ans += vm;
    }
    wt(ans);
  }
}
