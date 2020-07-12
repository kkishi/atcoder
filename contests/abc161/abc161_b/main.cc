#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int A[100];

int main() {
  int N, M;
  cin >> N >> M;
  int sum = 0;
  REP(i, N) {
    cin >> A[i];
    sum += A[i];
  }
  sort(A, A + N);
  if (A[N - 1 - (M - 1)] * 4 * M >= sum) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
