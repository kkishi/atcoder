#include <bits/stdc++.h>

// #undef DEBUG  // Uncomment this line to forcefully disable debug print.
#if DEBUG
template <typename T>
void debug(T value) {
  std::cerr << value;
}
template <typename T, typename... Ts>
void debug(T value, Ts... args) {
  std::cerr << value << ", ";
  debug(args...);
}
#define dbg(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define dbg(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define in(type, ...) \
  type __VA_ARGS__;   \
  read_from_cin(__VA_ARGS__);

template <typename T>
void write_to_cout(const T& value) {
  std::cout << value << std::endl;
}
template <typename T, typename... Ts>
void write_to_cout(const T& value, const Ts&... args) {
  std::cout << value << ' ';
  write_to_cout(args...);
}
#define out(...) write_to_cout(__VA_ARGS__);

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

const int kMax = 200000;

template <typename Map>
void Erase(Map& m, int value) {
  m.erase(m.find(value));
}

int main() {
  in(int, n, q);
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  vector<multiset<int, greater<int>>> kg(kMax + 1);
  rep(i, n) kg[b[i]].insert(a[i]);
  multiset<int> kgs;
  rep(i, kMax + 1) if (kg[i].size() > 0) {
    kgs.insert(*kg[i].begin());
  }
  while (q--) {
    in(int, c, d);
    --c;
    auto& before = kg[b[c]];
    Erase(kgs, *before.begin());
    Erase(before, a[c]);
    if (!before.empty()) {
      kgs.insert(*before.begin());
    }

    b[c] = d;

    auto& after = kg[b[c]];
    if (!after.empty()) {
      Erase(kgs, *after.begin());
    }
    after.insert(a[c]);
    kgs.insert(*after.begin());

    out(*kgs.begin());
  }
}
