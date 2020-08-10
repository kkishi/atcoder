#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using namespace std;

using mdint = ModInt<998244353>;

int main() {
  rd(int, n, m, k);
  mdint ans = 0;
  for (int i = 0; i <= k; ++i) {
    ans += mdint(m) * mdint(m - 1).Pow(n - 1 - i) * mdint::Comb(n - 1, i);
  }
  wt(ans);
}
