#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  if (min(h, w) == 1) {
    wt(1);
    return;
  }
  int h_even = h / 2, h_odd = h - h_even;
  int w_even = w / 2, w_odd = w - w_even;
  wt(w_even * h_even + w_odd * h_odd);
}
