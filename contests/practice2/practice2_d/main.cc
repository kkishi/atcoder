#include <bits/stdc++.h>

#include "edmonds_karp.h"
#include "graph.h"
#include "macros.h"

using namespace std;

int main() {
  ints(n, m);
  V<string> s(n);
  cin >> s;

  auto idx = [&](int r, int c) { return r * m + c; };
  int src = idx(n - 1, m - 1) + 1, dst = src + 1;
  Graph<int> g(dst + 1);
  auto add = [&](int u, int v) {
    g.AddEdge(u, v, 1);
    g.AddEdge(v, u, 0);
  };
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

  auto [total, flow] = EdmondsKarp(g, src, dst);
  rep(r, n) rep(c, m) rep(k, 4) {
    int nr = r + dr[k];
    int nc = c + dc[k];
    if (0 <= nr && nr < n && 0 <= nc && nc < m &&
        flow[idx(r, c)][idx(nr, nc)] == 1) {
      if (k == 0) {
        s[r][c] = '>';
        s[nr][nc] = '<';
      } else if (k == 1) {
        s[r][c] = 'v';
        s[nr][nc] = '^';
      } else if (k == 2) {
        s[r][c] = '<';
        s[nr][nc] = '>';
      } else {
        s[r][c] = '^';
        s[nr][nc] = 'v';
      }
    }
  }
  wt(total);
  rep(i, n) wt(s[i]);
}
