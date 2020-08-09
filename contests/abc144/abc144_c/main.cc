#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n);
  ll ans = 1LL << 60;
  for (ll i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      ans = min(ans, (i - 1) + (n / i - 1));
    }
  }
  wt(ans);
}
