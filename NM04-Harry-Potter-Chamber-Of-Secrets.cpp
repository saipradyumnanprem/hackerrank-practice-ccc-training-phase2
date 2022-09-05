#include <bits/stdc++.h>

using namespace std;

typedef struct LinkedListNode LinkedListNode;

struct LinkedListNode {
    int val;
    LinkedListNode *next;
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, int val) {
    if(head == NULL) {
        head = (LinkedListNode *) (malloc(sizeof(LinkedListNode)));
        head->val = val;
        head->next = NULL;
        tail = head;
    }
    else {
        LinkedListNode *node = (LinkedListNode *) (malloc(sizeof(LinkedListNode)));
        node->val = val;
        node->next = NULL;
        tail->next = node;
        tail = tail->next;
    }
    return tail;
}


/*
 * Complete the function below.
 */
/*
For your reference:
LinkedListNode {
    int val;
    LinkedListNode *next;
};
*/
bool hasCycle(LinkedListNode* head) {
    
    unordered_set <LinkedListNode*> s;
    while (head != NULL) {
        
        if (s.find(head) != s.end())
            return true;
 
        s.insert(head);
 
        head = head -> next;
    }
 
    return false;

}

int main()
{
    FILE *f = stdout;
    char *output_path = getenv("OUTPUT_PATH");
    if (output_path) {
        f = fopen(output_path, "w");
    }

    bool res;
    int head_size = 0;

    LinkedListNode* head = NULL;
    LinkedListNode* head_tail = NULL;

    scanf("%d\n", &head_size);
    for(int i = 0; i < head_size; i++) {
        int head_item;
        scanf("%d", &head_item);
        head_tail = _insert_node_into_singlylinkedlist(head, head_tail, head_item);

        if(i == 0) {
            head = head_tail;
        }
    }
    int x;
      scanf("%d", &x);
      if (x > -1)
    {
          LinkedListNode* ptr = head;
          while (x--) ptr = ptr->next;
          head_tail->next = ptr;
    }

    res = hasCycle(head);
    fprintf(f, "%d\n", res);

    fclose(f);
    return 0;
}