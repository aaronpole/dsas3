#include <stdio.h>

int main(){
    int s1[] = {1,2,3,4};
    int s2[] = {3,4,5};
    int s1length = sizeof(s1)/sizeof(int);
    int s2length = sizeof(s2)/sizeof(int);
    printf("Intersection : ");
    for (int i = 0; i < s1length; i++){
        for (int j = 0; j < s2length; j++){
            if (s1[i]==s2[j]){
                printf("%d ",s2[j]);
            }
        }
    }
    printf("\n");
    return 0;
}
