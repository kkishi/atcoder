#include <bits/stdc++.h>

#include "atcoder_yn.h"
#include "graph.h"

bool Main() {
  ints(n);
  Graph gr(n);
  V<int> t(n), s(n), g(n);

  // Sentinel
  t[0] = 1;
  s[0] = 0;
  g[0] = 0;

  V<int> med;
  V<int> dem(n);
  rep(i, 1, n) {
    ints(p);
    --p;
    gr[p].eb(i);
    cin >> t[i] >> s[i] >> g[i];
    if (t[i] == 2) {
      med.pb(i);
      dem[i] = sz(med) - 1;
    }
  }

  using P = pair<int, int>;
  using state = tuple<int, int, low_priority_queue<P>>;

  state init;
  get<0>(init) = 1;
  get<1>(init) = 0;
  get<2>(init).emplace(0, 0);

  auto move = [&](state& st) {
    auto&& [cg, T, que] = st;
    while (!que.empty()) {
      auto [_, i] = que.top();
      if (cg < s[i]) break;
      que.pop();
      if (t[i] == 1) {
        cg += g[i];
      } else {
        // Simply doing `cg *= g[i];` could overflow.
        cg = min(big, __int128_t(cg) * g[i]);
      }
      each(k, gr[i]) {
        if (t[k] == 1) {
          que.emplace(s[k], k);
        } else {
          T |= 1 << dem[k];
        }
      }
    }
  };

  move(init);

  int N = sz(med);
  vector<state> dp(1 << N);
  dp[0] = init;

  rep(S, 1 << N) {
    rep(i, N) if (!hasbit(S, i) && hasbit(get<1>(dp[S]), i)) {
      state next = dp[S];
      get<2>(next).emplace(0, med[i]);
      move(next);
      int NS = S | (1 << i);
      if (chmax(get<0>(dp[NS]), get<0>(next))) {
        dp[NS] = next;
      }
    }
  }
  return get<0>(dp.back()) >= max(s);
}
