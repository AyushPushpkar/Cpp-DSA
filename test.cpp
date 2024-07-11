#include<bits/stdc++.h>
using namespace std ;

void nextPermutation(vector<int>& nums) {
        int n = nums.size() ;
        int index = -1 ;
        for(int i =n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index = i;
            cout << index ;
            break;
            }
        }
        if(index == -1){
            reverse(nums.begin(),nums.end()) ;
        }
        else{
            for(int i =n-1;i>index;i--){
                if(nums[i]>nums[index]){
                    swap(nums[index],nums[i]) ;
                    break;
                }
            }
            sort(nums.begin()+index+1,nums.end()) ;
        }
        for(auto it : nums){
            cout << it << " " ;
        }
 }

int main(){
    vector<int>nums = {1,3,2} ;

    nextPermutation(nums) ;


    return 0;
}