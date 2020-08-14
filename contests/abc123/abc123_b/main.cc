#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  vector<int> v(5);
  cin >> v;
  auto ceil10 = [](int x) { return (x + 9) / 10 * 10; };
  sort(all(v), [&](int a, int b) { return ceil10(a) - a < ceil10(b) - b; });
  int t = 0;
  rep(i, 5) t = ceil10(t) + v[i];
  wt(t);
}
