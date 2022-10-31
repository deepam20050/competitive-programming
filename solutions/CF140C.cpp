// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

vector < array < int, 3 > > ans;
map < int, int > cnt;
int n;
priority_queue < pii > pq;

void print () {
  printf("%d\n", sz(ans));
  for (auto &[a, b, c] : ans) {
    printf("%d %d %d\n", c, b, a);
  }
  exit(0);
}

int main () {
  scanf("%d", &n);
  vector < int > arr(n);
  FOR(i, 0, n) {
    scanf("%d", &arr[i]);
    ++cnt[arr[i]];
  }
  sort(all(arr));
  arr.erase(unique(all(arr)), arr.end());
  for (auto &e : arr) {
    pq.emplace(cnt[e], e);
  }
  while (!pq.empty()) {
    pii a[3];
    FOR(i, 0, 3) {
      a[i] = {-1, -1};
    }
    FOR(i, 0, 3) {
      if (pq.empty()) print();
      a[i] = pq.top();
      pq.pop();
    }
    FOR(i, 0, 3) {
      if (a[i].F == -1) {
        print();
      }
    }
    array < int, 3 > x;
    FOR(i, 0, 3) {
      --cnt[a[i].S];
      x[i] = a[i].S;
      if (cnt[a[i].S] == 0) continue;
      pq.emplace(cnt[a[i].S], a[i].S);
    }
    sort(all(x));
    ans.eb(x);
  }
  print();
  return 0;
}
