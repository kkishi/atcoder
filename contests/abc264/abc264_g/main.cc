#include <bits/stdc++.h>

#include "atcoder.h"
#include "bellman_ford.h"

void Main() {
  ints(n);
  map<string, int> mp;
  rep(n) {
    strings(t);
    ints(p);
    mp[t] += p;
  }
  V<string> v = {""};
  rep(i, 2) {
    int s = sz(v);
    rep(j, s) rep(k, 26) v.eb(v[j] + (char)('a' + k));
  }
  sort(v);
  int N = sz(v);
  WeightedGraph<int> g(N);
  rep(i, N) rep(j, 26) {
    string t = v[i] + (char)('a' + j);
    int w = 0;
    rep(k, sz(t)) w += mp[t.substr(sz(t) - 1 - k)];
    if (sz(t) == 3) t = t.substr(1);
    int I = lower_bound(all(v), t) - v.begin();
    g[i].eb(I, -w);
  }
  auto [dist, ok] = BellmanFord(g, 0);
  if (!ok) {
    wt("Infinity");
  } else {
    int ans = -big;
    rep(i, 1, sz(dist)) if (dist[i]) chmax(ans, -*dist[i]);
    wt(ans);
  }
}
