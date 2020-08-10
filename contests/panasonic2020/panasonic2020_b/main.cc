#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, h, w);
  if (min(h, w) == 1) {
    wt(1);
    return 0;
  }
  ll h_even = h / 2, h_odd = h - h_even;
  ll w_even = w / 2, w_odd = w - w_even;
  wt(w_even * h_even + w_odd * h_odd);
}
