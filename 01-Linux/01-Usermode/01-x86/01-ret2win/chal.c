#include<stdio.h>

void win(){
    system("cat flag.txt");
}

int main(){
    char buf[16];
    puts("Tell me something to find the secret > ");
    gets(buf);
    return 0;
}

