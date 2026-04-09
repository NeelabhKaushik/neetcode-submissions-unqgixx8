class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string >> answer;
        unordered_map<string, int> mp;
        
        for(int i = 0; i < strs.size(); i++){
            string word = strs[i];
            sort(word.begin(), word.end());

            if(mp.find(word) == mp.end()){
                answer.push_back({strs[i]});
                mp[word] = answer.size() - 1;
            }
            else{
                answer[mp[word]].push_back(strs[i]);
            }
        }
      
        return answer;
    }
};
