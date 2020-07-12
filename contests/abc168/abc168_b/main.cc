#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int main() {
  int K;
  string S;
  cin >> K >> S;

  if (S.size() <= K) {
    cout << S << endl;
  } else {
    cout << S.substr(0, K);
    cout << "...";
    cout << endl;
  }
}
