#include <bits/stdc++.h>
#include <min_cost_flow.h>

#include "atcoder.h"
#include "pow.h"

void Main() {
  ints(n, m);
  V<int> a(n), b(n), r(3);
  cin >> a >> b >> r;

#define round(i) (i)
#define pin_round(i, j) (round(3) + ((i)*3 + (j)))
#define pin(i) (pin_round(n, 0) + (i))
  int s = pin(n), t = s + 1;

  MinCostFlow g;
  rep(i, 3) g.Add(s, round(i), m, 0, m);
  rep(i, 3) rep(j, n) {
    int x = a[j] * Pow(b[j], i + 1) % r[i];
    g.Add(round(i), pin_round(j, i), 1, -x);
  }
  rep(i, 3) rep(j, n) g.Add(pin_round(j, i), pin(j), 1, 0);
  auto cost = [](int i, int a, int b) {
    if (i == 1) return a * b;
    if (i == 2) return a * b * (b - 1);
    return a * b * b * (b - 1);
  };
  rep(i, 3) rep(j, n) g.Add(pin(j), t, 1, cost(i + 1, a[j], b[j]));
  wt(-g.Flow(s, t).second);
}
