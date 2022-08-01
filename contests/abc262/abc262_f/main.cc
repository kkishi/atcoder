#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> p(n);
  cin >> p;
  V<int> ans;
  auto take_rem = [](const V<int>& v, int rem) -> V<int> {
    int n = sz(v);
    int l = 0;
    int r = 0;
    set<pair<int, int>> st;
    V<int> ans;
    while (rem) {
      while (r < n && r - l < rem + 1) {
        st.emplace(v[r], r);
        ++r;
      }
      if (sz(st) < rem + 1) break;
      assert(r - l == sz(st));
      auto [val, idx] = *st.begin();
      ans.eb(val);
      rem -= idx - l;
      for (int i = l; i <= idx; ++i) {
        auto it = st.lower_bound({v[i], 0});
        st.erase(it);
      }
      l = idx + 1;
    }
    if (rem == 0) {
      rep(i, l, n) ans.eb(v[i]);
    }
    return ans;
  };
  {
    // Delete left
    int mi = big;
    int mi_i = -1;
    int mi_rem;
    rep(i, n) {
      int cost = i;
      if (cost <= k && chmin(mi, p[i])) {
        mi_i = i;
        mi_rem = k - cost;
      }
    }
    ans = {mi};
    V<int> v;
    rep(i, mi_i + 1, n) v.eb(p[i]);
    each(e, take_rem(v, mi_rem)) ans.eb(e);
  }
  {
    // Rotate right
    int mi = big;
    int mi_i = -1;
    int mi_rem;
    rep(i, n) {
      int cost = n - i;
      if (cost <= k && chmin(mi, p[i])) {
        mi_i = i;
        mi_rem = k - cost;
      }
    }
    if (mi != big) {
      V<int> v;
      rep(i, mi_i) v.eb(p[i]);
      V<int> R = take_rem(v, mi_rem);
      if (R.empty()) {
        wt(mi);
        return;
      }
      V<int> nans = {mi};
      set<pair<int, int>> L;
      rep(i, mi_i + 1, n) if (p[i] < R[0]) L.emplace(p[i], i);
      int idx = -big;
      each(v, i, L) {
        if (chmax(idx, i)) {
          nans.eb(v);
        }
      }
      each(e, R) nans.eb(e);
      chmin(ans, nans);
    }
  }
  wt(ans);
}
