#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
#define int ll
  ints(n, x);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  rep(i, 1, n) if (int diff = a[i - 1] + a[i] - x; diff > 0) {
    a[i] -= min(a[i], diff);
    ans += diff;
  }
  wt(ans);
}
