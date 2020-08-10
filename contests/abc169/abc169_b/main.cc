#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int N;
ll A[100000];
ll kMax = 1000000000000000000;

int main() {
  cin >> N;
  rep(i, N) {
    cin >> A[i];
    if (A[i] == 0) {
      cout << "0" << endl;
      return 0;
    }
  }
  ll ans = 1;
  rep(i, N) {
    if (A[i] > kMax / ans) {
      cout << -1 << endl;
      return 0;
    }
    ans *= A[i];
  }
  cout << ans << endl;
}
