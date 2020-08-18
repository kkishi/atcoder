#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(N);
  V<int> A(N);
  cin >> A;
  wt(sz(set<int>(all(A))) == N ? "YES" : "NO");
}
