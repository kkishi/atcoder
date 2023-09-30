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

  rep(r0, 4) {
    p[0] = Rotate90(p[0]);
    rep(r1, 4) {
      p[1] = Rotate90(p[1]);
      rep(r2, 4) {
        p[2] = Rotate90(p[2]);
        vector g(4, vector(4, int(0)));
        rep(dr, -3, 4) rep(dc, -3, 4) {
          if (fill(g, p[0], dr, dc)) {
            rep(dr, -3, 4) rep(dc, -3, 4) {
              if (fill(g, p[1], dr, dc)) {
                rep(dr, -3, 4) rep(dc, -3, 4) {
                  if (fill(g, p[2], dr, dc)) {
                    bool ok = true;
                    each(e, g) each(e, e) if (e == 0) ok = false;
                    if (ok) return true;
                  }
                  defill(g, p[2], dr, dc);
                }
              }
              defill(g, p[1], dr, dc);
            }
          }
          defill(g, p[0], dr, dc);
        }
      }
    }
  }
  return false;
}
