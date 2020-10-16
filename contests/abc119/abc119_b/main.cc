#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  rd(int, n);
  double ans = 0;
  rep(i, n) {
    rd(double, x);
    rd(string, u);
    if (u == "BTC") {
      x *= 380000;
    }
    ans += x;
  }
  cout << setprecision(20);
  wt(ans);
}
