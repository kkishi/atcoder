#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, r, m, x);
  int lo = 0, hi = 0;
  rep(i, m) {
    rd(int, a);
    (a < x ? lo : hi)++;
  }
  wt(min(lo, hi));
}
