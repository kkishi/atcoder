#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n, k);
  int x = 1;
  rep(i, n) {
    if (k < x) {
      x += k;
    } else {
      x *= 2;
    }
  }
  wt(x);
}
