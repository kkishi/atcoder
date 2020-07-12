#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int main() {
  int N;
  cin >> N;

  switch (N % 10) {
    case 2:
    case 4:
    case 5:
    case 7:
    case 9:
      cout << "hon";
      break;
    case 0:
    case 1:
    case 6:
    case 8:
      cout << "pon";
      break;
    default:
      cout << "bon";
      break;
  }
  cout << endl;
}
