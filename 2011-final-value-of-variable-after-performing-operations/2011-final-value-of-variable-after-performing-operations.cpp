class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) 
    {
        int N = 0;
        for(int i=0;i<operations.size();i++)
        {
            if(operations[i]=="X++")
            {
                N++;
            }
            else if(operations[i] == "++X")
            {
                ++N;
            }
            else if(operations[i] == "X--")
            {
                N--;
            }
            else if(operations[i] == "--X")
            {
                --N;
            }
        }
        return N;
    }
};