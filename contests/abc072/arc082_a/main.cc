#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  map<int, int> m;
  rep(i, n) rep(j, -1, 2) m[a[i] + j]++;
  int ans = 0;
  for (auto [_, v] : m) chmax(ans, v);
  wt(ans);
}
