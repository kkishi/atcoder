#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int A[200000];
int B[200000];

int main() {
  rd(int, N);
  rep(i, N) cin >> A[i] >> B[i];
  sort(A, A + N);
  sort(B, B + N);
  if (N % 2 == 0) {
  } else {
    wt(B[N / 2] - A[N / 2] + 1);
  }
}
