#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int a[100000];

int main() {
  ints(n, k);
  rep(i, n) cin >> a[i];
  sort(a, a + n);

  mint ans = 0;
  for (int i = 0; i < n - (k - 1); ++i) {
    ans -= mint(a[i]) * mint::Comb(n - 1 - i, k - 1);
  }
  for (int i = n - 1; i >= (k - 1); --i) {
    ans += mint(a[i]) * mint::Comb(i, k - 1);
  }
  wt(ans);
}
