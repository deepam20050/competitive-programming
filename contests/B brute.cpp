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

void print (int x, vector < int > v) {
  cout << x << " : ";
  for (auto &e : v) {
    cout << e << " ";
  }
  puts("");
}

int main () {
  int n;
  scanf("%d", &n);
  vector < int > v(n);
  for (auto &e : v) {
    scanf("%d", &e);
  }
  print(0, v);
  FOR(i, 1, 20) {
    for (int i = 1; i < n; ++i) {
      v[i] ^= v[i - 1];
    }
    print(i, v);
  }
  return 0;
}
