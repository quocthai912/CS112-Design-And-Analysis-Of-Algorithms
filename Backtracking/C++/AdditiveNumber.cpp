// Solution: Quay Lui (Backtracking)
// Ta có thể thấy Code C++ triển khai phức tạp hơn rất nhiều so với Python
#include <bits/stdc++.h>
using namespace std;

vector<string> Solution;
vector<vector<string>> Result;

bool Check(string s0, string s1, string s2)
{
    long long num0 = stoll(s0);
    long long num1 = stoll(s1);
    long long num2 = stoll(s2);
    return num2 == num0 + num1;
}

void Add(string nums, int start, int end)
{
    string temp = "";
    for (int i = start; i <= end; i++)
    {
        temp += nums[i];
    }
    Solution.push_back(temp);
}

void Backtracking(int start, string nums)
{
    if (start == nums.length())
    {
        vector<string> temp;
        for (int i = 0; i < Solution.size(); i++)
        {
            temp.push_back(Solution[i]);
        }
        Result.push_back(temp);
    }
    if (Result.size() > 0)
    {
        return;
    }
    for (int end = start; end < nums.length(); end++)
    {
        if ((end - start) + 1 > 17)
        {
            return;
        }
        if (Result.size() > 0)
        {
            return;
        }
        if (Solution.size() < 2 && end != nums.length() - 1)
        {
            if (start != end && nums[start] == '0')
                return;
            Add(nums, start, end);
            Backtracking(end + 1, nums);
            Solution.pop_back();
        }
        else if (Solution.size() >= 2)
        {
            if (start != end && nums[start] == '0')
                return;
            string temp = "";
            for (int i = start; i <= end; i++)
            {
                temp += nums[i];
            }
            if (Check(Solution[Solution.size() - 2], Solution[Solution.size() - 1], temp) == true)
            {
                Add(nums, start, end);
                Backtracking(end + 1, nums);
                Solution.pop_back();
            }
        }
    }
}

bool AdditiveNumber(string nums)
{
    Backtracking(0, nums);
    if (Result.size() > 0)
    {
        return true;
    }
    return false;
}

int main()
{
    string nums;
    cin >> nums;
    if (AdditiveNumber(nums) == true)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}