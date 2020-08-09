#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int p[200000];

double exp(int i) { return p[i] * (p[i] + 1) / 2 / (double)(p[i]); }

int main() {
  rd(int, N, K);
  rep(i, N) cin >> p[i];
  double sum = 0;
  rep(i, K) sum += exp(i);
  double ans = sum;
  for (int i = K; i < N; ++i) {
    sum -= exp(i - K);
    sum += exp(i);
    ans = max(ans, sum);
  }
  cout << setprecision(20);
  wt(ans);
}
