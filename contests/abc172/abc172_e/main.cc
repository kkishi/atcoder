#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int main() {
  ints(n, m);
  mint ans = 0;
  for (int i = 0; i <= n; ++i) {
    mint x =
        mint::Comb(n, i) * mint::Perm(m, i) * mint::Perm(m - i, n - i).Pow(2);
    if (i & 1) x = -x;
    ans += x;
  }
  wt(ans);
}
