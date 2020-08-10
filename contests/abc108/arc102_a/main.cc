#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n, k);
  ll x = n / k;
  ll ans = x * x * x;
  if (!(k & 1)) {
    ll y = (n + k / 2) / k;
    ans += y * y * y;
  }
  wt(ans);
}
