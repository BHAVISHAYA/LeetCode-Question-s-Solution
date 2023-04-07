//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    
    void insertAtTail(Node* &tail, int data) {
        Node* newNode = new Node(data);
        tail -> next = newNode;
        tail = newNode;
    }
    Node* segregate(Node *head) {
        
        // Add code here
        if(head == NULL && head -> next == NULL) return head;
        
        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;
        Node* oneHead = new Node(-1);
        Node* oneTail = oneHead;
        Node* twoHead = new Node(-1);
        Node* twoTail = twoHead;
        
        Node* curr = head;
        while(curr != NULL) {
            int value = curr -> data;
            if(value == 0) 
            insertAtTail(zeroTail, value);
            else if(value == 1) 
            insertAtTail(oneTail, value);
            else 
            insertAtTail(twoTail, value);
            
            curr = curr -> next;
        }
        
        if(oneHead -> next == NULL) {
            zeroTail -> next = twoHead -> next;
        }
        else {
            zeroTail -> next = oneHead -> next;
        }
        oneTail -> next = twoHead -> next;
        twoTail -> next = NULL;
        
        // Set head element
        head = zeroHead -> next;
        
        
        // Now delete all the dummy nodes;
        delete oneHead;
        delete zeroHead;
        delete twoHead;
        
        return head;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends