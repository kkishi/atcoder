#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> l(n);
  cin >> l;
  sort(all(l));
  int ans = 0;
  rep(i, n) rep(j, i) rep(k, j) {
    int I = l[i], J = l[j], K = l[k];
    if (I != J && J != K && K != I && I < (J + K)) ++ans;
  }
  wt(ans);
}
