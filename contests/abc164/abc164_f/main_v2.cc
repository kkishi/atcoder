#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

typedef unsigned long long ull;
const int kMax = 500;
int N;
ull S[kMax];
ull T[kMax];
ull U[kMax];
ull V[kMax];

ull u[kMax];
ull v[kMax];

// -1 unknown
int mat[kMax][kMax];

bool solve(ull bit) {
  // cout << bit << endl;
  REP(r, N) {
    REP(c, N) {
      ull u = U[r] & bit;
      ull v = V[c] & bit;
      int uw;
      if (S[r] == 0) {
        if (u == 0) {
          // Want 0.
          uw = -1;
        } else {
          uw = 1;
        }
      } else {
        if (u == 0) {
          uw = 0;
        } else {
          // Want 1.
          uw = -2;
        }
      }
      int vw;
      if (T[c] == 0) {
        if (v == 0) {
          vw = -1;
        } else {
          vw = 1;
        }
      } else {
        if (v == 0) {
          vw = 0;
        } else {
          vw = -2;
        }
      }
      if (uw >= 0 && vw >= 0) {
        if (uw != vw) {
          return false;
        } else {
          mat[r][c] = uw;
        }
      } else if (uw >= 0) {
        mat[r][c] = uw;
      } else if (vw >= 0) {
        mat[r][c] = vw;
      } else if (uw == vw) {
        mat[r][c] = uw == -1 ? 0 : 1;
        ;
      } else {
        mat[r][c] = -1;
      }
    }
  }
  int R = 0;
  REP(r, N) {
    if (S[r] == 0 && (U[r] & bit) == 0) {
      bool ok = false;
      REP(c, N) if (mat[r][c] == 0) { ok = true; }
      if (!ok)
        --R;
      else
        REP(c, N) if (mat[r][c] == -1) mat[r][c] = 1;
    } else if (S[r] == 1 && (U[r] & bit) == bit) {
      bool ok = false;
      REP(c, N) if (mat[r][c] == 1) { ok = true; }
      if (!ok)
        ++R;
      else
        REP(c, N) if (mat[r][c] == -1) mat[r][c] = 0;
    }
  }
  int C = 0;
  REP(c, N) {
    if (T[c] == 0 && (V[c] & bit) == 0) {
      bool ok = false;
      REP(r, N) if (mat[r][c] == 0) { ok = true; }
      if (!ok)
        --C;
      else
        REP(r, N) if (mat[r][c] == -1) mat[r][c] = 1;
    } else if (T[c] == 1 && (V[c] & bit) == bit) {
      bool ok = false;
      REP(r, N) if (mat[r][c] == 1) { ok = true; }
      if (!ok)
        ++C;
      else
        REP(r, N) if (mat[r][c] == -1) mat[r][c] = 0;
    }
  }
  /*
  REP(r, N) {
    REP(c, N) cout << mat[r][c] << " ";
    cout << endl;
  }
  cout << R << " " << C << endl;
  */
  if (R == C) {
    return true;
  }
  if (R == 0) {
    REP(r, N)
    REP(c, N) if (mat[r][c] == -1) mat[r][c] = (V[c] & bit) != 0 ? 1 : 0;
    return true;
  }
  if (C == 0) {
    REP(r, N)
    REP(c, N) if (mat[r][c] == -1) mat[r][c] = (U[r] & bit) != 0 ? 1 : 0;
    return true;
  }
  if (R + C != 0) {
    return false;
  }
  REP(r, N) {
    REP(c, N) if (mat[r][c] == -1) {
      mat[r][c] = 0;
      REP(c2, N) if (mat[r][c2] == -1) mat[r][c2] = 1;
      REP(r2, N) if (mat[r2][c] == -1) mat[r2][c] = 1;
      break;
    }
  }
  /*
  REP(r, N) {
    REP(c, N) cout << mat[r][c] << " ";
    cout << endl;
  }
  cout << R << " " << C << endl;
  */
  return true;
}

ull ans[kMax][kMax];

int main() {
  cin >> N;
  REP(i, N) cin >> S[i];
  REP(i, N) cin >> T[i];
  REP(i, N) cin >> U[i];
  REP(i, N) cin >> V[i];

  ull bit = 1;
  REP(b, 64) {
    // REP(b, 3) {
    if (!solve(bit)) {
      cout << -1 << endl;
      return 0;
    }
    REP(r, N) REP(c, N) if (mat[r][c] == 1) ans[r][c] |= bit;
    bit <<= 1;
  }
  REP(r, N) {
    REP(c, N) {
      if (c) cout << " ";
      cout << ans[r][c];
    }
    cout << endl;
  }
}
