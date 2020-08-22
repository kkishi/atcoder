#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int main() {
  ints(n);
  V<int> c(n);
  cin >> c;
  sort(all(c));

  mint ans = 0;
  rep(i, n) {
    int l = i;
    int r = n - i - 1;
    ans += c[i] * mint(2).Pow(l) * mint(2).Pow(r - 1) * (r + 2);
  }
  wt(ans * mint(2).Pow(n));
}
