#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int main() {
  rd(int, n);
  vector<ll> a(n);
  cin >> a;
  mint ans = 0;
  rep(i, 60) {
    ll ones = 0;
    rep(j, n) if ((a[j] >> i) & 1)++ ones;
    ans += mint(ones * (n - ones)) * mint(2).Pow(i);
  }
  wt(ans);
}
