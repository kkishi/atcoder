#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> cnt(n);
  for (int ai : a) {
    if ((n & 1) == (ai & 1)) {
      wt(0);
      return 0;
    }
    ++cnt[ai];
    if (cnt[ai] > 2 || ((n & 1) && ai == 0 && cnt[ai] > 1)) {
      wt(0);
      return 0;
    }
  }
  wt(mint(2).Pow(n / 2));
}
