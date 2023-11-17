// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* curr1 = head1;
    SinglyLinkedListNode* curr2 = head2;
    SinglyLinkedListNode node(0);
    
    SinglyLinkedListNode* tail = &node;

    while (curr1 != NULL && curr2 != NULL) {
        if (curr1->data <= curr2->data) {
            tail->next = curr1;
            tail = curr1;
            curr1 = curr1->next;
        }
        else {
            tail->next = curr2;
            tail = curr2;
            curr2 = curr2->next;
        }    
    }
    if (curr1 == NULL) {
        tail->next = curr2;
    }
    if (curr2 == NULL) {
        tail->next = curr1;
    }    
    return node.next;
}