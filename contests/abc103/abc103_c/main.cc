#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  vector<int> a(n);
  cin >> a;
  ll ans = 0;
  rep(i, n) ans += a[i] - 1;
  wt(ans);
}
