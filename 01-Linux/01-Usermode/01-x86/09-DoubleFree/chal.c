#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 8
#define SIZE 0x60

char *chunks[MAX];

void bye() {
    puts("bye");
}

void win() {
    system("/bin/sh");
}

struct FakeChunk {
    size_t prev_size;
    size_t size;
    void (*hook)();
    char padding[0x50];
} __attribute__((aligned(0x10)));

struct FakeChunk target = {
    .prev_size = 0,
    .size = 0x71,
    .hook = bye
};

void setup() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);

    puts("=== Double Free Demo ===");
    printf("target = %p\n", &target);
    printf("win    = %p\n", win);
}

int read_int() {
    char buf[0x10];
    read(0, buf, sizeof(buf));
    return atoi(buf);
}

void menu() {
    puts("");
    puts("1. malloc");
    puts("2. free");
    puts("3. edit");
    puts("4. trigger");
    puts("5. exit");
    printf("> ");
}

void add() {
    for (int i = 0; i < MAX; i++) {
        if (chunks[i] == NULL) {
            chunks[i] = malloc(SIZE);
            printf("idx = %d\n", i);
            return;
        }
    }

    puts("full");
}

void delete() {
    printf("idx: ");
    int idx = read_int();

    if (idx < 0 || idx >= MAX || chunks[idx] == NULL) {
        puts("invalid");
        return;
    }
    free(chunks[idx]);
    // chunks[...] = NULL

    puts("freed");
}

void edit() {
    printf("idx: ");
    int idx = read_int();

    if (idx < 0 || idx >= MAX || chunks[idx] == NULL) {
        puts("invalid");
        return;
    }

    puts("data:");
    read(0, chunks[idx], SIZE);
}

void trigger() {
    target.hook();
}

int main() {
    setup();

    while (1) {
        menu();

        int choice = read_int();

        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                delete();
                break;
            case 3:
                edit();
                break;
            case 4:
                trigger();
                break;
            default:
                exit(0);
        }
    }

    return 0;
}