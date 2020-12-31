#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

VV<string> abc = {
    {
        ".......",
        "...o...",
        "..o.o..",
        ".o...o.",
        ".ooooo.",
        ".o...o.",
        ".......",
    },
    {
        ".......",
        ".oooo..",
        ".o...o.",
        ".oooo..",
        ".o...o.",
        ".oooo..",
        ".......",
    },
    {
        ".......",
        "..ooo..",
        ".o...o.",
        ".o.....",
        ".o...o.",
        "..ooo..",
        ".......",
    },
};

void Main() {
  ints(h, w);
  V<string> c(h);
  cin >> c;
  auto rot90 = [](const V<string>& v) {
    int r = sz(v), c = sz(v[0]);
    V<string> u(c, string(r, '.'));
    rep(i, r) rep(j, c) u[j][r - 1 - i] = v[i][j];
    return u;
  };
  /*
  for (const auto& v : abc) {
    rep(i, 4) {
      V<string> u = v;
      rep(i) u = rot90(u);
      rep(i, 7) dbg(u[i]);
    }
  }
  */
  int max_factor = min(h / 7, w / 7);
  V<mint> two((max_factor * 7) * (max_factor * 7) + 1);
  two[0] = 1;
  rep(i, sz(two) - 1) two[i + 1] = two[i] * 2;
  // dbg(two);
  auto compute_hashes = [&](V<string> v) {
    VV<mint> ret(max_factor + 1);
    rep(4) {
      rep(factor, 1, max_factor + 1) {
        mint hash_r = 0;
        rep(i, sz(v)) {
          mint hash_c = 0;
          rep(j, sz(v[i])) rep(factor)(hash_c *= 2) += (v[i][j] == 'o');
          rep(factor)(hash_r *= two[7 * factor]) += hash_c;
        }
        ret[factor].push_back(hash_r);
      }
      v = rot90(v);
    }
    return ret;
  };

  V<VV<mint>> hs;
  for (const V<string>& v : abc) hs.push_back(compute_hashes(v));
  // dbg(hs);
  V<int> ans(3);
  rep(factor, 1, max_factor + 1) {
    int len = 7 * factor;
    vector hash_c(h + 1, vector(w + 1, mint(0)));
    vector hash_r(h + 1, vector(w + 1, mint(0)));
    rep(i, h) rep(j, w) {
      hash_c[i + 1][j + 1] = hash_c[i + 1][j] * 2 + (c[i][j] == 'o');
      // dbg(hash_c[i + 1][j], hash_c[i + 1][j + 1]);
      if (j >= len) hash_c[i + 1][j + 1] -= (c[i][j - len] == 'o') * two[len];
      hash_r[i + 1][j + 1] = hash_r[i][j + 1] * two[len] + hash_c[i + 1][j + 1];
      if (i >= len)
        hash_r[i + 1][j + 1] -= hash_c[i + 1 - len][j + 1] * two[len * len];
      // dbg(i, j, hash_c[i + 1][j], hash_c[i + 1][j + 1]);
      // dbg(i, j, hash_c[i + 1][j + 1], hash_r[i + 1][j + 1]);
      rep(hsi, 3) {
        const V<mint>& hashes = hs[hsi][factor];
        if (find(all(hashes), hash_r[i + 1][j + 1]) != hashes.end()) {
          ++ans[hsi];
        }
      }
    }
    // rep(i, h) dbg(hash_c[i]);
    // dbg(factor, ans);
  }
  wt(ans[0], ans[1], ans[2]);
}
