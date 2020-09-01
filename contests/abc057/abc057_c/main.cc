#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
#define int ll
  ints(n);
  auto digits = [](int x) {
    int ret = 1;
    while (x > 9) {
      x /= 10;
      ++ret;
    }
    return ret;
  };
  int ans = numeric_limits<int>::max();
  for (int a = 1; a * a <= n; ++a) {
    if (n % a == 0) {
      chmin(ans, max(digits(a), digits(n / a)));
    }
  }
  wt(ans);
}
