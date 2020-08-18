#include <bits/stdc++.h>

#include "macros.h"
#include "warshall_floyd.h"

using namespace std;

const ll INF = 1LL << 60;

int main() {
  rd(ll, n, m, l);

  vector<vector<ll>> dist(n, vector<ll>(n, INF));
  rep(i, m) {
    rd(ll, a, b, c);
    if (c <= l) {
      --a, --b;
      dist[a][b] = dist[b][a] = c;
    }
  }
  WarshallFloyd(dist);

  vector<vector<ll>> dist2(n, vector<ll>(n, INF));
  rep(i, n) rep(j, n) if (dist[i][j] <= l) dist2[i][j] = 1;
  WarshallFloyd(dist2);

  ints(q);
  rep(i, q) {
    ints(s, t);
    --s, --t;
    ll d = dist2[s][t];
    if (d == INF) {
      wt(-1);
    } else {
      wt(d - 1);
    }
  }
}
