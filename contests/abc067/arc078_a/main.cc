#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
#define int ll
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> s(n + 1);
  rep(i, n) s[i + 1] = s[i] + a[i];
  int ans = numeric_limits<int>::max();
  rep(i, n - 1) chmin(ans, abs(s[n] - s[i + 1] - s[i + 1]));
  wt(ans);
}
