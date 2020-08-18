#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int A[2 * 100000];

ll choose2(ll n) { return n * (n - 1) / 2; }

int main() {
  ints(N);
  map<int, int> m;
  rep(i, N) {
    cin >> A[i];
    m[A[i]]++;
  }
  ll total = 0;
  for (const auto it : m) {
    total += choose2(it.second);
  }
  rep(i, N) {
    ll n = m[A[i]];
    wt(total - choose2(n) + choose2(n - 1));
  }
}
