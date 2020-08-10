#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int N;
int A[100];

int main() {
  cin >> N;
  rep(i, N) cin >> A[i];

  bool ok = true;
  rep(i, N) if (A[i] % 2 == 0 && (A[i] % 3 != 0 && A[i] % 5 != 0)) {
    dbg(A[i]);
    ok = false;
  }

  if (ok) {
    cout << "APPROVED" << endl;
  } else {
    cout << "DENIED" << endl;
  }
}
