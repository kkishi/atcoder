#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n, k);
  int ans = 0;
  rep(i, n) {
    ints(h);
    if (h >= k) ++ans;
  }
  wt(ans);
}
