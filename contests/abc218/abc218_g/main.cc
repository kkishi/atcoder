#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  VV<int> g(n);
  rep(n - 1) {
    ints(u, v);
    --u, --v;
    g[u].pb(v);
    g[v].pb(u);
  }
  multiset<int> L, H;
  auto adjust = [&]() {
    while (sz(L) > sz(H) + 1) {
      auto it = prev(L.end());
      L.erase(it);
      H.insert(*it);
    }
    while (sz(L) < sz(H)) {
      auto it = H.begin();
      H.erase(it);
      L.insert(*it);
    }
  };
  auto push = [&](int x) {
    L.insert(x);
    if (!H.empty()) {
      auto it = prev(L.end());
      auto jt = H.begin();
      if (*it > *jt) {
        H.insert(*it);
        L.erase(it);
      }
    }
    adjust();
  };
  auto pop = [&](int x) {
    if (L.count(x)) {
      L.erase(L.find(x));
    } else {
      H.erase(H.find(x));
    }
    adjust();
  };
  auto get = [&]() {
    if (sz(L) > sz(H)) {
      return *prev(L.end());
    } else {
      return (*prev(L.end()) + *H.begin()) / 2;
    }
  };

  wt(Fix([&](auto rec, int node, int parent, int depth) -> int {
    push(a[node]);
    int ret = even(depth) ? -big : big;
    bool leaf = true;
    each(child, g[node]) {
      if (child == parent) continue;
      leaf = false;
      int r = rec(child, node, depth + 1);
      if (even(depth)) {
        chmax(ret, r);
      } else {
        chmin(ret, r);
      }
    }
    if (leaf) {
      ret = get();
    }
    pop(a[node]);
    return ret;
  })(0, -1, 0));
}
