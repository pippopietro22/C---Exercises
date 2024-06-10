//This program simply remove duplicates from an array and then prints the final result
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

#include "Functions.h"

int removeDuplicates(vector<int>& nums); 

int main(){
    vector<int> nums;

    write_on_file();
    read_from_file(nums);

    int result = removeDuplicates(nums);
    nums.erase(nums.begin() + result, nums.end());  //After rewriting the array without the duplicates, we erase the empty positions

    cout << result << endl;

    for(int i : nums){
        cout << i << "";
    }
    cout << endl;

    return 0;
}

int removeDuplicates(vector<int>& nums) {   //It, works with pointers, so it modifies the array passed as an argument outside this function
    int index = 1;  //We will use 2 indexes

    for (int i = 1; i < nums.size(); i++){
        if(nums[i] != nums[i-1]){       //If the current number is different from the previous one, we will store it.
            nums[index] = nums[i];
            index++;
        }
    }

    return index;
}