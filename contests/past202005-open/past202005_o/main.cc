#include <bits/stdc++.h>

#include <atcoder/mincostflow>

#include "atcoder.h"
#include "pow.h"

void Main() {
  ints(n, m);
  V<int> a(n), b(n), r(3);
  cin >> a >> b >> r;

#define round(i) (i)
#define pin_round(i, j) (round(3) + ((i)*3 + (j)))
#define pin(i) (pin_round(n, 0) + (i))
  int s = pin(n), t = s + 1, S = t + 1, T = S + 1;

  atcoder::mcf_graph<int, int> g(T + 1);
#define e g.add_edge
  // rep(i, 3) e(s, round(i), m, 0);
  int sum = 0;
  rep(i, 3) rep(j, n) {
    int x = a[j] * Pow(b[j], i + 1) % r[i];
    sum -= x;
    e(pin_round(j, i), round(i), 1, x);
  }
  rep(i, 3) rep(j, n) e(pin_round(j, i), pin(j), 1, 0);
  auto cost = [](int i, int a, int b) {
    if (i == 1) return a * b;
    if (i == 2) return a * b * (b - 1);
    return a * b * b * (b - 1);
  };
  rep(i, 3) rep(j, n) e(pin(j), t, 1, cost(i + 1, a[j], b[j]));

  e(t, s, big, 0);

  rep(i, 3) rep(j, n) e(S, pin_round(j, i), 1, 0);
  rep(i, 3) e(round(i), T, n, 0);

  rep(i, 3) e(S, round(i), m, 0);
  e(s, T, m * 3, 0);

  wt(-(sum + g.flow(S, T).second));
}
