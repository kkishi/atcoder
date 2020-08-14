#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int main() {
  int N, K, C;
  cin >> N >> K >> C;
  string S;
  cin >> S;

  vector<int> earliest;
  int d = 0;
  rep(i, K) {
    while (S[d] == 'x') ++d;
    // cout << i << " " << d << endl;
    earliest.push_back(d);
    d += C + 1;
  }

  vector<int> latest;
  d = N - 1;
  rep(i, K) {
    while (S[d] == 'x') --d;
    // cout << i << " " << d << endl;
    latest.push_back(d);
    d -= C + 1;
  }

  rep(i, K) if (earliest[i] == latest[latest.size() - 1 - i]) {
    cout << earliest[i] + 1 << endl;
  }
}
