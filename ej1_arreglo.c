#include <stdio.h>

int main(){
    int arr[5] = {1,2,3,4,5};
    int suma = 0;

    for (int i = 0; i <= 5; i++){
        suma += arr[i];
    }

    printf("%d", arr[5]);
}