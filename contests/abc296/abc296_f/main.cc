#include <bits/stdc++.h>

#include "atcoder.h"
#include "inversion_number.h"

bool Solve() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;
  V<int> A = a, B = b;
  sort(A);
  sort(B);
  if (A != B) return false;
  rep(i, n - 1) if (A[i] == A[i + 1]) return true;
  map<int, int> mp;
  rep(i, n) mp[a[i]] = i;
  rep(i, n) b[i] = mp[b[i]];
  return even(InversionNumber(b));
}

void Main() { wt(Solve()); }
