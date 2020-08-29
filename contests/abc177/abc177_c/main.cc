#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<mint> sum(n + 1);
  rrep(i, n) sum[i] = sum[i + 1] + a[i];
  mint ans = 0;
  rep(i, n - 1) ans += a[i] * sum[i + 1];
  wt(ans);
}
