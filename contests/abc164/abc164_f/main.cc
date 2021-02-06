#include <bits/stdc++.h>

#include "atcoder.h"

typedef unsigned long long ull;
const int kMax = 500;
int N;
ull S[kMax];
ull T[kMax];
ull U[kMax];
ull V_[kMax];

ull u[kMax];
ull v[kMax];

// -1 unknown
int mat[kMax][kMax];

bool solve(ull bit) {
  rep(r, N) {
    rep(c, N) {
      ull u = U[r] & bit;
      ull v = V_[c] & bit;
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
  rep(r, N) {
    if (S[r] == 0 && (U[r] & bit) == 0) {
      bool ok = false;
      rep(c, N) if (mat[r][c] == 0) { ok = true; }
      if (!ok)
        --R;
      else
        rep(c, N) if (mat[r][c] == -1) mat[r][c] = 1;
    } else if (S[r] == 1 && (U[r] & bit) == bit) {
      bool ok = false;
      rep(c, N) if (mat[r][c] == 1) { ok = true; }
      if (!ok)
        ++R;
      else
        rep(c, N) if (mat[r][c] == -1) mat[r][c] = 0;
    }
  }
  int C = 0;
  rep(c, N) {
    if (T[c] == 0 && (V_[c] & bit) == 0) {
      bool ok = false;
      rep(r, N) if (mat[r][c] == 0) { ok = true; }
      if (!ok)
        --C;
      else
        rep(r, N) if (mat[r][c] == -1) mat[r][c] = 1;
    } else if (T[c] == 1 && (V_[c] & bit) == bit) {
      bool ok = false;
      rep(r, N) if (mat[r][c] == 1) { ok = true; }
      if (!ok)
        ++C;
      else
        rep(r, N) if (mat[r][c] == -1) mat[r][c] = 0;
    }
  }
  int done = 0;
  rep(r, N) rep(c, N) if (mat[r][c] == -1) {
    int seen = 0;
    rep(c2, N) if (mat[r][c2] == -1) {
      mat[r][c2] = (done + seen) % 2;
      ++seen;
    }
    ++done;
  }
  // Check
  rep(r, N) {
    int x = mat[r][0];
    rep(c, N) {
      if (S[r] == 0)
        x &= mat[r][c];
      else
        x |= mat[r][c];
    }
    if (x != ((U[r] & bit) != 0)) return false;
  }
  rep(c, N) {
    int x = mat[0][c];
    rep(r, N) {
      if (T[c] == 0)
        x &= mat[r][c];
      else
        x |= mat[r][c];
    }
    if (x != ((V_[c] & bit) != 0)) return false;
  }
  return true;
}

void Main() {
  cin >> N;
  rep(i, N) cin >> S[i];
  rep(i, N) cin >> T[i];
  rep(i, N) cin >> U[i];
  rep(i, N) cin >> V_[i];

  ull bit = 1;
  vector ans(N, vector(N, ull(0)));
  rep(b, 64) {
    if (!solve(bit)) {
      cout << -1 << endl;
      return;
    }
    rep(r, N) rep(c, N) if (mat[r][c] == 1) ans[r][c] |= bit;
    bit <<= 1;
  }
  each(a, ans) wt(a);
}
