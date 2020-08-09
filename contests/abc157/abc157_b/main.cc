#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int A[3][3];

bool bingo() {
  rep(i, 3) {
    bool ok = true;
    rep(j, 3) if (A[i][j] > 0) ok = false;
    if (ok) return true;
  }
  rep(i, 3) {
    bool ok = true;
    rep(j, 3) if (A[j][i] > 0) ok = false;
    if (ok) return true;
  }
  {
    bool ok = true;
    rep(i, 3) {
      if (A[i][i] > 0) ok = false;
    }
    if (ok) return true;
  }
  {
    bool ok = true;
    rep(i, 3) {
      if (A[i][2 - i] > 0) ok = false;
    }
    if (ok) return true;
  }
  return false;
}

int main() {
  rep(i, 3) rep(j, 3) cin >> A[i][j];
  int N;
  cin >> N;
  rep(n, N) {
    int b;
    cin >> b;
    rep(i, 3) rep(j, 3) if (A[i][j] == b) A[i][j] = 0;
  }
  cout << (bingo() ? "Yes" : "No") << endl;
}
