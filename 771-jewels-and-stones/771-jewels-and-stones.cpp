class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans=0;
        for(int i=0;i<stones.length();i++){
            if(jewels.find(stones[i])!=-1){
                ans++;
            }
        }
        return ans;
    }
};