#include <iostream>

using namespace std;

int main() {
  cout << 2000 << endl;
  for (int i = 0; i < 2000; ++i) {
    if (i > 0) cout << " ";
    cout << 1000000000;
  }
  cout << endl;
}
