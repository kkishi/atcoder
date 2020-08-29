#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  mint sum = accumulate(all(a), mint(0));
  mint ans = 0;
  rep(i, n) ans += (sum - a[i]) * a[i];
  wt(ans / 2);
}
