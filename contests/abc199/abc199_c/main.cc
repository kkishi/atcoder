#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  ints(q);
  bool flipped = false;
  rep(q) {
    ints(t, a, b);
    --a, --b;
    if (t == 1) {
      if (flipped) {
        a = (a + n) % (2 * n);
        b = (b + n) % (2 * n);
      }
      swap(s[a], s[b]);
    } else {
      flipped = !flipped;
    }
  }
  if (flipped) {
    wt(s.substr(n) + s.substr(0, n));
  } else {
    wt(s);
  }
}
