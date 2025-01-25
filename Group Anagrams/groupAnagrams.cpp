class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // create hash map
        unordered_map<string, vector<string>> anagrams;
        for ( const string& word : strs) {
            //sort to generate key
            string key = word;
            sort(key.begin(), key.end());

            // add word to proper key
            anagrams[key].push_back(word);

        }
        // collect the grouped anagrams into a vector of vectors to return it
        vector<vector<string>> result;
        for ( const auto& group : anagrams){
            result.push_back(group.second); // second since the first would be the key
        }
        return result;
    }
};
