#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  vector<int> a(n);
  cin >> a;
  sort(all(a));
  int ans = a[0];
  rep(i, n - 1) ans = gcd(ans, a[i + 1]);
  wt(ans);
}
