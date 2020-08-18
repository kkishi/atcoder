#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  vector<int> b(n + 1);
  rep(i, n - 1) cin >> b[i + 1];
  b[0] = b[1];
  b[n] = b[n - 1];
  int ans = 0;
  rep(i, n) ans += min(b[i], b[i + 1]);
  wt(ans);
}
