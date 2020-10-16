#include <bits/stdc++.h>

#include "atcoder.h"

int A[200000];
int B[200000];

void Main() {
  ints(N);
  rep(i, N) cin >> A[i] >> B[i];
  sort(A, A + N);
  sort(B, B + N);
  if (N % 2 == 0) {
  } else {
    wt(B[N / 2] - A[N / 2] + 1);
  }
}
