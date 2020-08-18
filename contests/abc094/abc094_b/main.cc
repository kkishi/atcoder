#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(r, m, x);
  int lo = 0, hi = 0;
  rep(i, m) {
    ints(a);
    (a < x ? lo : hi)++;
  }
  wt(min(lo, hi));
}
