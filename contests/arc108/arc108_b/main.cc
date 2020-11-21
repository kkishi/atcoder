#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  string t;
  rep(i, n) {
    t += s[i];
    if (sz(t) >= 3 && t.substr(sz(t) - 3, 3) == "fox") {
      rep(3) t.pop_back();
    }
  }
  wt(sz(t));
}
