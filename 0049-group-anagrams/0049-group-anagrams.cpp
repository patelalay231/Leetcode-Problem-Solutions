class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int, vector<string>> mp;
        unordered_map<string, int> visited;
        int k = 0;
        for (auto it : strs) {
            string temp = it;
            sort(temp.begin(), temp.end());
            if (visited.find(temp) == visited.end()) {
                visited[temp] = k++;
            }
            mp[visited[temp]].push_back(it);
        }
        vector<vector<string>> ans;
        for (auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};