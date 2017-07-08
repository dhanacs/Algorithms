// Given a set of integers,
// Find two disjoint sub-sets such that their sum are equal and is maximized.
// Time complexity is O(n * S * S)
// n = number of elements in the given set
// S = sum of elements in the given set

#include <vector>
#include <iostream>

using namespace std;

int n, sum;
int answer;

int max(int a, int b)
{
  return a > b ? a : b;
}

// Improve performance by caching repeated multiplications
int **M;

int multiply(int a, int b)
{
  if(M[a][b] != -1)
  {
    return M[a][b];
  }
  else
  {
    int c = a * b;
    M[a][b] = c;
    return c;
  }
}
//

// Flattening a 3D array
// This improves the memory access performance
int constantProduct;

int getIndex(int i, int j, int k)
{
  return multiply(i, constantProduct) + multiply(j, n) + k;
}

// Memoize <sumA, sumB, index>
bool *dp;

void solve(int sumA, int sumB, int index, vector<int> &a)
{
  int n = a.size();

  // Get the index corresponding to <sumA, sumB, index>
  int key = getIndex(sumA, sumB, index);
  
  if(dp[key])
  {
    return;
  }

  // Update the answer
  if(sumA == sumB)
  {
    answer = max(answer, sumA);
  }

  if(index == n)
  {
    dp[key] = true;
    return;
  }

  // An element can be put into
  // 1. Set A or
  // 2. Set B or
  // 3. Neither A nor B
  solve(sumA + a[index], sumB, index + 1, a);
  solve(sumA, sumB + a[index], index + 1, a);
  solve(sumA, sumB, index + 1, a);

  // Memoize
  dp[key] = true;
  return;
}

int maxSum(vector<int> &a)
{
  // Initialize
  sum = 0;
  answer = 0;
  for(int i = 0; i < n; ++i)
  {
    sum += a[i];
  }
  constantProduct = sum * n;

  // Allocate memory
  int size = (sum * sum * n) + (sum * n) + n + 1;
  dp = new bool[size];
  for(int i = 0; i < size; ++i)
  {
    dp[i] = false;
  }

  M = new int*[sum + 1];
  for(int i = 0; i < sum + 1; ++i)
  {
    M[i] = new int[constantProduct + 1];
  }
  //

  // Initialize
  for(int i = 0; i < sum + 1; ++i)
  {
    for(int j = 0; j < constantProduct + 1; ++j)
    {
      M[i][j] = -1;
    }
  }

  solve(0, 0, 0, a);
  delete dp;
  delete M;

  return answer;
}

int main()
{
  int value;
  vector<int> a;

  cin >> n;
  for(int i = 0; i < n; ++i)
  {
    cin >> value;
    a.push_back(value);
  }

  cout << maxSum(a) << endl;
  return 0;
}