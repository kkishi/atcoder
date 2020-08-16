#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n, d, x);
  V<int> a(n);
  cin >> a;
  int ans = x;
  rep(i, n) for (int j = 1; j <= d; j += a[i])++ ans;
  wt(ans);
}
