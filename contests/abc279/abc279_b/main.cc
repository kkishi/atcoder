#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  wt([]() {
    strings(s, t);
    rep(i, sz(s) - sz(t) + 1) if (s.substr(i, sz(t)) == t) return true;
    return false;
  }());
}
