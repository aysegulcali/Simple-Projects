#include<stdio.h>

#define SIZE 5

void square(int *aGst);

int main(void) {
    int array_1[SIZE]={0};
    int i;
    for(i=0;i< SIZE; i++) {
        array_1[i]=i;
        printf("Before function array_1[%d]=%d\n",i, array_1[i]);
    }
    printf("\n");
    square (array_1);

    for(i=0;i< SIZE; i++) {
        printf("After function array_1[%d]=%d\n",i, array_1[i]);
    }
    return 0;
}

void square(int *aGst) {
    int i;
    for(i=0;i<SIZE;i++) {
        aGst[i]=(aGst[i]*aGst[i]);
    }
}
