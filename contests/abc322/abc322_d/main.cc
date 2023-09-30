#include <bits/stdc++.h>

#include "atcoder_yn.h"
#include "rotate90.h"

bool Main() {
  vector p(3, vector(4, string()));
  cin >> p;

  auto fill = [](VV<int>& g, const V<string>& p, int dr, int dc) -> bool {
    bool ok = true;
    rep(r, 4) rep(c, 4) {
      bool sharp = p[r][c] == '#';
      int R = r + dr;
      int C = c + dc;
      if (inside(R, C, 4, 4)) {
        if (sharp) {
          if (++g[R][C] > 1) {
            ok = false;
          }
        }
      } else {
        if (sharp) {
          ok = false;
        }
      }
    }
    return ok;
  };

  auto defill = [](VV<int>& g, const V<string>& p, int dr, int dc) -> void {
    rep(r, 4) rep(c, 4) {
      bool sharp = p[r][c] == '#';
      int R = r + dr;
      int C = c + dc;
      if (inside(R, C, 4, 4)) {
        if (sharp) {
          --g[R][C];
        }
      }
    }
    return;
  };

  vector g(4, vector(4, int(0)));
  return Fix([&](auto rec, int depth) -> bool {
    if (depth == 3) {
      each(e, g) each(e, e) if (!e) return false;
      return true;
    }
    rep(4) {
      p[depth] = Rotate90(p[depth]);
      rep(dr, -3, 4) rep(dc, -3, 4) {
        if (fill(g, p[depth], dr, dc)) {
          if (rec(depth + 1)) return true;
        }
        defill(g, p[depth], dr, dc);
      }
    }
    return false;
  })(0);
}
