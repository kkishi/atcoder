#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(m, n);
  V<V<int>> vs;
  V<int> v;
  stack<pair<int, bool>> stk;
  rep(i, 1, 4) {
    stk.push({0, false});
    stk.push({i, true});
  }
  while (!stk.empty()) {
    auto [x, push] = stk.top();
    stk.pop();
    if (!push) {
      v.pop_back();
      continue;
    }
    v.pb(x);
    if (sz(v) == m) {
      vs.pb(v);
      continue;
    }
    rep(i, 1, 4) {
      bool ok = true;
      rep(j, i) if (int k = sz(v) - 1 - j; k >= 0 && v[k] == i) ok = false;
      if (ok) {
        stk.push({0, false});
        stk.push({i, true});
      }
    }
  }
  // for (auto& vsi : vs) dbg(vsi);
  set<V<int>> valid;
  V<int> seq;
  Fix([&](auto rec) -> void {
    valid.insert(seq);
    if (sz(seq) == 4) return;
    rep(i, sz(vs)) {
      rep(j, m) rep(k, vs[i][j]) {
        if (int l = sz(seq) - 1 - k; l >= 0 && vs[seq[l]][j] == vs[i][j]) {
          goto bail;
        }
      }
      seq.pb(i);
      rec();
      seq.pop_back();
    bail:
      continue;
    }
  })();
  /*
  for (auto& vi : valid) {
    dbg(vi);
    for (int i : vi) dbg(vs[i]);
  }
  */
  map<V<int>, int> dp;
  dp[{}] = 1;
  rep(i, n) {
    map<V<int>, int> ndp;
    for (auto& [k, v] : dp) {
      V<int> nk;
      if (sz(k) == 4) {
        rep(i, 3) nk.pb(k[i + 1]);
      } else {
        nk = k;
      }
      rep(i, sz(vs)) {
        nk.pb(i);
        if (valid.count(nk)) {
          ndp[nk] += v;
        }
        nk.pop_back();
      }
    }
    swap(dp, ndp);
    /*
    int sum = 0;
    for (auto& [_, v] : dp) sum += v;
   dbg(i, sum);
    */
  }
  int ans = 0;
  for (auto& [_, v] : dp) ans += v;
  wt(ans);

  // dbg(sz(vs));
  // for (auto& vsi : vs) dbg(vsi);
}
