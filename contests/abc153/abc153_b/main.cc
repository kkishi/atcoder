#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

ll A[100000];

int main() {
  rd(ll, H, N);
  rep(i, N) cin >> A[i];
  ll sum = 0;
  rep(i, N) sum += A[i];
  wt(sum >= H);
}
