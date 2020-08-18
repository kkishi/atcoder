#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  sort(all(a));
  int ai = a[n - 1];
  int aj, ajm = -1;
  rep(i, n - 1) if (chmax(ajm, min(a[i], ai - a[i]))) aj = a[i];
  wt(ai, aj);
}
