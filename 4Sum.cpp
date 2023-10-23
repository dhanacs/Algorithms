// Time complexity is O(n**3)
// Extension of 3-Sum solution

class Solution
{
  public:

  vector<vector<int>> threeSum(vector<int> &a, long target, int index)
  {
    int n = a.size();
    vector<vector<int>> triplets;

    for(int i = index + 1; i < n - 2; ++i)
    {
      int j = i + 1;
      int k = n - 1;

      if(i > index + 1 && a[i] == a[i - 1]) continue;

      while(j < k)
      {
        long sum = (long) a[i] + a[j] + a[k];

        if(sum == target)
        {
          triplets.push_back({a[i], a[j], a[k]});
          ++j;
          --k;

          while(j < k && a[j] == a[j - 1]) ++j;
          while((k < n - 1) && j < k && a[k] == a[k + 1]) --k;
        }
        else if(sum > target)
        {
          --k;
        }
        else
        {
          ++j;
        }
      }
    }

    return triplets;
  }

  public:

  vector<vector<int>> fourSum(vector<int> &a, int target)
  {
    int n = a.size();
    vector<vector<int>> quadruplets;

    sort(a.begin(), a.end());
    for(int i = 0; i < n - 3; ++i)
    {
      int k = target - a[i];
      if(i > 0 && a[i] == a[i - 1]) continue;

      vector<vector<int>> triplets = threeSum(a, k, i);
      for(auto triplet : triplets)
      {
        triplet.insert(triplet.begin(), a[i]);
        quadruplets.push_back(triplet);
      }
    }

    return quadruplets;
  }
};
