#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  ll ans = 0;
  rep(i, n) ans += a[i] - 1;
  wt(ans);
}
