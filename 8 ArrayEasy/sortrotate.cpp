#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool check(vector<int>& nums) {   
        const int n = nums.size() ;
        vector<int> sorted_nums = nums;     //sc : o(2n)
        sort(sorted_nums.begin(),sorted_nums.end()) ;  // o(nlogn)  

        for(int k=0;k<n;k++){
             vector<int> rotated(nums.begin() + k, nums.end());               // o(n-k)
            rotated.insert(rotated.end(), nums.begin(), nums.begin() + k);    // o(k)

            if(rotated == sorted_nums) return true; 
        }
        return false ;
    }

    bool check2(vector<int>& nums) {
        const int n = nums.size() ;
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(),sorted_nums.end()) ;    

        for(int k=0;k<n;k++){              // tc : o(n^2)
            vector<int>rotated = nums ;
            reverse(rotated.begin(),rotated.begin()+k);     
            reverse(rotated.begin()+k,rotated.end());   
            reverse(rotated.begin(),rotated.end()); 

            if(rotated == sorted_nums) return true; 
        }
        return false ;
    }
};

int main(){
    vector<int>nums = {6,10,5,6} ;

    Solution obj;
    // bool result = obj.check(nums);
    // cout << result << endl;

    bool result2 = obj.check2(nums);
    cout << result2 << endl;

    return 0;
}