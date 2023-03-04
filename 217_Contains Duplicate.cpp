class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        int temp;
        set<int> num;
        for(int i=0; i<len; i++)
        {
            temp = nums[i];
            if(num.count(temp))
            {
                return true;
            }
            else
            {
                num.insert(temp);
            }
        }
        
        return false;
    }
};


// Contains Duplicate
  class Solution {
  public:
      bool containsDuplicate(vector<int>& nums) {
          map<int,int> mp;
          for(auto i : nums) mp[i]++;
          bool flag = false;
          for(auto i : mp){
              if(i.second >= 2) return true;
          }
          return flag;
      }
  };