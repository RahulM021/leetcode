class Solution
{
    public:
        void solve(vector<int> &candidates, int ind, int target, vector<int> &v, vector< vector< int>> &ans)
        {
            if (target == 0)
            {
                ans.push_back(v);
                return;
            }

            for (int i = ind; i < candidates.size(); i++)
            {
                if (i > ind && candidates[i] == candidates[i - 1]) continue;
                if (candidates[i] > target) break;
                v.push_back(candidates[i]);
                solve(candidates, i + 1, target - candidates[i], v, ans);
                v.pop_back();
            }
        }
    vector<vector < int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector < int>> ans;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, target, v, ans);
        return ans;
    }
};