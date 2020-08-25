#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n, k);
  V<int> x(n);
  cin >> x;
  int ans = 0;
  rep(i, n) ans += min(x[i], k - x[i]) * 2;
  wt(ans);
}
