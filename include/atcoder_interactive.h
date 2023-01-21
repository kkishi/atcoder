#include <iomanip>

#include "constants.h"
#include "debug.h"
#include "fix.h"
#include "io.h"
#include "macros.h"

void Main();

int main() {
  std::cout << std::fixed << std::setprecision(20);
  yes_str = "YES", no_str = "NO";
  Main();
  return 0;
}

using namespace std;

#define int i64

#define wt_flush(...) \
  do {                \
    wt(__VA_ARGS__);  \
    cout.flush();     \
  } while (0)
