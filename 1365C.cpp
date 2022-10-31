#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
  #include "../algo/debug.hpp"
#else
  #define debug(...)
#endif
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back

using lli = long long;
using pii = pair < int, int >;

int n;

int dist (int x, int y) {
  y -= x;
  if (y < 0) y += n;
  return y >= n ? y -= n : y;
}

void test_case() {
  cin >> n;
  vector < int > a(n), b(n);
  for (auto &e : a) {
    cin >> e;
    --e;
  }
  vector < int > pos(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    --b[i];
    pos[b[i]] = i;
  }
  vector < int > left(n), right(n);
  for (int i = 0; i < n; ++i) {
    left[i] = dist(i, pos[a[i]]);
    right[i] = dist(pos[a[i]], i);
  }
  vector < int > freq(n);
  vector < int > freq2(n);
  for (int i = 0; i < n; ++i) {
    ++freq[left[i]];
    ++freq2[right[i]];
  }
  cout << max(*max_element(all(freq)), *max_element(all(freq2))) << '\n';
}

int main() {
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}