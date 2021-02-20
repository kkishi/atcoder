#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  bool ok = true;
  rep(i, sz(s)) if (even(i) != !!islower(s[i])) ok = false;
  wt(ok);
}
