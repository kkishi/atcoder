#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m, k);
  V<int> a(m);
  cin >> a;
  each(e, a)-- e;
  VV<int> g(n);
  V<pair<int, int>> eg;
  rep(n - 1) {
    ints(u, v);
    --u, --v;
    g[u].pb(v);
    g[v].pb(u);
    eg.eb(u, v);
  }
  V<int> c;
  each(u, v, eg) {
    auto rec = Fix([&](auto rec, int node, int parent, set<int>& seen) -> void {
      seen.insert(node);
      each(child, g[node]) if (child != parent) { rec(child, node, seen); }
    });
    set<int> l, r;
    rec(u, v, l);
    rec(v, u, r);
    int cnt = 0;
    rep(i, m - 1) if (l.count(a[i]) && r.count(a[i + 1]) ||
                      l.count(a[i + 1]) && r.count(a[i])) {
      ++cnt;
    }
    c.pb(cnt);
  }
  map<int, mint> mp;
  mp[0] = 1;
  each(e, c) {
    map<int, mint> nmp;
    each(k, v, mp) {
      nmp[k - e] += v;
      nmp[k + e] += v;
    }
    swap(mp, nmp);
  }
  wt(mp[k]);
}
