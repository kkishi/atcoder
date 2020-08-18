#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int main() {
  ints(x, y);
  if ((x + y) % 3) {
    wt(0);
    return 0;
  }
  int n = (2 * y - x) / 3;
  int m = (2 * x - y) / 3;
  if (n < 0 || m < 0) {
    wt(0);
    return 0;
  }
  wt(mint::Comb(n + m, m));
}
