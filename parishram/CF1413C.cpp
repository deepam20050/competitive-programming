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

using lli = long long;
using pii = pair < int, int >;

const int M = 6;
const int N = 1e5 + 5;

int what[N];
int a[M];
int n;
vector < pii > v;

int main () {
  FOR(i, 0, M) scanf("%d", a + i); 
  scanf("%d", &n);
  FOR(i, 0, n) {
    int b;
    scanf("%d", &b);
    FOR(j, 0, M) {
      v.eb(b - a[j], i);
    }
  }
  sort(all(v));
  set < int > vals;
  multiset < int > place;
  FOR(i, 0, n) vals.em(i);
  int ans = 2e9;
  for(auto [x, pos] : v) {
    if (vals.find(pos) != vals.end()) {
      place.em(x);
      what[pos] = x;
      vals.erase(pos);
    } else {
      place.erase(place.lower_bound(what[pos]));
      place.em(x);
      what[pos] = x;
    }
    if (vals.empty()) {
      ans = min(ans, x - *place.begin());
    }
  }
  printf("%d\n", ans);
  return 0;
}
