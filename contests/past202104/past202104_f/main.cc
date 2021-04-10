#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, l, t, x);
  V<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  rep(i, n) {
    if (b[i] >= l && a[i] > t) {
      wt("forever");
      return;
    }
  }
  int tot = 0;
  int cont = 0;
  rep(i, n) {
    if (b[i] >= l) {
      if (cont + a[i] > t) {
        tot += t - cont;
        tot += x;
        tot += a[i];
        cont = a[i];
      } else {
        tot += a[i];
        cont += a[i];
      }
    } else {
      tot += a[i];
      cont = 0;
    }
    if (cont == t) {
      cont = 0;
      tot += x;
    }
  }
  wt(tot);
}
