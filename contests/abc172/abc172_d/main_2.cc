#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n);
  ll ans = 0;
  vector<ll> v(n + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j += i) {
      ++v[j];
    }
    ans += i * v[i];
  }
  wt(ans);
}
