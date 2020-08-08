#include <bits/stdc++.h>

#include "bignum.h"
#include "macros.h"

using namespace std;

int N;
bigint A[100000];
ll kMax = 1000000000000000000;

int main() {
  cin >> N;
  rep(i, N) {
    cin >> A[i];
    if (A[i] == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  bigint ans = 1;
  rep(i, N) {
    ans *= A[i];
    if (ans > kMax) {
      cout << -1 << endl;
      return 0;
    }
  }
  wt(ans);
}
