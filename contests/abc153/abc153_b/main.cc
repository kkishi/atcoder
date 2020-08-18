#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, H, N);
  V<ll> A(N);
  cin >> A;
  wt(accumulate(all(A), 0) >= H);
}
