class Solution {
    private:
    string removeKdigit(string num, int k){
        string res = "";
        
        for(char &ch : num){
            
            while(res.size() > 0 && k && res.back() > ch){
                res.pop_back();
                k--;
            }
                 
            if(res.size() > 0 || ch != '0')
                res.push_back(ch);
        }
        
        while(res.size() && k){
            res.pop_back();
                k--;
        }
        
        if(res.size() == 0) return "0";
        
        return res;
    }
    
public:
    string removeKdigits(string num, int k) {
        
        return removeKdigit(num, k);
    }
};