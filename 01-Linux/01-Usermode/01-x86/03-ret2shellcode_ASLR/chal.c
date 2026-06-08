#include<stdio.h>

int main(){
    char buf[120];
    printf("buf address: %p\n", (void *)buf);
    puts("Tell me something to get the secret > ");
    read(0, buf, 500);
    return 0;
}
