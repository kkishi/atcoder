#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n, y);
  y /= 1000;
  rep(a, 0, y / 10 + 1) rep(b, 0, (y - 10 * a) / 5 + 1) {
    int c = (y - a * 10 - b * 5);
    if (a + b + c == n) {
      wt(a, b, c);
      return 0;
    }
  }
  wt(-1, -1, -1);
}
