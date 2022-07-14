#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  using P = pair<int, int>;
  VV<P> v;
  map<int, V<int>> mp;
  rep(n) {
    ints(m);
    V<P> vi;
    rep(m) {
      ints(p, e);
      vi.eb(p, e);
      mp[p].eb(e);
    }
    v.eb(vi);
  }
  each(k, v, mp) {
    v.eb(0);
    sort(v);
  }
  set<V<int>> st;
  rep(i, n) {
    V<int> vi;
    each(p, e, v[i]) {
      const auto& w = mp[p];
      if (w.back() == e && w[sz(w) - 2] < e) {
        vi.eb(p);
      }
    }
    st.insert(vi);
  }
  wt(sz(st));
}
