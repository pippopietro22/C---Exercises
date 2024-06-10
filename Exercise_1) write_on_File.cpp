#include<iostream>
#include<vector>
#include<fstream>      //Allows to write on and read from a file
using namespace std;

int main (){
    ofstream outputFile("file.txt");    //Open a file for writing
    //Could have done:
        //ofstream outputFile;
        //outputFile.open("file.txt");

    //Check if the file is opened correctly
    if(!outputFile){
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    int n;
    string input;
    //Starts to write numbers in the file
    while(input != "*"){
        cout << "> ";
        cin >> input;

        if(input == "*")break;

        //Check if the inputs given from the users are corect
        try{
            n = stoi(input);
            outputFile << n << " ";
        }catch(const invalid_argument&){
            cerr << "Error, please insert a number or \"*\"" << endl;
            cin.clear();    //Clear the cin process
        }
    }

    //Close the file when the program is done writing
    outputFile.close();
    cout << endl;



    //Open an input file for reading
    ifstream inputFile("file.txt");
    //Could have done:
        //ifstream inputFile;
        //inputFile.open("file.txt");

    //Checks if the file is opened corectly
    if(!inputFile){
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    vector<int> myNums;     //Use a vector to memorize all the numbers
    //Pass all the numbers to the vector by an integer
    while(inputFile >> n){
        myNums.push_back(n);
    }

    //Finally checks if all the process is done correctly by printing all the input numbers from the file
    for(int i = 0; i < myNums.size(); i++){
        cout<< myNums[i] << " ";
    }
    cout << endl;
    

    return 0;
}