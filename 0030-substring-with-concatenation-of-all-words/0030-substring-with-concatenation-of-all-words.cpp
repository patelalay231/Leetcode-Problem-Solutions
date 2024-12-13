class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLength = words[0].size();
        int wordCount = words.size();
        int totalLength = wordLength * wordCount;

        // Create a frequency map of the words
        unordered_map<string, int> wordMap;
        for (const string& word : words) {
            wordMap[word]++;
        }

        // Iterate through all possible starting points
        for (int i = 0; i < wordLength; ++i) {
            int left = i, count = 0;
            unordered_map<string, int> tempMap;

            // Traverse the string with a sliding window
            for (int j = i; j + wordLength <= s.size(); j += wordLength) {
                string word = s.substr(j, wordLength);

                if (wordMap.count(word)) {
                    tempMap[word]++;
                    count++;

                    // If the word appears more times than it should, adjust the window
                    while (tempMap[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLength);
                        tempMap[leftWord]--;
                        count--;
                        left += wordLength;
                    }

                    // If all words are matched, record the starting index
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    // Reset the window if a word is not in the dictionary
                    tempMap.clear();
                    count = 0;
                    left = j + wordLength;
                }
            }
        }

        return result;
    }
};
