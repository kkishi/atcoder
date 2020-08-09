#include <bits/stdc++.h>

#include "binary_search.h"
#include "macros.h"

using namespace std;

ll n, k;
ll a[2 * 100000];
const ll tens = 1e9;

// Returns the number of pairs whose values are equal to or less than x.
ll count(ll x) {
  ll cnt = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] < 0) {
      if (a[i - 1] * a[i] <= x) {
        if (a[0] * a[i] <= x) {
          cnt += i;
          continue;
        }
        int j =
            BinarySearch<int>(0, i, [&](int idx) { return a[i] * a[idx] > x; });
        cnt += i - (j + 1);
      }
    } else {
      if (a[0] * a[i] <= x) {
        int j = BinarySearch<int>(0, i,
                                  [&](int idx) { return a[i] * a[idx] <= x; });
        cnt += j + 1;
      }
    }
  }
  return cnt;
}

int main() {
  cin >> n >> k;
  rep(i, n) cin >> a[i];
  sort(a, a + n);

  ll x = BinarySearch<ll>(-tens * tens - 1, tens * tens + 1,
                          [&](ll x) { return count(x) < k; });
  dbg(x, count(x - 1), count(x), count(x + 1));
  wt(x + 1);
}
