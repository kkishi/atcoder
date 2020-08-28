#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int main() {
  ints(n);
  V<int> a(n + 1);
  cin >> a;
  V<int> prev(sz(a), -1);
  V<int> dup;
  rep(i, sz(a)) {
    --a[i];
    if (int& p = prev[a[i]]; p == -1) {
      p = i;
    } else {
      dup.push_back(p);
      dup.push_back(i);
    }
  }
  int x = dup[0];
  int z = sz(a) - dup[1] - 1;
  rep(len, 1, sz(a) + 1) {
    mint ans = 0;
    // Use both
    if (len >= 2) ans += mint::Comb(sz(a) - 2, len - 2);
    // Use none
    if (len <= sz(a) - 2) ans += mint::Comb(sz(a) - 2, len);
    // Use one
    if (len >= 1 && len - 1 <= sz(a) - 2)
      ans += mint::Comb(sz(a) - 2, len - 1) * 2;
    // Correct overcount for Use one
    if (len >= 1 && len - 1 <= x + z) ans -= mint::Comb(x + z, len - 1);
    wt(ans);
  }
}
