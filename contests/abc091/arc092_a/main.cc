#include <bits/stdc++.h>

#include "edmonds_karp.h"
#include "graph.h"
#include "macros.h"

using namespace std;

struct XY {
  int x, y;
};

int main() {
  rd(int, n);
  Graph<int> g(n * 2 + 2);
  V<XY> r(n), b(n);
  rep(i, n) cin >> r[i].x >> r[i].y;
  rep(i, n) cin >> b[i].x >> b[i].y;
  const int r0 = 0, b0 = r0 + n, s = b0 + n, d = s + 1;
  auto add = [&](int i, int j) {
    g.AddEdge(i, j, 1);
    g.AddEdge(j, i, 0);
  };
  rep(i, n) add(s, r0 + i);
  rep(i, n) add(b0 + i, d);
  rep(i, n) rep(j, n) if (r[i].x < b[j].x && r[i].y < b[j].y)
      add(r0 + i, b0 + j);
  wt(EdmondsKarp(g, s, d));
}
