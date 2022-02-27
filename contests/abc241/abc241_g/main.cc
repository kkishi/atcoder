#include <bits/stdc++.h>

#include <atcoder/maxflow>

#include "atcoder.h"

void Main() {
  ints(n, m);
  vector g(n, vector(n, int(-1)));
  rep(m) {
    ints(w, l);
    --w, --l;
    g[w][l] = 1;
    g[l][w] = 0;
  }
  V<int> ans;
  rep(i, n) {
    int w = 0;
    vector G = g;
    rep(j, n) if (j != i) {
      if (G[i][j] == -1) {
        G[i][j] = 1;
        G[j][i] = 0;
      }
      w += G[i][j];
    }
#define person(i) (i)
#define game(i, j) (person(n) + ((i)*n) + (j))
    int s = game(n, 0), t = s + 1;
    atcoder::mf_graph<int> g(t + 1);
    bool ok = true;
    rep(j, n) if (j != i) {
      int W = 0;
      rep(k, n) if (G[j][k] != -1) W += G[j][k];
      int x = w - W - 1;
      if (x < 0) {
        ok = false;
        break;
      }
      g.add_edge(s, person(j), x);
    }
    if (!ok) continue;
    int games = 0;
    rep(i, n) rep(j, i) if (G[i][j] == -1) {
      g.add_edge(person(i), game(i, j), 1);
      g.add_edge(person(j), game(i, j), 1);
      g.add_edge(game(i, j), t, 1);
      ++games;
    }
    if (g.flow(s, t) == games) ans.pb(i + 1);
  }
  wt(ans);
}
