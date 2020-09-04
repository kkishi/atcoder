#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
#define int ll
  ints(n, a, b);
  V<int> x(n);
  cin >> x;
  sort(all(x));
  int ans = 0;
  rep(i, n - 1) ans += min(b, a * (x[i + 1] - x[i]));
  wt(ans);
}
