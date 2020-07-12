#include <bits/stdc++.h>

template <typename T>
struct Edge {
  int from, to;
  T weight;
};

template <typename T>
class Graph {
 public:
  Graph(int n) : edges_(n) {}
  void AddEdge(int from, int to, T weight = T()) {
    edges_[from].push_back({from, to, weight});
  }
  const std::vector<Edge<T>>& Edges(int from) const { return edges_[from]; }
  int NumVertices() const { return edges_.size(); }

 private:
  std::vector<std::vector<Edge<T>>> edges_;
};

template <typename T>
std::vector<std::optional<T>> Dijkstra(const Graph<T>& graph, int start) {
  const int n = graph.NumVertices();

  std::vector<std::optional<T>> dist(n);

  using element = std::pair<T, int>;
  std::priority_queue<element, std::vector<element>, std::greater<>> que;

  auto push = [&dist, &que](int u, T c) {
    if (dist[u] && *dist[u] <= c) return;
    dist[u] = c;
    que.push({c, u});
  };

  push(start, 0);

  while (!que.empty()) {
    auto [c, u] = que.top();
    que.pop();
    for (const Edge<T>& e : graph.Edges(u)) {
      push(e.to, c + e.weight);
    }
  }

  return dist;
}

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

int main() {
  in(ll, n, m, t);
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  Graph<ll> g(n), rg(n);
  rep(i, m) {
    in(ll, a, b, c);
    --a, --b;
    g.AddEdge(a, b, c);
    rg.AddEdge(b, a, c);
  }
  vector<optional<ll>> dist = Dijkstra(g, 0);
  vector<optional<ll>> rdist = Dijkstra(rg, 0);
  ll ans = 0;
  rep(i, n) {
    if (!dist[i] || !rdist[i]) continue;
    ll rem = t - *dist[i] - *rdist[i];
    if (rem > 0) ans = max(ans, rem * a[i]);
  }
  out(ans);
}
