#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  V<int> a(n);
  rep(i, n) cin >> a[i];
  int ans = 0;
  rep(i, n) {
    while (a[i] % 2 == 0) {
      a[i] /= 2;
      ++ans;
    }
  }
  wt(ans);
}
