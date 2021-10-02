#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s, t);
  bool ok = s == t;
  rep(i, sz(s) - 1) {
    swap(s[i], s[i + 1]);
    if (s == t) ok = true;
    swap(s[i], s[i + 1]);
  }
  wt(ok);
}
