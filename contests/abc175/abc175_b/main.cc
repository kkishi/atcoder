#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  V<int> l(n);
  cin >> l;
  int ans = 0;
  rep(i, n) rep(j, i) rep(k, j) {
    int I = l[i], J = l[j], K = l[k];
    if (I != J && J != K && K != I && I < (J + K) && J < (K + I) &&
        K < (I + J)) {
      ++ans;
    }
  }
  wt(ans);
}
