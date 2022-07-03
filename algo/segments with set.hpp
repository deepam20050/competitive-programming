/* Rough code for merging segments in a suitable range (~10^5)
 * using STL set in O(n log n) time
 */

set < int > s;

for (int i = 1; i <= n; ++i) {
  s.emplace(i);
}

int l, r; cin >> l >> r;
auto it2 = s.lower_bound(r);
for (auto i = s.lower_bound(l); i != it2; i = s.erase(i)) {
  // merge segments using DSU
}

/* Code for merging segments with set
 */