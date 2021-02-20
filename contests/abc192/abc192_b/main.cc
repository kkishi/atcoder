#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  bool ok = true;
  rep(i, sz(s)) {
    if (even(i)) {
      if (!islower(s[i])) {
        ok = false;
      }
    } else {
      if (!isupper(s[i])) {
        ok = false;
      }
    }
  }
  wt(ok);
}
