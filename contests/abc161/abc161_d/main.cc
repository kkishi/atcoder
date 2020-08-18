#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

ll increment(ll x) {
  if (x < 10) {
    return x + 1;
  }
  ll a = x % 10;
  ll b = x / 10 % 10;
  if (a + 1 < 10 && a + 1 <= b + 1) {
    return x + 1;
  }
  ll res = increment(x / 10);
  if (res % 10 == 0) {
    return res * 10;
  }
  return res * 10 + (res % 10 - 1);
}

int main() {
  ints(k);

  ll x = 0;
  rep(i, k) x = increment(x);
  wt(x);
}
