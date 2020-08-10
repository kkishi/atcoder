#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n, d);
  int ans = 0;
  rep(i, n) {
    rd(ll, x, y);
    if (x * x + y * y <= d * d) {
      ++ans;
    }
  }
  wt(ans);
}
