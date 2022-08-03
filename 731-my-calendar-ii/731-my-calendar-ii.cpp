class MyCalendarTwo {
    private:
    map<int,int> m;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end)
    {
        m[start]++;
        m[end]--;
        int sum = 0;
        for(auto a = m.begin();a!=m.end();a++)
        {
            sum+=a->second;
            if(sum > 2)
            {
                m[start]--;
                m[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */