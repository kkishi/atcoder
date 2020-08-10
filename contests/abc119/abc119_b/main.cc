#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
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
