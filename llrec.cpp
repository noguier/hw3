#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
   //base case if list is null -- return 
  if (head == nullptr) {
    smaller = nullptr;
    larger = nullptr;
    return;
  }
  //if the first element in the in list is larger push back to larger, 
  //otherwise push back for smaller 
  else {
    if (head->val > pivot) {
      larger = head;
      head = head->next;
      llpivot(head, smaller, larger->next, pivot);
    }
    else {
      smaller = head;
      head = head->next;
      llpivot(head, smaller -> next, larger, pivot);
    }
  }
}

