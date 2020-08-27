#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
#define int ll
  auto rec = Fix([](auto rec, int d, int n) -> pair<int, int> {
    if (n == 0) return {0, 0};
    if (n == 1) return {0, d};
    if (n & 1) {
      auto [cnt, res] = rec(d, n - 1);
      int sum = res + d;
      if (sum < 10) return {cnt + 1, sum};
      return {cnt + 2, sum / 10 + sum % 10};
    }
    auto [cnt, res] = rec(d, n / 2);
    int sum = res + res;
    if (sum < 10) return {cnt * 2 + 1, sum};
    return {cnt * 2 + 2, sum / 10 + sum % 10};
  });
  ints(m);
  int carry = 0;
  int ans = 0;
  rep(m) {
    ints(d, c);
    auto [cnt, res] = rec(d, c);
    carry = carry * 10 + res;
    while (carry >= 10) {
      ++cnt;
      carry = carry / 10 + carry % 10;
    }
    ans += cnt;
  }
  wt(ans);
}
