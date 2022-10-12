#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(node* &head, int val){
    node* n = new node(val);

    if(head==NULL){
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next = n;
}

node* insert(node* &head, int pos, int val){
    node* n = new node(val);

    int i=0;
    node* temp;
    temp=head;
    for(i=0; i<pos-1; i++){
        temp=temp->next;
    }
    n->next = temp->next;
    temp->next = n;

    return head;
}

void display (node* head){
    node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int sum (node* head){
    // node* temp = head;
    // int sum = 0;

    // while(temp!=NULL){
    //     sum+=temp->data;
    //     temp=temp->next;
    // }
    // return sum;

    if (head==0)
        return 0;
    
    return head->data + sum(head->next);
}

node* insertAtSort (node* head, int val){
    node* n = new node(val);
    node* q = NULL;
    node* p = head;

    while(p != 0 && p->data<=val){   
        q=p;
        p=p->next;
    }
    n->next=q->next;
    q->next=n;
    return head;
}

node* deleteDuplicates (node* head){
    node* p = head;
    node* q = head->next;

    while(p->next != 0){
        if(q->data!=p->data){
            p=q;
            q=q->next;
        } else {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
    return head;
}

node* merge2LinkedLists (node* h1, node* h2){
    node* mergeHead;
    node* last;
    if(h1->data < h2->data){
        mergeHead = last = h1;
        h1 = h1->next;
        last->next=NULL;
    } else {
        mergeHead = last = h2;
        h2 = h2->next;
        last->next=NULL;
    }

    while (h1!=NULL && h2!=NULL){
        if(h1->data > h2->data){
            last->next = h2;
            last = h2;
            h2 = h2->next;
            last->next = NULL;
        } else {
            last->next = h1;
            last = h1;
            h1 = h1->next;
            last->next = NULL;
        }
    }
    if (h1 != NULL)
        last->next = h1;
    else
        last->next = h2;

    return mergeHead;

}

int main()
{
    node* h1 = NULL;
    node* h2 = NULL;
    
    insertAtTail(h1, 1);
    insertAtTail(h1, 3);
    insertAtTail(h1, 5);
    insertAtTail(h2, 2);
    insertAtTail(h2, 4);
    display(h1);
    display(h2);

    display(merge2LinkedLists(h1, h2));
   
    return 0;
}