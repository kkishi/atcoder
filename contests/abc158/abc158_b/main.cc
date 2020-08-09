#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  cout << N / (A + B) * A + min(N % (A + B), A) << endl;
}
