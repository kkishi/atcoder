#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int A[200000];

int main() {
  ints(N);
  rep(i, N) cin >> A[i];
  set<int> s(A, A + N);
  wt(s.size() == N ? "YES" : "NO");
}
