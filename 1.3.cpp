#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
  vector<int> v{5, 3, 3, 6, 2};
  sort(v.begin(), v.end());

  bool duplicateFound = false;

  for (int i = 0; i < v.size() - 1; i++)
  {
    if (v[i] == v[i + 1])
    {
      duplicateFound = true;
      break;
    }
  }

  if (duplicateFound)
    cout << "duplicate found" << endl;
  else
    cout << "duplicate not found" << endl;

  return 0;
}
