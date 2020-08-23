#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  while (true) {
    rep(i, n) {
      if (a[i] % 2 == 1) {
        wt(ans);
        return 0;
      }
      a[i] /= 2;
    }
    ++ans;
  }
}
