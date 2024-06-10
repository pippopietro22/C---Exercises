//The program removes all the elements into an array that are equal to a target
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

#include "Functions.h"

int removeElement(vector<int>& nums, int val);

int main(){
    int n, target, num_of_safe;
    vector<int> num;

    cout << "Insert the number you want to remove: ";
    cin >> target;

    //The user inserts an array 
    write_on_file();

    //The program reads the array from a file
    read_from_file(num);

    //We get the number of spared element 
    num_of_safe = removeElement(num, target);

    //And print all the results
    cout << "There are " << num_of_safe << " spared numbers in the array: "<<endl;

    ifstream inputFile2("file2.txt");

    while(inputFile2 >> n){     //The modified array is taken from another txt file
        cout << n << " ";
    }
    cout << endl;

    inputFile2.close();

    return 0;
}


int removeElement(vector<int>& nums, int val) {
    int index = 0;

    ofstream outputFile("file.txt");            //We use a txt file to write our new array

    for(int i = 0; i < nums.size(); i++){

        //If the value is different from the target, we store it in the array and shift to another position
        if(nums[i] != val){
            nums[index] = nums[i];

            outputFile << nums[index] << " "; 

            index++;
        }
    }

    outputFile.close();

    return index;
}