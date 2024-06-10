//This program handles 2 sorted arrays and find the Median of the complessive array
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

#include "Functions.h"

int p1 = 0;
int p2 = 0;

int getMin(vector<int>& nums1, vector<int>& nums2);
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

int main(){
    cout << "Inserisci il primo array" << endl;

    vector<int> nums1;
    
    write_on_file();
    read_from_file(nums1);

    cout << "Inserisci il secondo array" << endl;
    
    vector<int> nums2;
    write_on_file();
    read_from_file(nums2);    

    //Whe get the Mediane
    double result = findMedianSortedArrays(nums1, nums2);

    //Print the result
    cout << "Median is: " << result << endl;

    return 0;
}

//This function returns the lowest element of both the arrays and, if called ricorsively, 
//it points to the next one in order of growth and so on.
int getMin(vector<int>& nums1, vector<int>& nums2){
    if(p1 < nums1.size() && p2 < nums2.size()){
        return nums1[p1] < nums2[p2] ? nums1[p1++] : nums2[p2++];

    }else if(p1 < nums1.size()){
        return nums1[p1++];

    }else if(p2 < nums2.size()){
        return nums2[p2++];
    }

    return -1;   
}

//This function - using getMin - returns the complessive Mediane
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = int(nums1.size()), n = int(nums2.size());

        if ((m + n) % 2 == 0) {
            for (int i = 0; i < (m + n) / 2 - 1; ++i) {
                int _ = getMin(nums1, nums2);
            }
            return (double)(getMin(nums1, nums2) + getMin(nums1, nums2)) / 2;

        } else {
            for (int i = 0; i < (m + n) / 2; ++i) {
                int _ = getMin(nums1, nums2);
            }            
            return getMin(nums1, nums2);
        }

        return -1;
    }