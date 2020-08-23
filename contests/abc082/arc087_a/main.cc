#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  map<int, int> m;
  for (int ai : a) ++m[ai];
  int ans = 0;
  for (auto [k, v] : m) {
    if (k > v) {
      ans += v;
    } else {
      ans += v - k;
    }
  }
  wt(ans);
}
