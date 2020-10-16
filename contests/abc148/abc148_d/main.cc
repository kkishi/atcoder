#include <bits/stdc++.h>

#include "atcoder.h"

int a[200000];

void Main() {
  ints(n);
  rep(i, n) cin >> a[i];
  int last = 0;
  rep(i, n) {
    if (a[i] == last + 1) {
      ++last;
    }
  }
  if (last == 0) {
    wt(-1);
  } else {
    wt(n - last);
  }
}
