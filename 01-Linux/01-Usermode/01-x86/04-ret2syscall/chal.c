#include<stdio.h>
#include<unistd.h>
//#include<stdlib.h>

int main(){
    char buf[64];
    puts("No shellcode anymore! Tell me something to get flag >");
    read(0, buf, 300);
    return 0;
}
