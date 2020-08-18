#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
#define int ll
  int ans = numeric_limits<int>::max();
  ints(l, r);
  rep(i, l, r) {
    rep(j, i + 1, r + 1) {
      int k = i * j % 2019;
      if (k == 0) {
        wt(0);
        return 0;
      }
      chmin(ans, k);
    }
  }
  wt(ans);
}
