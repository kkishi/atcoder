#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n, m);
  VV<ll> x(n, V<ll>(3));
  V<int> idx(n);
  rep(i, n) {
    rep(j, 3) cin >> x[i][j];
    idx[i] = i;
  }
  ll ans = 0;
  rep(s, 1 << 3) {
    auto f = [&](int i) {
      ll ret = 0;
      rep(j, 3) { ret += x[i][j] * (((s >> j) & 1) ? 1 : -1); }
      return ret;
    };
    sort(all(idx), [&](int a, int b) { return f(a) > f(b); });
    ll sum = 0;
    rep(j, 3) {
      ll tmp = 0;
      rep(i, m) { tmp += x[idx[i]][j]; }
      sum += abs(tmp);
    }
    chmax(ans, sum);
  }
  wt(ans);
}
