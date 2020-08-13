#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  V<int> x(n);
  rep(i, n) cin >> x[i];
  V<int> sx = x;
  sort(all(sx));
  rep(i, n) {
    int l = n / 2 - 1;
    wt(x[i] <= sx[l] ? sx[l + 1] : sx[l]);
  }
}
