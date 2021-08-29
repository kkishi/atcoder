#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "pow.h"

int n, k;
int a[2 * 100000];
const int tens = Pow(10, 9);

// Returns the number of pairs whose values are equal to or less than x.
int count(int x) {
  int cnt = 0;
  rep(i, 1, n) {
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

void Main() {
  cin >> n >> k;
  rep(i, n) cin >> a[i];
  sort(a, a + n);

  int x = BinarySearch<int>(-tens * tens - 1, tens * tens + 1,
                            [&](int x) { return count(x) < k; });
  wt(x + 1);
}
