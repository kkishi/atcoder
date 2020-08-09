#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<int> v(n), c(n);
  rep(i, n) cin >> v[i];
  rep(i, n) cin >> c[i];
  int ans = numeric_limits<int>::min();
  rep(s, 1 << n) {
    int x = 0, y = 0;
    rep(i, n) if ((s >> i) & 1) {
      x += v[i];
      y += c[i];
    }
    ans = max(ans, x - y);
  }
  wt(ans);
}
