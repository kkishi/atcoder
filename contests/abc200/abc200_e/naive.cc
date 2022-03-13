#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<tuple<int, int, int>> v;
  rep(i, n) rep(j, n) rep(k, n) v.eb(i + 1, j + 1, k + 1);
  sort(v, [](auto& a, auto& b) {
    auto [i, j, k] = a;
    int s = i + j + k;
    auto [I, J, K] = b;
    int S = I + J + K;
    if (s != S) {
      return s < S;
    }
    if (i != I) {
      return i < I;
    }
    return j < J;
  });
  auto [a, b, c] = v[k - 1];
  wt(a, b, c);
}
