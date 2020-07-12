#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int p[100000];
int q[100000];
int r[100000];

int main() {
  int X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;
  REP(i, A) cin >> p[i];
  REP(i, B) cin >> q[i];
  REP(i, C) cin >> r[i];

  sort(p, p + A);
  sort(q, q + B);
  sort(r, r + C);

  int ai = A - X;
  int bi = B - Y;
  int ci = C;
  while (true) {
    if (ci == 0) {
      break;
    }
    bool a = ai < A && p[ai] < r[ci - 1];
    bool b = bi < B && q[bi] < r[ci - 1];
    if (!a && !b) {
      break;
    }
    if (a && (!b || p[ai] < q[bi])) {
      ++ai;
    } else {
      ++bi;
    }
    --ci;
  }

  long long ans = 0;
  for (int i = ai; i < A; ++i) {
    ans += p[i];
  }
  for (int i = bi; i < B; ++i) {
    ans += q[i];
  }
  for (int i = ci; i < C; ++i) {
    ans += r[i];
  }
  cout << ans << endl;
}
