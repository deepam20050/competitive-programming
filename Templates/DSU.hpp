struct DSU {
  int size[N];
  int p[N];
  void init (int n) {
    iota(init, init + n + 1, 0);
  }
  inline int get (int a) {
    return (p[a] == a) ? a : p[a] = get(p[a]);
  }
  inline bool join (int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return 0;
    if (size[a] < size[b]) {
      swap(a, b);
    }
    size[a] += size[b];
    p[b] = a;
    return 1;
  }
};