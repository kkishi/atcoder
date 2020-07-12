#include <ctime>
#include <iostream>
#include <random>

using namespace std;

int main() {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(
      1, 1000000000);  // distribution in range [1, 6]

  cout << 10 << endl;
  for (int i = 0; i < 10; ++i) {
    if (i > 0) cout << " ";
    cout << dist6(rng);
  }
  cout << endl;
}
