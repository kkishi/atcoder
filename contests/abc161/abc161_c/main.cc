#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int main() {
  long long N, K;
  cin >> N >> K;
  N %= K;
  cout << min(abs(N - K), N) << endl;
}
