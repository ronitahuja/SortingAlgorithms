/**/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define int long long
#define float double
#define null nullptr
#define N static_cast<int>(1e5 + 10)
#define pi (3.141592653589)
#define mod 1000000007
#define mini INT_MIN
#define maxi INT_MAX
#define fast_io ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

vector<string> Split(string &s, string key)
{
   int start = 0, pos = 0;
   vector<string> res;
   while ((pos = s.find(key, start)) != string::npos)
   {
      res.push_back(s.substr(start, pos - start));
      start = pos + key.size();
   }
   res.push_back(s.substr(start));
   return res;
}

string Trim(string &s)
{
   int start = 0, end = s.size() - 1;
   while (start < s.size() && s[start] == ' ')
      start++;
   while (end >= 0 && s[end] == ' ')
      end--;
   return s.substr(start, end - start + 1);
}
void bucketSort(vector<int> &arr)
{
   map<int, int> mp;
   for (int i : arr)
      mp[i]++;
   vector<vector<int>> bucket(arr.size() + 1);
   for (auto i : mp)
   {
      bucket[i.second].push_back(i.first);
   }
   int index = 0;
   for (int i = 0; i < bucket.size(); i++)
   {
      sort(bucket[i].begin(), bucket[i].end());
      for (int j = 0; j < bucket[i].size(); j++)
      {
         arr[index++] = bucket[i][j];
      }
   }
}
int32_t main()
{
   fast_io;
   int n;
   cin >> n;
   vector<int> arr(n);
   for (int i = 0; i < n; i++)
      cin >> arr[i];
   bucketSort(arr);
   for (int i : arr)
      cout << i << " ";
}