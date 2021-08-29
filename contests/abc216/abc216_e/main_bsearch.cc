#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "numeric_sequence.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  int x = BinarySearch<int>(*max_element(all(a)), -1, [&](int x) {
    int sum = 0;
    each(e, a) sum += max(0, e - x);
    return sum <= k;
  });
  int ans = 0;
  each(e, a) if (e > x) {
    ans += ArithmeticProgressionSum<int>(x + 1, 1, e - x);
    k -= e - x;
  }
  wt(ans + x * k);
}
