// 1 based indexing
struct query {
  int id, l, r, lb, rb;
} q[Q];

int nq; cin >> nq;
for (int i = 0; i < nq; ++i) {
  int l, r; cin >> l >> r;
  q[i] = {i, l, r, l / SQN, r / SQN};
}
sort(q, q + nq, [&] (const query &a, const query &b) {
  if (a.lb != b.lb) return a.lb < b.lb;
  return a.lb & 1 ? a.r < b.r : a.r > b.r;
});
for (int i = 0, L = 1, R = 0; i < nq; ++i) {
  while (R < q[i].r) add_element(++R);
  while (L > q[i].l) add_element(--L);
  while (R > q[i].r) remove_element(R--);
  while (L < q[i].l) remove_element(L++);
  res[q[i].id] = ans;
}