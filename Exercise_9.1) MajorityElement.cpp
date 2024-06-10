//This program shows a way to find the number that apeares the same times or more than "n/2". Where n/2 is the length of the array.
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

#include "Functions.h"

int main(){
    vector<int> nums;   //Declares an array

    write_on_file();
    read_from_file(nums);

    int result = majorityElement(nums);     //Execute the program

    cout << result << endl;
    return 0;
}

int majorityElement(vector<int>& nums){
    sort(nums.begin(), nums.end());     //Sorts the array from the smallest to the largest element
    int n = nums.size();                //the times the number apears is n/2, so it's going to be in the middle

    return nums[n/2];
}