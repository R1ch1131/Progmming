#include <iostream>
#include <vector>
using namespace std;

vector<int> countPrefixSum(const vector<int> &A)
{
  int n = A.size();
  vector<int> prefixSum(n);
  prefixSum[0] = A[0];
  for (int i = 1; i < n; i++)
  {
    prefixSum[i] = prefixSum[i - 1] + A[i];
  }
  return prefixSum;
}

int main()
{
  int n;
  cin » n;

  vector<int> A(n);
  for (int i = 0; i < n; i++)
  {
    cin » A[i];
  }

  vector<int> prefixSum = countPrefixSum(A);

  while (true)
  {
    int start, end;
    cin » start » end;
    if (start == 0)
    {
      cout « prefixSum[end] « endl;
    }
    else
    {
      cout « prefixSum[end] - prefixSum[start - 1] « endl;
    }
  }

  return 0;
}