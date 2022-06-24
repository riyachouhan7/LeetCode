class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num == 0) return 0;
        for(int i=1;i<=10;i++)
        {
            if((num-(i*k))%10 == 0 && i*k <= num)
            {
                return i;
            }
        }
        return -1;
    }
};

/*int minimumNumbers(int num, int k)
   {
       if(num==0) return 0; // base case;
       
       for(int n=1;n<=10 && n*k<=num ;n++)  // n is number of elements in set
       {
           if((num-n*k)%10 == 0)   
           return n;
               
       }
       return -1;
   }*/