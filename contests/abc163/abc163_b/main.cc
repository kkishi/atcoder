#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int A[10000];

int main() {
  int N, M;
  cin >> N >> M;

  REP(i, M) cin >> A[i];

  int sum = 0;
  REP(i, M) sum += A[i];

  if (sum > N) {
    cout << -1 << endl;
  } else {
    cout << N - sum << endl;
  }
}
