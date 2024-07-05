#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    struct Stack *top;
    int value;
};

struct StackHead
{
    struct Stack *head;
};

struct Stack *initializeStack()
{
    struct Stack *stack = (struct Stack *)
        malloc(sizeof(struct Stack));
    ;

    return stack;
}

struct StackHead *createStack(int initialValue)
{

    struct Stack *stack = initializeStack();

    stack->top = NULL;
    stack->value = initialValue;

    struct StackHead *stackHead = (struct StackHead *)malloc(sizeof(struct StackHead));

    stackHead->head = stack;

    return stackHead;
}

int isEmpty(struct Stack *root)
{
    return !root;
}

int pushOnStack(int value, struct StackHead *stackHead)
{
    struct Stack *stack = initializeStack();
    stack->top = stackHead->head;
    stack->value = value;
    stackHead->head = stack;

    return 0;
}

void popOnStack(struct StackHead *stackHead)
{
    if (isEmpty(stackHead->head))
        return;
    struct Stack *prevStack = initializeStack();
    prevStack = stackHead->head->top;
    free(stackHead->head);
    stackHead->head = prevStack;
}

int main()
{
    struct StackHead *stackHead = createStack(10);

    printf("%d \n", stackHead->head->value);

    int result = pushOnStack(12, stackHead);
    printf("Push 12 \n");
    printf("%d \n", stackHead->head->top->value);
    printf("%d \n", stackHead->head->value);

    popOnStack(stackHead);
    printf("Pop 12 \n");
    printf("%d \n", stackHead->head->value);
    printf("Is empty? %s\n", isEmpty(stackHead->head) ? "Yes" : "No");

    popOnStack(stackHead);
    printf("Pop 10 \n");

    printf("Is empty? %s\n", isEmpty(stackHead->head) ? "Yes" : "No");

    /* code */
    return 0;
}
