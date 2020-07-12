#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int A[2 * 100000];
int B[2 * 100000];

int main() {
  int N;
  cin >> N;

  REP(i, N) {
    cin >> A[i];
    B[A[i] - 1]++;
  }

  REP(i, N) cout << B[i] << endl;
}
