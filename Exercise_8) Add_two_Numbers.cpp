//Il programma somma 2 numeri che sono salvati su 2 linked lists (sono scritti al contrario)
#include<iostream>
#include<list>
#include<string>
using namespace std;

#include "Functions.h"

//Dichiarazione di funzioni (Definite dopo il main)
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
ListNode* Write_on_nodes();
void printList (ListNode *list);

int main(){

    //Chiamo una funzione che mi riempia i nodi
    ListNode *l1 = Write_on_nodes();
    printList(l1); 

    ListNode *l2 = Write_on_nodes();
    printList(l2);

    //Creo la lista risultato
    ListNode *results = addTwoNumbers(l1, l2);

    //Stampo la lista risultato MA NON FUNZIONAAAA!!!
    printList(results);
    
    return 0;
}


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *dummyHead = new ListNode(0);
    ListNode *tail = dummyHead;
    int carry = 0;

    while(l1 != nullptr || l2 != nullptr || carry != 0){
        int digit1 = (l1 != nullptr) ? l1->val : 0;
        int digit2 = (l2 != nullptr) ? l2->val : 0;

        int sum = digit1 + digit2 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        ListNode *newNode = new ListNode(digit);
        tail->next = newNode;
        tail = tail->next;

        l1 = (l1 != nullptr) ? l1->next : nullptr;
        l2 = (l2 != nullptr) ? l2->next : nullptr;
    }

    ListNode *result = dummyHead->next;
    delete dummyHead;

    return result;
}
