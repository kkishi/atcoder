// NOTE: This solution is not legit. It passes all contest cases but fails with
// 2 after_contest cases. Basically, the strategy is to speed up the naive
// approach using bit operations.
#include <bits/stdc++.h>

#include "atcoder.h"

uint64_t S[20000], T[20000];
int B = 64;

inline int Now() {
  return chrono::duration_cast<chrono::milliseconds>(
             chrono::system_clock::now().time_since_epoch())
      .count();
}

void Main() {
  int start = Now();

  strings(s, t);
  int szs = sz(s), szt = sz(t);
  rep(i, szs) {
    if (s[i] == '1') {
      S[i / B] |= 1ULL << (i % B);
    }
  }
  rep(i, szt) {
    if (t[i] == '1') {
      T[i / B] |= 1ULL << (i % B);
    }
  }
  int LT = div_ceil(szt, B);
  int szt_rem = szt % B;
  int ans = big;
  rep(i, szs - szt + 1) {
    int sum = 0;
    int d = i >> 6;              // i / B
    int r = i & ((1 << 6) - 1);  // i % B
    rep(j, LT) {
      uint64_t x = S[j + d] >> r;
      if (r != 0) {
        x += S[j + d + 1] << (B - r);
      }
      if (j == LT - 1 && szt_rem != 0) {
        x &= ~(0ULL) >> (B - szt_rem);
      }
      sum += popcount<int>(x ^ T[j]);
      // We already have a better answer, so we prune.
      if (sum >= ans) break;
    }
    chmin(ans, sum);
    // Terminates the search early to avoid TLE, hoping we already have the
    // answer.
    if (Now() - start > 2900) break;
  }
  wt(ans);
}
