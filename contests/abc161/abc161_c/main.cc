#include <bits/stdc++.h>

using namespace std;

int main() {
  long long N, K;
  cin >> N >> K;
  N %= K;
  cout << min(abs(N - K), N) << endl;
}
