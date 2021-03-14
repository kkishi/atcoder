#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m);

  // p[i] = m^i
  V<mint> p(n + 1);
  p[0] = 1;
  rep(i, n) p[i + 1] = p[i] * m;

  // NOTE: These are defined outside of the loop just for optimization.
  vector L(n + 1, vector(2, mint(0)));
  vector R(n + 1, mint(0));

  mint sum = 0;
  rep(M, 1, m + 1) {
    // L[i][j]: The number of A with length i such that when a new element with
    // value M is added to the right,
    // - j=0: the new element requires another operation.
    // - j=1: the new element can be added without another operation (there's
    //        another element in A that can share the operation).
    L[0][0] = 1;
    L[0][1] = 0;
    rep(i, n) {
      L[i + 1][0] = L[i][0] * (m - 1) + L[i][1] * (M - 1);
      L[i + 1][1] = L[i][0] + L[i][1] * (m - M + 1);
    }

    // R[i]: The total number of elements, among all possible A with length i,
    // such that the elements can be created with the same operation.
    R[0] = 0;
    rep(i, n) R[i + 1] = R[i] * (m - M + 1) + p[i];

    // i is the left most element where an operation for M can begin.
    rep(i, n - 1) sum += L[i][0] * R[n - 1 - i];
  }
  wt(p[n] * n - sum);
}
