#include <bits/stdc++.h>

#include <atcoder/maxflow>

#include "macros.h"

using namespace std;

int main() {
  ints(n, m);
  V<string> s(n);
  cin >> s;

  auto idx = [&](int r, int c) { return r * m + c; };
  int src = idx(n - 1, m - 1) + 1, dst = src + 1;
  atcoder::mf_graph<int> g(dst + 1);
  auto add = [&](int u, int v) { g.add_edge(u, v, 1); };
  int dr[] = {0, 1, 0, -1};
  int dc[] = {1, 0, -1, 0};
  rep(r, n) rep(c, m) {
    if (s[r][c] == '#') continue;
    if ((r + c) % 2 == 0) {
      add(src, idx(r, c));
      rep(i, 4) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0 <= nr && nr < n && 0 <= nc && nc < m && s[r][c] == '.') {
          add(idx(r, c), idx(nr, nc));
        }
      }
    } else {
      add(idx(r, c), dst);
    }
  }

  wt(g.flow(src, dst));
  auto edges = g.edges();
  for (const auto& e : g.edges()) {
    if (e.from < src && e.to < src && e.flow == 1) {
      auto ridx = [&](int i) { return make_pair(i / m, i % m); };
      auto [r, c] = ridx(e.from);
      auto [nr, nc] = ridx(e.to);
      if (c + 1 == nc) {
        s[r][c] = '>';
        s[nr][nc] = '<';
      } else if (r + 1 == nr) {
        s[r][c] = 'v';
        s[nr][nc] = '^';
      } else if (c - 1 == nc) {
        s[r][c] = '<';
        s[nr][nc] = '>';
      } else if (r - 1 == nr) {
        s[r][c] = '^';
        s[nr][nc] = 'v';
      }
    }
  }
  rep(i, n) wt(s[i]);
}
