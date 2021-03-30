#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, l);
  strings(s);
  int tab = 1;
  int ans = 0;
  each(e, s) {
    if (e == '+') {
      ++tab;
      if (tab > l) {
        ++ans;
        tab = 1;
      }
    } else {
      --tab;
    }
  }
  wt(ans);
}
