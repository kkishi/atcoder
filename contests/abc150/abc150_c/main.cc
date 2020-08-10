#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int n;
int p[8], q[8];

int count(int a[8]) {
  rep(i, n) dbg(a[i]);
  int x[8];
  rep(i, n) x[i] = i + 1;
  int c = 0;
  do {
    bool ok = true;
    rep(i, n) if (x[i] != a[i]) ok = false;
    if (ok) {
      return c;
    }
    ++c;
  } while (next_permutation(x, x + n));
}

int main() {
  cin >> n;
  rep(i, n) cin >> p[i];
  rep(i, n) cin >> q[i];
  wt(abs(count(p) - count(q)));
}
