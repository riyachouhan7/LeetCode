class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        vector<string> v{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> s;
        for (string word : words)
        {
            string temp;
            for (int i = 0; i < word.size(); i++)
            {
                temp += v[word[i] - 'a'];
            }
            s.insert(temp);
        }
        return s.size();
    }
};