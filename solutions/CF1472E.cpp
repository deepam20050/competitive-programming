#include "bits/stdc++.h"

using namespace std;

using pii = pair < int, pair < int, int > > ;

const int N = 2e5 + 5;

pii a1[N], a2[N];
pair < int ,int > mini_h[N], mini_w[N];
int ans[N];

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      int h, w;
      scanf("%d %d", &h, &w);
      a1[i] = {h, {w, i}};
      a2[i] = {w, {h, i}};
    }
    sort(a1 + 1, a1 + n + 1);
    sort(a2 + 1, a2 + n + 1);
    int mini = 1e9, mini2 = 1e9, idx = -1, idx2 = -1;
    for (int i = 1; i <= n; ++i) {
      if (a1[i].second.first < mini) {
        idx = a1[i].second.second;
        mini_w[i].first = a1[i].second.first;
        mini_w[i].second = idx;
        mini = a1[i].second.first;
      } else {
        mini_w[i].first = mini;
        mini_w[i].second = idx;
      }
      if (a2[i].second.first < mini2) {
        idx2 = a2[i].second.second;
        mini_h[i].first = a2[i].second.first;
        mini_h[i].second = idx2;
        mini2 = a2[i].second.first;
      } else {
        mini_h[i].first = mini2;
        mini_h[i].second = idx2;
      }
    }
    // cout << "A1s --> \n";
    // for (int i = 1; i <= n; ++i) {
    //   cout << a1[i].first << " " << a1[i].second.first << '\n';
    // }
    // cout << "A2s --> \n";
    // for (int i = 1; i <= n; ++i) {
    //   cout << a2[i].first << " " << a2[i].second.first << '\n';
    // }
    // cout << " \n";
    for (int i = 1; i <= n; ++i) {
      int h = a1[i].first, w = a1[i].second.first;
      int find1 = lower_bound(a1, a1 + n + 1, make_pair(h, make_pair(-1, -1))) - a1 - 1;
      int find2 = lower_bound(a2, a2 + n + 1, make_pair(h, make_pair(-1, -1))) - a2 - 1;
      ans[a1[i].second.second] = -1;
      // cout << h << " " << w << " " << find1 << " " << mini_h[find2].first << '\n';;
      if (find1 > 0 && mini_w[find1].first < w && a1[find1].first < h) {
        ans[a1[i].second.second] = mini_w[find1].second;
        continue;
      }
      if (find2 > 0 && mini_h[find2].first < w && a2[find2].first < h) {
        ans[a1[i].second.second] = mini_h[find2].second;
        continue;
      }
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d ", ans[i]);
    }
    puts("");
  }
  return 0;
}
