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
void Erase(Map& m, int v) {
  auto it = m.find(v);
  if (it->second > 1) {
    --it->second;
  } else {
    m.erase(it);
  }
}

int main() {
  in(int, n, q);
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  vector<map<int, int, greater<int>>> kg(kMax + 1);
  rep(i, n) kg[b[i]][a[i]]++;
  map<int, int> kgs;
  rep(i, kMax + 1) if (kg[i].size() > 0) {
    kgs[kg[i].begin()->first]++;
  }
  while (q--) {
    in(int, c, d);
    --c;
    auto& before = kg[b[c]];
    Erase(kgs, before.begin()->first);
    Erase(before, a[c]);
    if (!before.empty()) {
      kgs[before.begin()->first]++;
    }

    b[c] = d;

    auto& after = kg[b[c]];
    if (!after.empty()) {
      Erase(kgs, after.begin()->first);
    }
    after[a[c]]++;
    kgs[after.begin()->first]++;

    out(kgs.begin()->first);
  }
}
