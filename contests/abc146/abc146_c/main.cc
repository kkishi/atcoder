#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, a, b, x);
  ll ans = 0;
  for (int d = 1; d <= 10; ++d) {
    ll tens = 1;
    for (int i = 1; i < d; ++i) {
      tens *= 10;
    }
    ll y = x - (tens * a + d * b);
    dbg(d, y, tens);
    if (y >= 0) {
      if (d == 10) {
        ans = tens;
      } else {
        ans = max(ans, tens + min(tens * 9 - 1, y / a));
      }
    }
  }
  wt(ans);
}
