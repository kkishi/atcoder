#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

ll H[200000];

int main() {
  rd(ll, N, K);
  rep(i, N) cin >> H[i];
  sort(H, H + N);
  ll ans = 0;
  for (int i = 0; i < N - K; ++i) {
    ans += H[i];
  }
  wt(ans);
}
