class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int > picked (strs.size(),  0);
        vector<vector<string >> answer;

        for(int i = 0; i < strs.size() - 1; i++){
            if(picked[i] == 1) continue;
            picked[i] = 1;

            answer.push_back({strs[i]});

            vector<int > mp(26, 0);
            for(auto j : strs[i]){
                mp[j - 'a']++;
            }

            for(int j = i+1; j < strs.size(); j++){
                if(picked[j] == 1) continue;

                vector<int > helper_mp(26, 0);

                for( auto k: strs[j]){
                    helper_mp[k-'a']++;
                }

                if(mp == helper_mp){
                    answer[answer.size() - 1].push_back(strs[j]);
                    picked[j] = 1;
                }
            }
        }

        if(!picked[strs.size() - 1]) answer.push_back({strs[strs.size() - 1]});

        return answer;
    }
};
