#include <stdio.h>
void main() {
    int n,key;
    // taking length of data 
    printf(" enter the no. of element :: ");
    scanf("%d",&n);
    int data[n];
    // taking data input
    for (int i=0; i<n; i++) {
        scanf("%d",&data[i]);
    }
    // taking key input 
    printf(" enter the key :: ");
    scanf("%d",&key); 
    for(int i=0; i<n; i++ ) {
        if(key == data[i]){
            printf("Key(%d) found at %d position.",key,i+1);
            return;
        } 
    }
    printf("Key(%d) not found.",key);
}