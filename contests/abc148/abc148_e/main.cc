#include <bits/stdc++.h>

#include "bignum.h"
#include "macros.h"

using namespace std;

int main() {
  rd(ll, n);
  if (n % 2) {
    wt(0);
  } else {
    ll ans = 0;
    ll fives = 1;
    while (bigint(fives) * 5 <= n) {
      fives *= 5;
      ans += n / fives / 2;
    }
    wt(ans);
  }
}
