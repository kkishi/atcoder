#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<int> a(n), b(n), c(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) cin >> c[i];
  int ans = 0;
  rep(i, n) {
    ans += b[i];
    if (a[i] + 1 == a[i + 1]) {
      ans += c[a[i] - 1];
    }
  }
  wt(ans);
}
