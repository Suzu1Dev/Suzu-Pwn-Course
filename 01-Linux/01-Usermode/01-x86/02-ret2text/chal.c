#include <stdio.h>

void hacked(int code){
    if(code == 0x1337){
	puts("You hacked the sysyem !!!\n");
	system("cat flag.txt");
    }
}

int main(){
    char buf[64];
    puts("Can you find the secret?\n");
    gets(buf);
    return 0;
}
