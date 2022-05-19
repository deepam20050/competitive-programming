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

const int N = 1e5 + 5;

lli v[N];
lli t[N];

int main () {
  int n; scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%lld", v + i);
  }
  FOR(i, 1, n + 1) {
    scanf("%lld", t + i);
  }
  priority_queue < lli > pq;
  lli sum = 0;
  int siz = 0;
  FOR(i, 1, n + 1){
    pq.em(-v[i] - sum);
    lli ans = 0;
    auto del = sum;
    sum += t[i];
    while (!pq.empty() && -pq.top() <= sum) {
      ans += -pq.top() - del;
      pq.pop();
    }
    ans += t[i] * 1ll * sz(pq);
    printf("%lld ", ans);
  }
  return 0;
}
