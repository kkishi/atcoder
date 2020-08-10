#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n);
  vector<ll> x(n), y(n), h(n);
  int I = -1;
  rep(i, n) {
    cin >> x[i] >> y[i] >> h[i];
    if (h[i] > 0) I = i;
  }
  assert(I >= 0);
  rep(cx, 101) rep(cy, 101) {
    ll H = h[I] + abs(x[I] - cx) + abs(y[I] - cy);
    bool ok = true;
    rep(i, n) {
      if (max(H - abs(x[i] - cx) - abs(y[i] - cy), 0LL) != h[i]) ok = false;
    }
    if (ok) {
      wt(cx, cy, H);
      return 0;
    }
  }
}
