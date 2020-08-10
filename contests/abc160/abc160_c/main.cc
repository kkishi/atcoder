#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int A[2 * 100000];

int main() {
  int K, N;
  cin >> K >> N;
  rep(i, N) cin >> A[i];
  int maximum = 0;
  rep(i, N - 1) maximum = max(maximum, A[i + 1] - A[i]);
  cout << K - max(maximum, K - A[N - 1] + A[0]) << endl;
}
