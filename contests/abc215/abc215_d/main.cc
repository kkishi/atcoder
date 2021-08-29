#include <bits/stdc++.h>

#include "atcoder.h"
#include "sieve.h"

void Main() {
  ints(n, m);
  V<int> a(n);
  cin >> a;
  set<int> st(all(a));
  set<int> ps;
  Sieve s(100001);
  each(e, st) { each(k, _, s.Factors(e)) ps.insert(k); }
  V<bool> p(m + 1, false);
  each(e, ps) {
    // dbg(e);
    if (e == 1) continue;
    for (int i = e; i <= m; i += e) {
      p[i] = true;
    }
  }
  // dbg(p);
  V<int> ans;
  rep(i, 1, m + 1) if (!p[i]) ans.pb(i);
  wt(sz(ans));
  each(e, ans) wt(e);
}
