#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  strings(a);
  rep(s, 1 << 3) {
    int sum = a[0] - '0';
    rep(i, 3) {
      if ((s >> i) & 1) {
        sum += a[i + 1] - '0';
      } else {
        sum -= a[i + 1] - '0';
      }
    }
    if (sum == 7) {
      cout << a[0];
      rep(i, 3) {
        cout << (((s >> i) & 1) ? '+' : '-');
        cout << a[i + 1];
      }
      cout << "=7" << endl;
      return 0;
    }
  }
}
