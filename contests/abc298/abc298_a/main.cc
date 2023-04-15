#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  bool ok1 = false;
  bool ok2 = true;
  each(e, s) {
    if (e == 'o') ok1 = true;
    if (e == 'x') ok2 = false;
  }
  wt(ok1 && ok2);
}
