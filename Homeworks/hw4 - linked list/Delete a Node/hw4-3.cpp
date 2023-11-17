// Complete the deleteNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    if (head == NULL) {
        cout << "list is empty\n";
        return NULL;
    }
    SinglyLinkedListNode* curr = head;
    SinglyLinkedListNode* prev = NULL;
    for (int i = 0; i < position; i++)
    {
        prev = curr;
        curr = curr->next;
        if (curr == NULL) {
            cout << "not valid position\n";
            return NULL;
        }
    }
    if(prev==NULL){
        head=head->next;
    }
    else{
        prev->next=curr->next;
    }

 
    delete curr;
    return head;
}