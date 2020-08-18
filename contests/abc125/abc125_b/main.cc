#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  vector<int> v(n), c(n);
  cin >> v >> c;
  int ans = numeric_limits<int>::min();
  rep(s, 1 << n) {
    int x = 0, y = 0;
    rep(i, n) if ((s >> i) & 1) {
      x += v[i];
      y += c[i];
    }
    chmax(ans, x - y);
  }
  wt(ans);
}
