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

template <typename T>
class RangeSegmentTree {
 public:
  using Operation = std::function<T(T, T)>;
  using RangeOperation = std::function<T(T, int)>;

  RangeSegmentTree(
      int size, Operation operation, T identity = T(),
      RangeOperation range_operation = [](T v, int) { return v; })
      : operation_(operation),
        identity_(identity),
        range_operation_(range_operation) {
    int two = 1;
    while (two < size) {
      two <<= 1;
    }
    v_.resize(two * 2 - 1, identity_);
    l_.resize(two * 2 - 1, identity_);
  }

  void Apply(int begin, int end, T v) {
    std::function<void(int, int, int)> rec = [&](int cbegin, int cend,
                                                 int index) {
      if (begin <= cbegin && cend <= end) {
        l_[index] = operation_(l_[index], v);
        return;
      }
      if (cend <= begin || end <= cbegin) {
        return;
      }
      int cmid = (cbegin + cend) / 2;
      rec(cbegin, cmid, index * 2 + 1);
      rec(cmid, cend, index * 2 + 2);
      int size = std::min(cend, end) - std::max(cbegin, begin);
      v_[index] = operation_(v_[index], range_operation_(v, size));
    };
    rec(0, (v_.size() + 1) / 2, 0);
  }

  T Get(int i) const { return Aggregate(i, i + 1); }
  T Aggregate(int begin, int end) const {
    std::function<T(int, int, int)> rec = [&](int cbegin, int cend, int index) {
      int size = std::min(cend, end) - std::max(cbegin, begin);
      if (begin <= cbegin && cend <= end) {
        return operation_(v_[index], range_operation_(l_[index], size));
      }
      if (cend <= begin || end <= cbegin) {
        return identity_;
      }
      int cmid = (cbegin + cend) / 2;
      return operation_(operation_(rec(cbegin, cmid, index * 2 + 1),
                                   rec(cmid, cend, index * 2 + 2)),
                        range_operation_(l_[index], size));
    };
    return rec(0, (v_.size() + 1) / 2, 0);
  }

 private:
  const Operation operation_;
  const T identity_;
  const RangeOperation range_operation_;
  std::vector<T> v_;
  std::vector<T> l_;
};

template <typename T>
RangeSegmentTree<T> AdditiveSegmentTree(int size) {
  auto add = [](T a, T b) { return a + b; };
  auto mul = [](T v, int size) { return v * size; };
  return RangeSegmentTree<T>(size, add, T(), mul);
}

int main() {
  in(int, n, m);
  RangeSegmentTree tree = AdditiveSegmentTree<int>(n);
  rep(i, m) {
    in(int, l, r);
    tree.Apply(l - 1, r, 1);
  }
  int ans = 0;
  rep(i, n) if (tree.Get(i) == m)++ ans;
  out(ans)
}
