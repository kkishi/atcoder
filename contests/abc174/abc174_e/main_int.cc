#include <bits/stdc++.h>

#include "binary_search.h"
#include "macros.h"

using namespace std;

int main() {
  rd(ll, n, k);
  V<ll> a(n);
  rep(i, n) cin >> a[i];
  wt(BinarySearch<ll>(*max_element(all(a)), 0, [&](ll mid) {
    ll cuts = 0;
    rep(i, n) cuts += (a[i] - 1) / mid;
    return cuts <= k;
  }));
}
