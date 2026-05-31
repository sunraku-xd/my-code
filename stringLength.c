#include <stdio.h>
int main(){
    char str[] = "saikat";
    size_t len = 0;
    for(; str[len] != '\0'; len++);
        printf("length of string:%d\n", len);
    
    return 0;
}

    // for(int i=1; i<=strlen("HELLO"); i++){
    //     printf("%.*s\n", i, "HELLO");
    // }
    
    // if(printf("Hello, World")){}
    
