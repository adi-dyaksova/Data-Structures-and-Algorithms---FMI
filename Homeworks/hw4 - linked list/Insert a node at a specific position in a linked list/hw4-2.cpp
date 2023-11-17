// Complete the insertNodeAtPosition function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode* currTail = head;
    while (currTail->next != NULL) {
        currTail = currTail->next;
    }

    SinglyLinkedListNode* current = head;
    SinglyLinkedListNode* previous = NULL;
    for (int i = 0; i < position; i++)
    {
        if (current) {
            previous = current;
            current = current->next;
        }
        else {
            //throw std::out_of_range("Cannot insert in invalid position");
            cout << "Not valid position\n";
            return NULL;
        }
    }
    if (previous == NULL) { //position==0
        head = new SinglyLinkedListNode(data);
        head->next = current;
    }
    else {
        previous->next = new SinglyLinkedListNode(data);
        previous->next->next = current;
    }    
    if (currTail == previous) { //(current == NULL)
        currTail = current;  //previous->next
    }
    return head;
}