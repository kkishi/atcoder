#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<int> a(n), b(n), c(n);
  cin >> a >> b >> c;
  int ans = 0;
  rep(i, n) {
    ans += b[i];
    if (a[i] + 1 == a[i + 1]) {
      ans += c[a[i] - 1];
    }
  }
  wt(ans);
}
