#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  ints(k);
  sort(s);
  do {
    --k;
    if (k == 0) {
      wt(s);
      break;
    }
  } while (next_permutation(all(s)));
}
