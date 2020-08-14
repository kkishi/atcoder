#include <bits/stdc++.h>

#include "dijkstra.h"
#include "graph.h"
#include "macros.h"

using namespace std;

int main() {
  rd(ll, n, m, t);
  vector<ll> a(n);
  cin >> a;
  Graph<ll> g(n), rg(n);
  rep(i, m) {
    rd(ll, a, b, c);
    --a, --b;
    g.AddEdge(a, b, c);
    rg.AddEdge(b, a, c);
  }
  vector<optional<ll>> dist = Dijkstra(g, 0);
  vector<optional<ll>> rdist = Dijkstra(rg, 0);
  ll ans = 0;
  rep(i, n) {
    if (!dist[i] || !rdist[i]) continue;
    ll rem = t - *dist[i] - *rdist[i];
    if (rem > 0) ans = max(ans, rem * a[i]);
  }
  wt(ans);
}
