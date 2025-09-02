/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        // code here
        int n=getLength(head);
        if(k>n)return head;
        if(k==(n-k+1))return head;
        
        Node* beg=head,*beg_prev=NULL;
        Node* end=head,*end_prev=NULL;
        
        for(int i=1;i<k;i++){
            beg_prev=beg;
            beg=beg->next;
        }
        for(int i=1;i<n-k+1;i++){
            end_prev=end;
            end=end->next;
        }
        if(beg_prev!=NULL){
            beg_prev->next=end;
        }
        if(end_prev!=NULL){
            end_prev->next=beg;
        }
        Node* temp=beg->next;
        beg->next=end->next;
        end->next=temp;
        
        if(k==1)return head=end;
        if(k==n)return head=beg;
        
        return head;
    }
    int getLength(Node* head){
        int len=0;
        while(head){
            len++;
            head=head->next;
        }
        return len;

    }
};