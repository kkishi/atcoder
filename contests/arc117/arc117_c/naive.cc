#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  rep(n - 1) {
    string ns;
    rep(i, sz(s) - 1) ns +=
        s[i] == s[i + 1] ? s[i] : ('B' + 'W' + 'R' - s[i] - s[i + 1]);
    s = ns;
  }
  wt(s);
}
