#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n, T);
  int ans = 1000000;
  rep(i, n) {
    rd(int, c, t);
    if (t <= T) ans = min(ans, c);
  }
  if (ans == 1000000) {
    wt("TLE");
  } else {
    wt(ans);
  }
}
