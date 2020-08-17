#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

ll solve(ll n, ll m) {
  if (n == 1 && m == 1) return 1;
  if (n == 1 || m == 1) return max(n, m) - 2;
  return (n - 2) * (m - 2);
}

int main() {
  rd(ll, n, m);
  wt(solve(n, m));
}
