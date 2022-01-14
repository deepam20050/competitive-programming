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

const int N = 1e5 + 5;

int n;
vector < pii > vec; 
vector < int > ones;
int arr[N];

int main () {
  scanf("%d", &n);
  FOR(i, 0, n) {
    scanf("%d", arr + i);
  }
  int lst = arr[0], cnt = 0;
  FOR(i, 0, n + 1) {
    if ((i == n) || (arr[i] != lst)) {
      vec.eb(lst, cnt);
      lst = arr[i];
      cnt = 1;
    } else {
      ++cnt;
    }
  }
  for (auto [val, cnt] : vec) {
    if (cnt > 1) {
      ones.eb(val);
    }
  }
  ones.erase(unique(all(ones)), ones.end());
  printf("%d\n", sz(ones) + sz(vec));
  return 0;
}
