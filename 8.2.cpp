#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

struct SegmentTree
{
  vector<int> tree;
  int n;

  SegmentTree(const vector<int> &arr)
  {
    n = arr.size();
    tree.assign(4 * n, 0);
    build_tree(arr, 1, 0, n - 1);
  }

  void build_tree(const vector<int> &arr, int v, int tl, int tr)
  {
    if (tl == tr)
    {
      tree[v] = arr[tl];
    }
    else
    {
      int tm = (tl + tr) / 2;
      build_tree(arr, v * 2, tl, tm);
      build_tree(arr, v * 2 + 1, tm + 1, tr);
      tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
    }
  }

  int query(int v, int tl, int tr, int l, int r)
  {
    if (l > r)
      return INT_MAX;
    if (l == tl && r == tr)
      return tree[v];
    int tm = (tl + tr) / 2;
    return min(query(v * 2, tl, tm, l, min(r, tm)), query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }
};

int main()
{
  int n;
  cin » n;

  vector<int> A(n);
  for (int i = 0; i < n; i++)
  {
    cin » A[i];
  }

  SegmentTree segmentTree(A);

  while (true)
  {
    int start, end;
    if (!(cin » start » end))
    {
      break;
    }
    int result = segmentTree.query(1, 0, A.size() - 1, start, end - 1);
    cout « result « endl;
  }

  return 0;
}