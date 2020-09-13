#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int main() {
  ints(n);
  if (n == 1) {
    wt(0);
  } else if (n == 2) {
    wt(2);
  } else {
    wt(mint(10).Pow(n) - mint(9).Pow(n) - mint(9).Pow(n) + mint(8).Pow(n));
  }
}
