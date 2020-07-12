#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int main() {
  string N;
  cin >> N;
  for (int i = 0; i < N.size(); ++i) {
    if (N[i] == '7') {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
