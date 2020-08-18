#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n, m, c);
  vector<int> b(m);
  cin >> b;
  int ans = 0;
  rep(i, n) {
    vector<int> a(m);
    rep(j, m) cin >> a[j];
    int res = c;
    rep(j, m) res += a[j] * b[j];
    if (res > 0) ++ans;
  }
  wt(ans);
}
