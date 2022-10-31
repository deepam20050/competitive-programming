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

const int N = 1005;

string str, rest;
int n, lol, k;
string ans[N];

void solve (int l, int r, int idx, deque < char > tmp) {
  if (l > r || idx == lol || tmp.empty()) return;
  FOR(i, l, r + 1) {
    ans[i] += tmp.front();
    tmp.pop_front();
  }
  if (tmp.empty()) return;
  int lst = l;
  FOR(i, l, r + 2) {
    if ((i == r + 1) || (ans[i][idx] != ans[lst][idx])) {
      int l_ = lst;
      int r_ = i - 1;
      deque < char > x;
      int cnt = (r_ - l_ + 1) * (lol - idx - 1);
      FOR(kk, 0, cnt) {
        x.emplace_front(tmp.back());
        tmp.pop_back();
      }
      solve(l_, r_, idx + 1, x);
      lst = i;
    }
  }
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> lol >> k;
  cin >> str;
  sort(all(str));
  deque < char > take;
  FOR(i, 0, lol * k) take.eb(str[i]);
  solve(0, k - 1, 0, take);
  FOR(i, 0, k) {
    cout << ans[i] << '\n';
  }
  FOR(i, k, n) {
    cout << str.substr(i * lol, lol) << '\n';
  }
  return 0;
}
