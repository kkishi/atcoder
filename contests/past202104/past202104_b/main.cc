#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  int N = sz(s) / 4;
  int idx = -1;
  rep(i, N) if (s[1 + i * 4] == 'o') idx = i;
  if (idx == -1) {
    wt("none");
  } else {
    wt(idx + 1);
  }
}
