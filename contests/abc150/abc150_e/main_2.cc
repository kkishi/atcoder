#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using namespace std;

int n;
int c[200000];

int main() {
  cin >> n;
  rep(i, n) cin >> c[i];
  sort(c, c + n);

  mint ans = 0;
  rep(i, n) {
    int l = i;
    int r = n - i - 1;
    dbg(l, r);
    ans += mint(c[i]) * mint(2).Pow(l) * mint(2).Pow(r - 1) * (r + 2);
  }
  wt(ans * mint(2).Pow(n));
}
