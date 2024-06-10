#ifndef Functions
#define Functions

//Structure, defines how my linked lists are made and how their functions are
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Functions that allows to create (or overwrite) a file and writing a serie of numbers (int) on that
int write_on_file(){    

    ofstream outputFile;
    outputFile.open("file.txt");

    if(!outputFile){
        cerr << "Error opening this file to write!"<< endl;
        return 1;
    }

    int n;
    string input;
    while(input != "*"){
        cout << "> ";
        cin >> input;

        if(input == "*") break;
        
        try{
            n = stoi(input);
            outputFile << n <<" ";
        }catch(const invalid_argument&){
            cerr << "Error, insert a number or \"*\"!" << endl;
            cin.clear();
        }
    }
    outputFile.close();

    return 0;
}

//Function that allows to read from a file a serie of numbers and memorize them on a vector
int read_from_file (vector<int>& num){
    int n;
    ifstream inputFile("file.txt");
    if(!inputFile){
        cerr << "Error reading file!" << endl;
        return 1;
    }

    while(inputFile >> n){
        num.push_back(n);
    }

    inputFile.close();

    return 0;
}

//Function that allows to print every value of a linked list
void printList (ListNode *list){
    ListNode *tail = list;

    while (tail != nullptr){
        cout << tail->val << " ";
        tail = tail->next;
    }
    cout << endl;
}

//Function that allows to fill an entire linked list values
ListNode *Write_on_nodes(){
    string input;
    ListNode *dummyHead = new ListNode(0);
    ListNode *tail = dummyHead;

    cout << "**********************************************" << endl;
    cout << "Inserisci cifre numero AL CONTRARIO" << endl;
    cout << "\"*\" per uscire" << endl;
    cout << "**********************************************" << endl;

    while(input != "*"){
        int digit;

        cout << "> ";
        cin >> input;

        if(input == "*") break;

        try{
            int digit = stoi(input);
        }catch(const invalid_argument){
            cerr << "ERROR, insert a number or \"*\" to exit" << endl;
            cin.clear();
            continue; 
        }

        ListNode *newNode = new ListNode(digit);
        tail->next = newNode;

        tail = tail->next;
    }

    ListNode *result = dummyHead->next;
    delete dummyHead;
    return result;
}

bool isPalindrome (string num){
    int n = num.length();

    for(int i = 0; i < n/2; i++){
        if(num[i] != num[n-i-1]) return false;
    }

    return true;
}

#endif