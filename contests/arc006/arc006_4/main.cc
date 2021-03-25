#include <bits/stdc++.h>

#include "atcoder.h"

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
  V<string> grid(h);
  cin >> grid;
  auto rot90 = [](const V<string>& v) {
    int r = sz(v), c = sz(v[0]);
    V<string> u(c, string(r, '.'));
    rep(i, r) rep(j, c) u[j][r - 1 - i] = v[i][j];
    return u;
  };
  VV<bool> seen(h, V<bool>(w));
  V<int> ans(3);
  rep(i, h) rep(j, w) {
    if (seen[i][j]) continue;
    if (grid[i][j] != 'o') continue;
    int min_r = i, max_r = i, min_c = j, max_c = j;
    Fix([&](auto rec, int r, int c) -> void {
      seen[r][c] = true;
      chmin(min_r, r);
      chmax(max_r, r);
      chmin(min_c, c);
      chmax(max_c, c);
      rep(dr, -1, 2) rep(dc, -1, 2) {
        int nr = r + dr;
        int nc = c + dc;
        if (!inside(nr, nc, h, w)) continue;
        if (seen[nr][nc] || grid[nr][nc] != 'o') continue;
        rec(nr, nc);
      }
    })(i, j);
    assert(max_r - min_r == max_c - min_c);
    int factor = (max_r - min_r + 1) / 5;
    int offset_r = min_r - factor;
    int offset_c = min_c - factor;
    rep(i, 3) {
      rep(rot, 4) {
        V<string> u = abc[i];
        rep(rot) u = rot90(u);
        bool ok = true;
        rep(r, 7) rep(c, 7) rep(fr, factor)
            rep(fc, factor) if (u[r][c] != grid[offset_r + r * factor + fr]
                                               [offset_c + c * factor + fc]) {
          ok = false;
        }
        if (ok) {
          ++ans[i];
          goto out;
        }
      }
    }
  out:
    rep(i, 7 * factor) rep(j, 7 * factor) seen[offset_r + i][offset_c + j] =
        true;
    continue;
  }
  wt(ans[0], ans[1], ans[2]);
}
