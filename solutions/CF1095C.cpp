#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define lb lower_bound
#define ub upper_bound

using lli = long long;
using pii = pair < int, int >;

int main () {
  int n, k; scanf("%d %d", &n, &k);
  int c = __builtin_popcount(n);
  if (k < c) {
    puts("NO");
    return 0;
  }
  priority_queue < int > pq;
  for (int i = 29; i >= 0; --i) {
    if (n >> i & 1) {
      pq.em(1 << i);
    }
  }
  while (sz(pq) < k) {
    int x = pq.top();
    pq.pop();
    if (x == 1) {
      break;
    }
    x >>= 1;
    pq.em(x);
    pq.em(x);
  }
  if (sz(pq) < k) {
    puts("NO");
    return 0;
  }
  puts("YES");
  while (!pq.empty()) {
    printf("%d ", pq.top());
    pq.pop();
  }
  return 0;
}
