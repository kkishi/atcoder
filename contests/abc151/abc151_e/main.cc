#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

int a[100000];
mint combs[100000];

using namespace std;

int main() {
  rd(int, n, k);
  if (k == 1) {
    wt(0);
    return 0;
  }
  rep(i, n) cin >> a[i];
  sort(a, a + n);

  int l = k - 2;
  for (int i = l; i <= n - 2; ++i) {
    combs[i] = combs[i - 1] + mint::Comb(i, l);
    dbg(i, combs[i]);
  }
  mint mins = 0;
  for (int i = 0; i < n - (k - 1); ++i) {
    mins += mint(a[i]) * combs[n - i - 2];
    dbg(i, a[i], n - i - 2, combs[n - i - 2], mins);
  }
  mint maxs = 0;
  for (int i = n - 1; i >= (k - 1); --i) {
    maxs += mint(a[i]) * combs[i - 1];
    dbg(i, a[i], i - 1, combs[i - 1], maxs);
  }
  wt(maxs - mins);
}
