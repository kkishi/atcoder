#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(n);
  each(e, n) e -= '0';
  sort(all(n), greater{});
  int a = n[0], b = n[1];
  rep(i, 2, sz(n)) {
    if (a < b) {
      a = a * 10 + n[i];
    } else {
      b = b * 10 + n[i];
    }
  }
  wt(a * b);
}
