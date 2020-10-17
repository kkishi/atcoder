#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  int n, k;
  cin >> n >> k;

  mint ans = 0;
  for (int holes = 0; holes <= min(n - 1, k); ++holes) {
    ans += mint::Comb(n, holes) * mint::Comb(n - 1, holes);
  }
  cout << ans << endl;
}
