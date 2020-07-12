#include <algorithm>
#include <iostream>
#include <vector>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

long long A[2000];

long long absolute(long long x) { return x < 0 ? -x : x; }

int main() {
  int N;
  cin >> N;
  REP(i, N) cin >> A[i];

  vector<int> indice(N);
  REP(i, N) indice[i] = i;
  long long ans = 0;
  do {
    long long sum = 0;
    REP(i, N) sum += A[i] * absolute(i - indice[i]);
    if (ans < sum) {
      ans = sum;
      /*
      REP(i, N) REP(j, N) if (indice[j] == i) cout << A[j] << " ";
      cout << endl;
      */
    }
  } while (next_permutation(indice.begin(), indice.end()));
  cout << ans << endl;
}
