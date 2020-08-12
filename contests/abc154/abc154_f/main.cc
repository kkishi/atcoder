#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

mint calc(int r, int c) { return mint::Comb(r + c + 2, c + 1) - 1; }

int main() {
  rd(int, r1, c1, r2, c2);
  --r1, --c1;
  wt(calc(r2, c2) - calc(r2, c1) - calc(r1, c2) + calc(r1, c1));
}
