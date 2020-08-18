#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, N, K);
  V<ll> H(N);
  cin >> H;
  sort(all(H));
  ll ans = 0;
  rep(i, N - K) ans += H[i];
  wt(ans);
}
