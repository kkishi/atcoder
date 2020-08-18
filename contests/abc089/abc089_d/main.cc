#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, h, w, d);
  int n = h * w;
  V<int> R(n), C(n);
  rep(i, h) rep(j, w) {
    rd(int, a);
    R[a - 1] = i;
    C[a - 1] = j;
  }
  V<int> cum(n);
  rep(i, n - d) cum[i + d] =
      cum[i] + abs(R[i + d] - R[i]) + abs(C[i + d] - C[i]);
  rd(int, q);
  while (q--) {
    rd(int, l, r);
    wt(cum[r - 1] - cum[l - 1]);
  }
}
