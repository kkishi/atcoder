#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  sort(all(a));

  mint ans = 0;
  rep(i, n - (k - 1)) ans -= mint(a[i]) * mint::Comb(n - 1 - i, k - 1);
  for (int i = n - 1; i >= (k - 1); --i) {
    ans += mint(a[i]) * mint::Comb(i, k - 1);
  }
  wt(ans);
}
