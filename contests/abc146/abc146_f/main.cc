#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n, m);
  rd(string, s);

  vector<int> v;
  int i = n;
  while (true) {
    int ni = max(0, i - m);
    while (s[ni] == '1' && ni < i) ++ni;
    if (ni == i) {
      cout << -1 << endl;
      return 0;
    }
    v.push_back(i - ni);
    i = ni;
    if (i == 0) {
      reverse(all(v));
      rep(i, v.size()) {
        if (i) cout << " ";
        cout << v[i];
      }
      cout << endl;
      return 0;
    }
  }
}
