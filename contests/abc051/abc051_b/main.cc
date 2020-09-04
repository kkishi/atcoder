#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(k, s);
  int ans = 0;
  rep(x, 0, k + 1) rep(y, 0, k + 1) {
    int z = s - x - y;
    if (0 <= z && z <= k) ++ans;
  }
  wt(ans);
}
