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

struct State {
  ull must;
  ull mustnot;
};

State mat[kMax][kMax];

int main() {
  cin >> N;
  REP(i, N) cin >> S[i];
  REP(i, N) cin >> T[i];
  REP(i, N) cin >> U[i];
  REP(i, N) cin >> V[i];

  bool ok = true;
  REP(r, N) {
    REP(c, N) {
      State& s = mat[r][c];
      s.must = 0;
      s.mustnot = 0;

      /*
      cout << S[r] << " " << T[c] << endl;
      cout << U[r] << " " << bitset<8>(U[r]) << " " << bitset<8>(~U[r]) << endl;
      cout << V[c] << " " << bitset<8>(V[c]) << " " << bitset<8>(~V[c]) << endl;
      */

      if (S[r] == 0) {
        s.must |= U[r];
      } else {
        s.mustnot |= ~U[r];
      }
      if (T[c] == 0) {
        s.must |= V[c];
      } else {
        s.mustnot |= ~V[c];
      }

      cout << r << " " << c << ": ";
      cout << "must:" << bitset<8>(s.must)
           << " mustnot:" << bitset<8>(s.mustnot) << endl;

      if (s.must & s.mustnot) {
        ok = false;
      }
    }
  }
  REP(r, N) {
    u[r] = mat[r][0].must;
    REP(c, N) {
      if (S[r] == 0)
        u[r] &= mat[r][c].must;
      else
        u[r] |= mat[r][c].must;
      // u[r] |= mat[r][c].must;
    }
    cout << "must u: " << r << " " << bitset<8>(u[r]) << endl;
  }
  REP(c, N) {
    v[c] = mat[0][c].must;
    REP(r, N) {
      if (T[c] == 0)
        v[c] &= mat[r][c].must;
      else
        v[c] |= mat[r][c].must;
      // v[c] |= mat[r][c].must;
    }
    cout << "must v: " << c << " " << bitset<8>(v[c]) << endl;
    ;
  }
  if (ok) {
    /*
    REP(r, N) {
      ull x = 0;
      REP(c, N) x |= ~mat[r][c].mustnot;
      cout << x << endl
      REP(c, N) x &= mat[r][c].must;
      cout << x << endl;
    }
    */
    REP(r, N) {
      REP(c, N) {
        const State& s = mat[r][c];
        ull want = U[r] | V[c];
        cout << "want     " << r << " " << c << " " << bitset<8>(want) << endl;
        cout << "must     " << r << " " << c << " " << bitset<8>(s.must)
             << endl;
        cout << "must not " << r << " " << c << " " << bitset<8>(s.mustnot)
             << endl;
        cout << "optional " << r << " " << c << " "
             << bitset<8>(~s.must & ~s.mustnot) << endl;
        ull want2 = (U[r] | V[c]) & ~(u[r] | v[c]);
        cout << bitset<8>(want2) << endl;
        // cout << r << " " << c << " " << want << endl;
        // cout << (want & (~s.mustnot));
      }
    }

    REP(r, N) {
      REP(c, N) {
        if (c > 0) cout << " ";
        const State& s = mat[r][c];

        ull want = (U[r] | V[c]) & ~(u[r] | v[c]);
        // cout << bitset<8>(want) << endl;
        /*
        if (S[r] == 0) {
          want |= U[r];
        }
        if (T[c] == 0) {
          want |= V[c];
        }
        */

        // ull want = U[r] | V[c];
        // ull want = u[r] | v[c];
        // cout << r << " " << c << " " << want << endl;
        cout << (s.must | (want & (~s.mustnot)));
      }
      cout << endl;
    }
  } else {
    cout << -1 << endl;
  }
}
