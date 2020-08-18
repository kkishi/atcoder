#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(h, w, d);
  int n = h * w;
  V<int> R(n), C(n);
  rep(i, h) rep(j, w) {
    ints(a);
    R[a - 1] = i;
    C[a - 1] = j;
  }
  V<int> cum(n);
  rep(i, n - d) cum[i + d] =
      cum[i] + abs(R[i + d] - R[i]) + abs(C[i + d] - C[i]);
  ints(q);
  while (q--) {
    ints(l, r);
    wt(cum[r - 1] - cum[l - 1]);
  }
}
