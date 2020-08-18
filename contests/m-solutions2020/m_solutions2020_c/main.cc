#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  rep(i, k, n) wt(a[i] > a[i - k]);
}
