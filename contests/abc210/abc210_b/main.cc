#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  rep(i, n) if (s[i] == '1') {
    wt(even(i) ? "Takahashi" : "Aoki");
    return;
  }
}
