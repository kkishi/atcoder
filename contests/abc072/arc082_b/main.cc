#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  V<int> p(n);
  cin >> p;
  int ans = 0;
  rep(i, n - 1) if (p[i] == i + 1) {
    swap(p[i], p[i + 1]);
    ++ans;
  }
  if (p[n - 1] == n) {
    swap(p[n - 2], p[n - 1]);
    ++ans;
  }
  wt(ans);
}
