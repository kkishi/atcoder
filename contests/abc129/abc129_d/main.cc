#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, h, w);
  int H = h + 2, W = w + 2;

  V<string> s(H);
  s[0] = s[H - 1] = string(W, '#');
  rep(i, h) {
    rd(string, row);
    s[i + 1] = '#' + row + '#';
  }

  function<int(int, int, int, int, V<V<int>>&)> rec = [&](int dr, int dc, int r,
                                                          int c, V<V<int>>& m) {
    if (s[r][c] == '#') {
      return 0;
    }
    if (m[r][c] == -1) {
      m[r][c] = rec(dr, dc, r + dr, c + dc, m) + 1;
    }
    return m[r][c];
  };
  V<V<V<int>>> memo(4, V<V<int>>(H, V<int>(W, -1)));
  int ans = 0;
  int dr[] = {1, -1, 0, 0};
  int dc[] = {0, 0, 1, -1};
  rep(r, H) rep(c, W) if (s[r][c] == '.') {
    int res = -3;
    rep(i, 4) res += rec(dr[i], dc[i], r, c, memo[i]);
    chmax(ans, res);
  }
  wt(ans);
}
