#include <bits/stdc++.h>

#include "atcoder.h"

template <typename T, std::size_t N, std::size_t M>
using Matrix = std::array<std::array<T, M>, N>;

template <typename T, std::size_t N, std::size_t M, std::size_t L>
Matrix<T, N, M> Mult(const Matrix<T, N, L>& a, const Matrix<T, L, M>& b) {
  Matrix<T, N, M> c{};
  for (std::size_t i = 0; i < N; ++i) {
    for (std::size_t j = 0; j < M; ++j) {
      for (std::size_t k = 0; k < L; ++k) {
        c[i][j] ^= a[i][k] & b[k][j];
      }
    }
  }
  return c;
}

template <typename T, std::size_t N>
Matrix<T, N, N> Pow(const Matrix<T, N, N>& x, int64_t y) {
  Matrix<T, N, N> a = {}, b = x;
  for (std::size_t i = 0; i < N; ++i) {
    a[i][i] = ~0;
  }
  for (; y; y >>= 1) {
    if (y & 1) {
      a = Mult(a, b);
    }
    b = Mult(b, b);
  }
  return a;
}

using M = Matrix<uint32_t, 100, 100>;
using A = Matrix<uint32_t, 100, 1>;

void Main() {
  ints(k, m);
  V<uint32_t> a(k), c(k);
  cin >> a >> c;
  if (m <= k) {
    wt(a[m - 1]);
    return;
  }
  M mat{};
  rep(i, k) mat[0][i] = c[i];
  rep(i, 1, k) mat[i][i - 1] = ~0;
  A ini{};
  rep(i, k) ini[i][0] = a[k - 1 - i];
  A ans = Mult(Pow(mat, m - k), ini);
  wt(ans[0][0]);
}
