#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    void (*fp)();
    char buf[0x20];
} Note;

Note *note;

void normal() {
    puts("normal note");
}

void win() {
    system("/bin/sh");
}

int main() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);

    note = malloc(sizeof(Note));
    note->fp = normal;

    printf("win = %p\n", win);

    free(note);
                            
    puts("input:");
    read(0, malloc(sizeof(Note)), sizeof(Note));

    note->fp();

    return 0;
}