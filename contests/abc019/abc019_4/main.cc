#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  std::ios_base::sync_with_stdio(true);
  ints(n);
  V<pair<int, int>> v;
  rep(i, n - 1) {
    cout << "? 1 " << (i + 2) << endl;
    ints(d);
    v.emplace_back(d, i + 1);
  }
  sort(all(v), greater());
  auto [_, a] = v[0];
  V<pair<int, int>> w;
  rep(i, n) {
    cout << "? " << (a + 1) << " " << (i + 1) << endl;
    ints(d);
    w.emplace_back(d, i);
  }
  sort(all(w), greater());
  auto [d, b] = w[0];
  cout << "! " << d << endl;
}
