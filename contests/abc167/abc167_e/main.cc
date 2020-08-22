#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using namespace std;

using mint = ModInt<998244353>;

int main() {
  ints(n, m, k);
  mint ans = 0;
  for (int i = 0; i <= k; ++i) {
    ans += m * mint(m - 1).Pow(n - 1 - i) * mint::Comb(n - 1, i);
  }
  wt(ans);
}
