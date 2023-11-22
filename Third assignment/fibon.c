#include <stdio.h>
#include <stdlib.h>

/* Structure for a node in the circular list */
typedef struct Node {
     int data;
     struct Node* next;
} Node;

/* Function to create a new node */
Node* createNode(int data) {
     Node* newNode = (Node*)malloc(sizeof(Node));
     newNode->data = data;
     newNode->next = NULL;
     return newNode;
}

/* Function to create the circular list with Fibonacci series */
Node* createFibonacciCircularList(int n) {
     Node* head = NULL;
     Node* curr = NULL;

     if (n == 0) {
         head = createNode(0);
         head->next = head;
         return head;
     }

     int a = 1;
     int b = 1;
     int i;

     /* Generate the Fibonacci series and create the circular list */
     for (i = 0; i < n; i++) {
         Node* newNode = createNode(a);

         if (head == NULL) {
             head = newNode;
             curr = head;
         } else {
             newNode->next = head;
             curr->next = newNode;
             curr = newNode;
         }

         int sum = a + b;
         a = b;
         b = sum;
     }

     return head;
}

/* A function that reverses the Fibonacci series and arranges it from the largest number to the smallest */
Node* transformFibonacciCircularList(Node* head) {
     if (head == NULL || head->next == NULL) {
         return head;
     }

     Node* prev = NULL;
     Node* curr = head;
     Node* next = NULL;

     /* Reverse the links in the circular list */
     do {
         next = curr->next;
         curr->next = prev;
         prev = curr;
         curr = next;
     } while (curr != head);

     /* Update the head pointer */
     head->next = prev;
     head = prev;

     return head;
}

/* Function to print the circular list in descending order */
void printCircularList(Node* head, FILE* outputFile, int n) {
     fprintf(outputFile, "The program prints out the Fibonacci sequence in descending order. Below is the last value you entered in the program and its series.\n");
     fprintf(outputFile, "n: %d\n", n);

     if (head == NULL) {
         return;
     }

     Node* current = head;
     do {
         printf("%d ", current->data);
         fprintf(outputFile, "%d ", current->data);
         current = current->next;
     } while (current != head);

     printf("\n");
     fprintf(outputFile, "\n");
}

int main() {
     printf("Welcome to the Fibonacci Calculator!\n");
     printf("Please enter a value, and the calculator will return (in descending order) the corresponding numbers in the Fibonacci series.\n");

     int n;
     printf("Enter a number (n): ");
     if (scanf("%d", &n) != 1) {
         printf("Invalid input.\n");
         return 1;
     }

     if (n < 0) {
         printf("The number must be non-negative.\n");
         return 1;
     }

     Node* head = createFibonacciCircularList(n);
     Node* transformedHead = transformFibonacciCircularList(head);

     FILE* outputFile = fopen("output.txt", "w");
     if (outputFile == NULL) {
         printf("Error opening the output file.\n");
         return 1;
     }

     printCircularList(transformedHead, outputFile, n);

     fclose(outputFile);

     return 0;
}

