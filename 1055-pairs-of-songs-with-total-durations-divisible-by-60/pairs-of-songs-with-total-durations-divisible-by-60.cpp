class Solution {
public:
	int numPairsDivisibleBy60(vector<int>& time) {
		int count = 0;
		vector<int> t (60, 0);
		for(int i = 0; i < time.size(); i++){
			int p = time[i] % 60;
			if(p == 0){
				count += t[p];
			}
			else{
				count += t[60 - p];
			}
			t[p]++;
		}
		return count;
	}
};