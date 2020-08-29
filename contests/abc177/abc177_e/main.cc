#include <bits/stdc++.h>

#include "factorize.h"
#include "macros.h"

using namespace std;

int main() {
  ints(n);
  V<int> a(n);
  cin >> a;

  set<int> factors;
  bool pc = true;
  rep(i, n) {
    map<int, int> fs = Factorize(a[i]);
    for (auto [key, _] : fs) {
      if (!factors.insert(key).second) {
        pc = false;
      }
    }
  }
  if (pc) {
    wt("pairwise coprime");
    return 0;
  }
  int sgcd = a[0];
  rep(i, 1, n) sgcd = gcd(sgcd, a[i]);
  if (sgcd == 1) {
    wt("setwise coprime");
    return 0;
  }
  wt("not coprime");
}
