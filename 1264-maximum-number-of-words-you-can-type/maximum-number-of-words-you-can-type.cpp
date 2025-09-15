class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool isCorrect = true;
        int res = 0;
        for(int i=0; i<text.length(); i++){
            char c = text[i];
            
            if(c == ' ' && isCorrect) res++;
            else if(c == ' ') isCorrect = true;
            else if(brokenLetters.find(c) != string::npos){
                isCorrect = false;
            }
        } 

        if(isCorrect) res++;

        return res;
    }
};