#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  ll minus = 0, mini = numeric_limits<ll>::max(), sum = 0;
  rep(i, n) {
    rd(ll, a);
    if (a < 0) {
      ++minus;
      a = -a;
    }
    sum += a;
    chmin(mini, a);
  }
  if (minus % 2 == 1) {
    sum -= mini * 2;
  }
  wt(sum);
}
