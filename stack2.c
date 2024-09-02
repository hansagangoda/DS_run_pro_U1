//pro2 stack
#include <stdio.h>
#include <stdlib.h>

#define MAX 10


void push(int stack[], int *top, int value);
void pop(int stack[], int *top);
void peep(int stack[], int top);
void modify(int stack[], int top, int index, int newValue);
void display(int stack[], int top);

int main() {
    int stack[MAX];
    int top = -1; 
    int choice, value, index;

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep\n");
        printf("4. Modify\n");
        printf("5. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (top < MAX - 1) {
                    printf("Enter value to push: ");
                    scanf("%d", &value);
                    push(stack, &top, value);
                } else {
                    printf("Stack is full. Cannot push more elements.\n");
                }
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                peep(stack, top);
                break;
            case 4:
                if (top >= 0) {
                    printf("Enter index to modify (0 to %d): ", top);
                    scanf("%d", &index);
                    if (index >= 0 && index <= top) {
                        printf("Enter new value: ");
                        scanf("%d", &value);
                        modify(stack, top, index, value);
                    } else {
                        printf("Invalid index.\n");
                    }
                } else {
                    printf("Stack is empty. No elements to modify.\n");
                }
                break;
            case 5:
                display(stack, top);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}


void push(int stack[], int *top, int value) {
    stack[++(*top)] = value;
    printf("Pushed %d onto stack.\n", value);
}


void pop(int stack[], int *top) {
    if (*top >= 0) {
        printf("Popped %d from stack.\n", stack[(*top)--]);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }
}


void peep(int stack[], int top) {
    if (top >= 0) {
        printf("Top element is %d.\n", stack[top]);
    } else {
        printf("Stack is empty.\n");
    }
}


void modify(int stack[], int top, int index, int newValue) {
    stack[index] = newValue;
    printf("Modified index %d to new value %d.\n", index, newValue);
}

void display(int stack[], int top)
{
	int i;
    if (top >= 0) {
        printf("Stack elements:\n");
        for (i = 0; i <= top; i++)
		{
            printf("%d ", stack[i]);
        }
        printf("\n");
    } else {
        printf("Stack is empty.\n");
    }
}

