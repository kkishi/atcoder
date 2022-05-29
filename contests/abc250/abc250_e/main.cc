#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;

  using P = array<int, 2>;
  auto norm = [&](const V<int>& v) {
    set<int> seen;
    V<P> w;
    rep(i, n) if (seen.insert(v[i]).second) w.pb({i, v[i]});
    w.pb({n, -1});
    return w;
  };
  V<P> na = norm(a);
  V<P> nb = norm(b);
  set<int> A, B;
  V<tuple<int, int, int, int>> ok;
  rep(i, min(sz(na), sz(nb)) - 1) {
    A.insert(na[i][1]);
    B.insert(nb[i][1]);
    while (!A.empty() && !B.empty() && *A.begin() == *B.begin()) {
      A.erase(A.begin());
      B.erase(B.begin());
    }
    if (A.empty() && B.empty()) {
      ok.pb({na[i][0], na[i + 1][0], nb[i][0], nb[i + 1][0]});
    }
  }

  ints(q);
  rep(q) {
    wt([&] {
      ints(x, y);
      --x, --y;
      auto it = lower_bound(all(ok), tuple{x + 1, 0, 0, 0});
      if (it == ok.begin()) return false;
      --it;
      auto [a0, a1, b0, b1] = *it;
      return a0 <= x && x < a1 && b0 <= y && y < b1;
    }());
  }
}
