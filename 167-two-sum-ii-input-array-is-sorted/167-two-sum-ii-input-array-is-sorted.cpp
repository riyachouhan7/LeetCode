class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int ,int> m;
        vector<int> v;
        int k;
        for(int i=0;i<numbers.size();i++){
            k=target-numbers[i];
            if(m.find(k)!=m.end()){
                v.push_back(m[k]+1);
                v.push_back(i+1);
                break;
            }
            else{
                m[numbers[i]]=i;
            }
        }
        return v;
    }
};