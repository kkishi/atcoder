#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  bool seen = false;
  each(e, s) {
    if (e == '|') seen = !seen;
    if (e == '*' && seen) {
      wt("in");
      return;
    }
  }
  wt("out");
}
