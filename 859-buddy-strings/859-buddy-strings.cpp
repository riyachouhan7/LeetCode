class Solution {
public:
     bool buddyStrings(string s, string goal) {
         if(s.size()!=goal.size()) return false;
         if(s==goal){
             sort(s.begin(), s.end());
             sort(goal.begin(), goal.end());
             for(int i=0; i<s.size()-1; i++){
                 if(s[i]==s[i+1]) return true;
             }
             return false;
         }
         int diffCount = 0;
         for(int i=0; i<s.size(); i++){
             if(s[i]!=goal[i]) diffCount++;
         }
         if(diffCount>2) return false;
         sort(s.begin(), s.end());
         sort(goal.begin(), goal.end());
         if(s==goal) return true;
         return false;
    }       
};