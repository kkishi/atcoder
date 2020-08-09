#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int A[10000];

int main() {
  int N, M;
  cin >> N >> M;

  rep(i, M) cin >> A[i];

  int sum = 0;
  rep(i, M) sum += A[i];

  if (sum > N) {
    cout << -1 << endl;
  } else {
    cout << N - sum << endl;
  }
}
