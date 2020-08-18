#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(N, M);
  V<int> A(M);
  cin >> A;
  int sum = accumulate(all(A), 0);
  wt(sum > N ? -1 : (N - sum));
}
