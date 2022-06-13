class Solution
{
    public:
        int findMin(vector<int> &nums)
        {
            int n = nums.size();
            int start = 0,end = n - 1;
           /* if (nums[start] <= nums[end])
            {
                return nums[0];
            }
            else*/
            {
                while (start <= end)
                {
                    int mid = start + (end - start) / 2;
                    int prev = (mid + n - 1) % n;
                    int next = (mid + 1) % n;

                    if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])
                    {
                        return nums[mid];
                    }
                    else if (nums[mid] > nums[end])
                    {
                        start = mid + 1;
                    }
                    else
                    {
                        end = mid;
                    }
                }
            }
            return -1;
        }
};