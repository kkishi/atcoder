#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n, X);
  vector<int> x(n);
  rep(i, n) cin >> x[i];
  int ans = abs(x[0] - X);
  rep(i, n - 1) ans = gcd(ans, abs(x[i + 1] - X));
  wt(ans);
}
