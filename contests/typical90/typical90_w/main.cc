#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(h, w);
  V<string> c(h);
  cin >> c;
  // State has w+1 bits. The lowest bit represents the furthest cell.
  VV<pair<int32_t, int32_t>> state(w);
  int max_size = 0;
  rep(i, w) {
    rep(mask, 1 << (w + 1)) {
      if (mask & (mask >> w)) continue;
      // Same row (the highest i+1 bits)
      int same_row = mask >> (w - i);
      if (same_row & (same_row >> 1)) continue;
      // Previous row (the lowest w-i bits)
      int prev_row = mask & ((1 << (w - i)) - 1);
      if (i == 0) prev_row >>= 1;
      if (prev_row & (prev_row >> 1)) continue;
      int j = sz(state[i]);
      state[i].eb(mask, j);
    }
    sort(all(state[i]));
    chmax(max_size, sz(state[i]));
  }
  auto state_idx = [&](int i, int32_t mask) {
    auto& st = state[i];
    auto it = lower_bound(all(st), pair<int32_t, int32_t>{mask, 0});
    if (it == st.end()) return -1;
    return it->second;
  };
  VV<pair<int32_t, int32_t>> next_state(w);
  rep(i, w) {
    each(s, _, state[i]) {
      int ns0 = s >> 1;
      int ns1 = (s >> 1) | (1 << w);
      int ni = (i + 1) % w;
      next_state[i].eb(state_idx(ni, ns0), state_idx(ni, ns1));
    }
  }
  vector dp(2, vector(max_size, mint(0)));
  int idx = 0;
  rep(i, h) rep(j, w) {
    auto& cdp = dp[idx];
    each(e, cdp) e = 0;
    idx = 1 - idx;
    auto& pdp = dp[idx];
    if (i == 0 && j == 0) {
      cdp[state_idx(0, 0)] = 1;
      if (c[0][0] == '.') cdp[state_idx(0, 1 << w)] = 1;
      continue;
    }
    int pj;
    if (j == 0) {
      pj = w - 1;
    } else {
      pj = j - 1;
    }
    rep(si, sz(state[pj])) {
      mint d = pdp[si];
      if (d == 0) continue;
      auto [ps, _] = state[pj][si];
      // Do not put.
      int s = ps >> 1;
      cdp[next_state[pj][si].first] += d;
      if (c[i][j] == '#') continue;
      auto ok = [&]() {
        // Top left
        if (j > 0 && hasbit(ps, 0)) return false;
        // Top
        if (hasbit(ps, 1)) return false;
        // Top right
        if (j + 1 < w && hasbit(ps, 2)) return false;
        // Left
        if (j > 0 && hasbit(ps, w)) return false;
        return true;
      };
      if (!ok()) continue;
      s |= 1 << w;
      cdp[next_state[pj][si].second] += d;
    }
  }
  wt(accumulate(dp[1 - idx]));
}
