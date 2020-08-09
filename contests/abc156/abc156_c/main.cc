#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int N;
int X[100];

int cost(int i, int x) {
  int a = abs(X[i] - x);
  return a * a;
}

int main() {
  cin >> N;
  rep(i, N) cin >> X[i];

  int ans = 1000000000;
  for (int x = 1; x <= 100; ++x) {
    int total = 0;
    rep(i, N) total += cost(i, x);
    ans = min(ans, total);
  }
  cout << ans << endl;
}
