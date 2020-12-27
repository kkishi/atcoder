#include <bits/stdc++.h>

#include "atcoder.h"

int Simulate(V<int> v) {
  while (sz(v) > 1) {
    V<int> nv;
    auto mid = [](int a, int b, int c) {
      return a + b + c - min({a, b, c}) - max({a, b, c});
    };
    rep(i, sz(v) - 2) nv.push_back(mid(v[i], v[i + 1], v[i + 2]));
    swap(v, nv);
  }
  return v[0];
}

void Main() {
  ints(n, x);
  int N = 2 * n - 1;
  if (x == 1 || x == N) {
    wt("No");
    return;
  }
  wt("Yes");
  V<int> ans(N);
  int mid = (N + 1) / 2;
  if (x < mid) {
    int d = mid - x;
    rep(i, N - d) ans[i + d] = i + 1;
    rep(i, d) ans[i] = N - i;
  } else {
    int d = x - mid;
    rep(i, N - d) ans[i] = i + d + 1;
    rep(i, d) ans[N - 1 - i] = i + 1;
  }
#ifdef DEBUG
  dbg(ans);
  int s = Simulate(ans);
  dbg(s);
  assert(s == x);
#endif
  rep(i, N) wt(ans[i]);
}
