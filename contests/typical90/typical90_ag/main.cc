#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  if (h > w) swap(h, w);
  if (h == 1) {
    wt(w);
  } else {
    wt(div_ceil(h, 2) * div_ceil(w, 2));
  }
}
