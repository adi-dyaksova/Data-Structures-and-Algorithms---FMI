// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
 int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* currHead1 = head1;
    SinglyLinkedListNode* currHead2 = head2;
    while (currHead1 !=NULL) {
        while (currHead2!=NULL) {
            if (currHead1 == currHead2)return currHead1->data;
            currHead2 = currHead2->next;
        }
        currHead2 = head2;
        currHead1 = currHead1->next;
    }
    return 0;
}
