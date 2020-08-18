#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(K, N);
  V<int> A(N);
  cin >> A;
  int maxi = 0;
  rep(i, N - 1) chmax(maxi, A[i + 1] - A[i]);
  wt(K - max(maxi, K - A[N - 1] + A[0]));
}
