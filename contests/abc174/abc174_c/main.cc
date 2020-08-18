#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, k);
  ll sum = 0;
  ll x = 7;
  rep(i, k + 1) {
    sum = (sum + x) % k;
    if (sum == 0) {
      wt(i + 1);
      return 0;
    }
    x = x * 10 % k;
  }
  wt(-1);
}
