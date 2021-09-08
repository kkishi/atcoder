#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m);
  int N = n * 2;
  vector ok(N, vector(N, false));
  rep(m) {
    ints(a, b);
    --a, --b;
    ok[a][b] = ok[b][a] = true;
  }
  mint ans = 0;
  set<int> st;
  rep(i, N) st.insert(i);
  V<pair<int, int>> M;
  map<V<pair<int, int>>, int> MU;
  Fix([&](auto rec, int depth) {
    if (depth == n) {
      ++ans;
      dbg(M);
      V<pair<int, int>> SM = M;
      sort(all(SM));
      MU[SM]++;
      return;
    }
    V<int> v(all(st));
    rep(i, sz(v) - 1) if (ok[v[i]][v[i + 1]]) {
      st.erase(v[i]);
      st.erase(v[i + 1]);
      M.eb(v[i] + 1, v[i + 1] + 1);
      rec(depth + 1);
      st.insert(v[i]);
      st.insert(v[i + 1]);
      M.pop_back();
    }
  })(0);
  wt(ans);
  each(k, v, MU) dbg(k, v);
}
