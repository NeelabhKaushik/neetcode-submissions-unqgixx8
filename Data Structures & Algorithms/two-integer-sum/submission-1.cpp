class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++){

            int numToFind = target - nums[i];
            if(mp.find(numToFind) != mp.end() ){
                vector<int > ans = {i, mp[numToFind]};
                sort(ans.begin(), ans.end());
                return ans;
            }
            else{
                mp[nums[i]] = i;
            }
        }

        return {-1, -1};
    }
};
