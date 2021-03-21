#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(x);
  rep(i, sz(x)) if (x[i] == '.') {
    wt(x.substr(0, i));
    return;
  }
  wt(x);
}
