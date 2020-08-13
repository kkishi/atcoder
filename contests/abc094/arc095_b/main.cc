#include <bits/stdc++.h>

#include "macros.h"
#include "setmax.h"

using namespace std;

int main() {
  rd(int, n);
  V<int> a(n);
  rep(i, n) cin >> a[i];
  sort(all(a));
  int ai = a[n - 1];
  int aj, ajm = -1;
  rep(i, n - 1) if (Setmax(ajm, min(a[i], ai - a[i]))) aj = a[i];
  wt(ai, aj);
}
