#include<stdio.h>
#include<stdlib.h>

struct Node {
    int key;
    struct Node *next;
};

/*
 * Queue is essentially a double ended linked list
 */
struct Queue {
    struct Node *start, *end;
};

/*
 * Stack is essentially a single ended linked list
 */
struct Stack {
    struct Node *top;
};

struct Queue* createQueue() {
    // Get the size of our node in memory
    unsigned queueSize = sizeof(struct Queue);

    // create our new mode in memory
    struct Queue* temp = (struct Queue*)malloc(queueSize);
    temp->start = temp->end = NULL;
    return temp;
}

struct Stack* createStack() {
    // Get the size of our node in memory
    unsigned stackSize = sizeof(struct Stack);

    // create our new mode in memory
    struct Stack* temp = (struct Stack*)malloc(stackSize);
    temp->top = NULL;
    return temp;
}

/*
 * This function simply creates a new Node
 */
struct Node* createNode(int k) {
    // Get the size of our node in memory
    unsigned nodeSize = sizeof(struct Node);

    // create our new mode in memory
    struct Node* temp = (struct Node*)malloc(nodeSize);

    // assign our key value to the new node
    temp->key = k;
    temp->next = NULL;
    return temp;
}
/*
 * This function is to add a node to the queue
 */
void enQueue(struct Queue* q, int key) {
    // create a new node
    struct Node* newNode = createNode(key);

    // add our node to the queue
    if (q->start == NULL) {
        q->start = q->end = newNode;
        return;
    }

    // add the new node to our queue
    q->end->next = newNode;
    q->end = newNode;
}

/*
 * Deletes the first element in the queue
 */
void deQueue(struct Queue* q) {
    // make sure queue isn't empty
    if (q->start == NULL)
        return;

    // Get the front of the queue
    struct Node* newNode = q->start;

    // Move the front of queue to next node
    q->start = newNode->next;

    // Free the memory
    free(newNode);
}

/*
 * Pushes a node with the key to the top of the stack.
 */
void push(struct Stack* s, int key) {
    // Create a node
    struct Node* newNode = createNode(key);

    // Add the node to the stack
    if (s->top == NULL) {
        s->top = newNode;
        return;
    }

    newNode->next = s->top;
    s->top = newNode;
}

/*
 * Pops the top node off of the stack.
 */
void pop(struct Stack* s) {
    // make sure stack isn't empty
    if (s->top == NULL)
        return;

    // Get the top of the stack
    struct Node* newNode = s->top;

    // Move the top of te stack to next node
    s->top = newNode->next;

    // Free the memory
    free(newNode);
}

void printLinkedList(struct Node *node)
{
    while (node != NULL)
    {
        printf(" %d", (node->key));
        node = node->next;
    }
}

void printQueue(struct Queue *queue) {
    printf(" %s\n", "-----");
    struct Node* currNode = queue->start;
    while (currNode != NULL) {
        printf(" %d", currNode->key);
        currNode = currNode->next;
    }
}

void printStack(struct Stack *stack) {
    printf(" %s\n", "-----");
    struct Node* currNode = stack->top;
    while (currNode != NULL) {
        printf(" %d", currNode->key);
        currNode = currNode->next;
    }
}

void testQueue() {
    struct Queue* queue = createQueue();
    int i;
    for(i = 0; i < 6; i = i + 1 ){
        enQueue(queue, i+1);
    }
    printQueue(queue);

    for(i = 0; i < 6; i = i + 1 ){
        deQueue(queue);
    }
    printQueue(queue);
    enQueue(queue, 1);
    enQueue(queue, 2);
    printQueue(queue);
}

void testStack() {
    struct Stack* stack = createStack();
    int i;
    for(i = 0; i < 6; i = i + 1 ){
        push(stack, i+1);
    }
    printStack(stack);

    for(i = 0; i < 6; i = i + 1 ){
        pop(stack);
    }
    printStack(stack);
    push(stack, 1);
    push(stack, 2);
    printStack(stack);
}

int main() {
    testQueue();
    testStack();
    return 0;
}
