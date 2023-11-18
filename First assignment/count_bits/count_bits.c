#include <stdio.h>
#include <stddef.h>

unsigned int count_bits(unsigned long num) {
     unsigned int count = 0, i; unsigned long shif_num, ind_val;
    for (i = 0; i < sizeof(num); i += 1) {
	shif_num = num >> i;
	ind_val = shif_num & 1;
        if (ind_val == 1 && i % 2 == 1) {
            count++;
        }
    }
    return count;
}


int main() {
    unsigned long num; 
    printf("Please enter a binary number: ");
    scanf("%lu", &num);	
    unsigned int count = count_bits(num);
   
    printf("The number of lit bits in even positions is: %u\n", count);
    return 0;
}
