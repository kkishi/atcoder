#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(m);
  rep(m) {
    strings(s);
    each(e, s) {
      if (e == 'A' || e == 'T') {
        e = 'A' + 'T' - e;
      } else {
        e = 'C' + 'G' - e;
      }
    }
    reverse(s);
    wt(s);
  }
}
