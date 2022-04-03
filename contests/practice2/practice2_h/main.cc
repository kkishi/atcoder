#include <bits/stdc++.h>

#include "atcoder.h"
#include "strongly_connected_component.h"

void Main() {
  ints(n, d);
  V<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  Graph g(n * 2);

  rep(i, n - 1) rep(j, i + 1, n) {
    if (abs(x[i] - x[j]) < d) {
      // !i v !j = (i -> !j) ^ (j -> !i)
      g[i].eb(n + j);
      g[j].eb(n + i);
    }
    if (abs(x[i] - y[j]) < d) {
      // !i v j = (i -> j) ^ (!j -> !i)
      g[i].eb(j);
      g[n + j].eb(n + i);
    }
    if (abs(y[i] - x[j]) < d) {
      // i v !j = (!i -> !j) ^ (j -> i)
      g[n + i].eb(n + j);
      g[j].eb(i);
    }
    if (abs(y[i] - y[j]) < d) {
      // i v j = (!i -> j) ^ (!j -> i)
      g[n + i].eb(j);
      g[n + j].eb(i);
    }
  }

  VV<int> scc = StronglyConnectedComponents(g);
  V<int> t(n), f(n);
  rep(i, scc.size()) for (int j : scc[i]) {
    if (j < n) {
      t[j] = i;
    } else {
      f[j - n] = i;
    }
  }
  bool ok = true;
  V<int> v;
  rep(i, n) {
    if (t[i] == f[i]) {
      ok = false;
    } else {
      v.pb((t[i] > f[i] ? x : y)[i]);
    }
  }
  wt(ok);
  if (ok) {
    for (int vi : v) wt(vi);
  }
}
