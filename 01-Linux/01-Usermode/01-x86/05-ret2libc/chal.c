#include<stdio.h>
#include<unistd.h>

int main(){
    char buf[0x40];
    puts("Tell me something to get the secret > ");
    read(0, buf, 0x100);
    return 0;
}
