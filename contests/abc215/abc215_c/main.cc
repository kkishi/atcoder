#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  ints(k);
  sort(all(s));
  do {
    --k;
    if (k == 0) {
      wt(s);
      break;
    }
  } while (next_permutation(all(s)));
}
