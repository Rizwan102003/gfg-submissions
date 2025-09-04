/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* reverse(Node* head){
        Node* prev=NULL,*temp=head;
        while(temp){
            Node* future=temp->next;
            temp->next=prev;
            prev=temp;
            temp=future;
        }
        
        // the updated head
        return prev;
    }
  
    Node *reverseKGroup(Node *head, int k) {
        // code here
        Node* temp=head;
        Node* ans=new Node(-1);
        Node* temp_ans=ans;
        while(temp){
            int cnt=0;
            Node* node_to_be_reversed=temp;
            while(temp && cnt<k-1){
                cnt++;
                temp=temp->next;
            }
            
            Node* future_node=NULL;
            if(temp){
                future_node=temp->next;
                temp->next=NULL;
            }
            Node* updated_head=reverse(node_to_be_reversed);
            temp_ans->next=updated_head;
            temp_ans=node_to_be_reversed;
            temp=future_node;
        }
        
        return ans->next;
    }
};