#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int odds = 0;
  rep(n) {
    ints(a);
    if (!even(a)) ++odds;
  }
  wt(even(odds) ? "YES" : "NO");
}
