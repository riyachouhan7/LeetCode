class Solution {
public:
    int findClosest(int x, int y, int z) {
        int a = abs(z-x), b = abs(z-y);
        if(a==b) return 0;
        if(a > b) return 2;
        else return 1;
    }
};