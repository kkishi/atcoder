#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  int N;
  cin >> N;

  map<string, int> m;
  int maximum = 0;
  rep(i, N) {
    string s;
    cin >> s;
    m[s]++;
    maximum = max(maximum, m[s]);
  }

  for (const auto p : m) {
    if (p.second == maximum) cout << p.first << endl;
  }
}
