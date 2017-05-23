#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr_num;
    int *br_elementi;
    int **arr;
    int br1, br2;

    printf("vuvedete broi masivi\n");
    scanf("%d", &arr_num);
    arr = (int**)malloc(arr_num * sizeof(int*));
    br_elementi = (int*)malloc(arr_num*sizeof(int));

    for(br1=0; br1<arr_num; br1++){
        printf("vuvedete broi elementi za %d masiv\n", br1);
        scanf("%d", &br_elementi[br1]);
        arr[br1] = (int*)malloc(br_elementi[br1]*sizeof(int));
        for(br2=0; br2<br_elementi[br1]; br2++){
            printf("vuvedete %d element za %d masiv\n", br2, br1);
            scanf("%d", &arr[br1][br2]);
        }

    }
     for(br1=0; br1<arr_num; br1++){
        for(br2=0; br2<br_elementi[br1]; br2++){
            printf("A[%d][%d] = %d\n", br1, br2, arr[br1][br2]);
        }
     }
    free(arr);
    free(br_elementi);
    free(arr_num);
    return 0;
}
