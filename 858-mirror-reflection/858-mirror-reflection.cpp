// height * p = base * q;

class Solution {
public:
    int mirrorReflection(int p, int q)
    {
        int height = q, base = p;
        
        while(height % 2 == 0 && base % 2 == 0) 
        {
            height/=2;
            base/=2;
        }
        
        if(height % 2 == 0 && base % 2 != 0) 
            return 0;
        if(height % 2 != 0 && base % 2 != 0) 
            return 1;
        if(height % 2 != 0 && base % 2 == 0) 
            return 2;
        
        return -1;
        
    }
};