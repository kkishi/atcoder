#include <bits/stdc++.h>

#include "atcoder.h"
#include "rational.h"

void Main() {
  ints(n, a);
  V<int> w(n), x(n), v(n);
  rep(i, n) cin >> w[i] >> x[i] >> v[i];

  int ans = 0;

  // Time 0
  rep(i, n) {
    int sum = 0;
    rep(j, n) if (x[i] <= x[j] && x[j] <= x[i] + a) sum += w[j];
    chmax(ans, sum);
  }

  auto f = [&](int left_x, int left_v) {
    int sum = 0;
    V<tuple<Rational, bool, int>> events;  // Time, Out, Weight
    rep(i, n) {
      int relative_v = v[i] - left_v;
      if (relative_v == 0) {
        if (left_x <= x[i] && x[i] <= left_x + a) sum += w[i];
      } else {
        Rational in(left_x - x[i], relative_v);
        Rational out(left_x + a - x[i], relative_v);
        if (out < in) swap(in, out);
        events.eb(in, false, w[i]);
        events.eb(out, true, -w[i]);
      }
    }
    sort(events);
    for (auto [time, _, weight] : events) {
      sum += weight;
      if (Rational(0, 1) <= time) chmax(ans, sum);
    }
  };

  rep(i, n) f(x[i], v[i]);
  wt(ans);
}
