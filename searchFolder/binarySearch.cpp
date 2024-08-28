

#include "iostream"
#include "vector"

using namespace std;

/// @brief binary search
/// @param target 
/// @param nums 
/// @return 
int binarySearch(int target, vector<int> nums){

    int i = 0; 
    int j = nums.size() - 1;

    int m = int(j/2);

    while(i <= j){
        int m = (i + j) /2;
        if (target == nums[m]){
            return m;
        } else if(target > nums[m]){
            i = m  + 1;
        } else if(target < nums[m]){
            j = m  - 1;
        }
    }

    return -1;
}

/// @brief insert a number with binary search
/// @param target 
/// @param nums 
/// @return 
int insertElement(int target, vector<int> nums){
    int i = 0;
    int j = nums.size() - 1;
    while (i <= j){
        int m = (i + j) / 2;
        if (target == nums[m]){
            return m;
        }else if(target > nums[m]){
            i = m + 1;
        }else if(target < nums[m]){
            j = m - 1;
        }

    }

    return i;
}

/// @brief insert an element in vector with more than 1 target
/// @param target 
/// @param nums 
/// @return 
int insertElement2(int target, vector<int> nums){
    int i = 0;
    int j = nums.size() - 1;
    while (i <= j){
        int m = (i + j) / 2;
        if (target == nums[m]){
            j = m - 1;
        }else if(target > nums[m]){
            i = m + 1;
        }else if(target < nums[m]){
            j = m - 1;
        }

    }

    return i;
}



int main(){

    // vector<int> nums = {1,3,4,5,6,7,8,9};
    // for (int i : nums){
    //     cout << i << endl;
    // }

    // int ind = binarySearch(8, nums);
    // cout << ind << endl;

    // int ind2 = insertElement(2, nums);
    // cout << ind2 << endl;

    vector<int> nums2 = {1,3,4,4,4,4,5,6,7,8,9};
    int ind3 = insertElement2(4, nums2);
    cout << ind3 << endl;

    return 0;

}