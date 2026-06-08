#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char key[] = "Suzu";

void win(unsigned int a, char *s, unsigned long c) {
    if (a == 0xdeadbeef &&
        s == key &&
        c == 0x1337133713371337UL) {
        system("/bin/sh");
    } else {
        puts("wrong arguments");
        printf("a = 0x%x\n", a);
        printf("s = %p\n", s);
        printf("c = 0x%lx\n", c);
    }
}

void normal_handler(unsigned int a, char *s, unsigned long c) {
    puts("normal handler");
}

void (*handlers[])(unsigned int, char *, unsigned long) = {
    normal_handler,
    win
};

__attribute__((constructor))
void setup_message(void) {
    puts("system ready");
}

void vuln(void) {
    char buf[64];

    puts("Tell me something to get the flag > ");
    read(0, buf, 256);
}

int main(void) {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    vuln();
    return 0;
}
