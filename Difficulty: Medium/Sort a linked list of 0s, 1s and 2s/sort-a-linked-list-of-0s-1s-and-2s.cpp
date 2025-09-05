/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* head0 = NULL;
        Node* head0p = NULL;
        Node* head1 = NULL;
        Node* head1p = NULL;
        Node* head2 = NULL;
        Node* head2p = NULL;
        
        Node* t = head;
        Node* pre = NULL;
        
        while(t != NULL){
            if(t->data == 0){
                if(pre != NULL && pre->data != 0){
                    pre->next = NULL;
                }
                if(head0 == NULL){
                    head0 = t ;
                    head0p = t;
                }
                else{
                    head0p ->next = t;
                    head0p = t ;
                }
            }
            else if(t->data == 1){
                if(pre != NULL && pre->data != 1){
                    pre->next = NULL;
                }
                if(head1 == NULL){
                    head1 = t ;
                    head1p = t;
                }
                else{
                    head1p ->next = t;
                    head1p = t ;
                }
            }
            else{
                if(pre != NULL && pre->data != 2){
                    pre->next = NULL;
                }
                if(head2 == NULL){
                    head2 = t ;
                    head2p = t;
                }
                else{
                    head2p ->next = t;
                    head2p = t ;
                }
            }
            
            pre = t;
            t = t->next;
        }
        
        if(head0 != NULL){
            if(head1 != NULL){
                head0p->next = head1;
                head1p->next = head2;   
            }
            else{
                head0p->next = head2;
            }
            return head0;
        }
        else if(head1 != NULL){
            head1p->next = head2;
            return head1;
        }
        else{
            return head2;   
        }
    }
};