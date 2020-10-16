#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  for (;; ++n) {
    string s = to_string(n);
    bool ok = true;
    for (char c : s)
      if (c != s[0]) ok = false;
    if (ok) {
      wt(n);
      return;
    }
  }
}
