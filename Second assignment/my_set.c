#include <stdio.h>
#include <stdlib.h>
#define ENLARGE_SIZE(n) n += 1


/* Function declarations */
int* get_set(int* n);
void print_set(int* group, int n);

/* Main */
int main() {
    int *group = NULL;
    int n = 0;
    
    group = get_set(&n);
    print_set(group, n);

    free(group);
    return 0;
}


/* The function get_set 
Creates and returns a group with the input values.
@param n - the size of the group
@return - the created group
*/
int* get_set(int* n) {
    int *group = NULL;
    int value;

    printf("Please enter the values (enter EOF to stop):\n");
    while (scanf("%d", &value) != EOF) {
        /* Entering a list of values by the user */
        int found = 0;
        int i;
        for (i = 0; i < *n; i++) {
            if (group[i] == value) {
                found = 1;
                break;
            }
        }

        /* If the value doesn't exist in the group, add it */
        if (!found) {
            ENLARGE_SIZE(*n);
            group = (int*) realloc(group, *n * sizeof(int));
            group[*n-1] = value;
        }
    }

    return group;
}


/* The function print_set
Prints the group memebers.
@param group - the group 
@param n - the size of the group 
*/
void print_set(int* group, int n) {
    int i;
    printf("Members of the group in order of appearance:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", group[i]);
    }
    printf("\n");
}
