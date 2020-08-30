#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
#define int ll
  ints(n, T);
  V<int> t(n);
  cin >> t;
  int ans = T;
  rep(i, n - 1) ans += min(T, t[i + 1] - t[i]);
  wt(ans);
}
