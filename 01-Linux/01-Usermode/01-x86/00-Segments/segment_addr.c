#include <stdio.h>
#include <stdlib.h>

int g_init = 123;           // .data
int g_zero;                 // .bss
int g_arr[1000];            // .bss

static int s_init = 456;    // .data
static int s_zero;          // .bss

const char *global_str = "hello"; 
// global_str 這個指標變數在 .data
// "hello" 字串本體通常在 .rodata

void func() {
    printf("func\n");
}

int main() {
    int local = 789;        // stack
    static int local_static_init = 999; // .data
    static int local_static_zero;       // .bss

    int *heap_int = malloc(sizeof(int)); // heap
    *heap_int = 777;

    printf("=== .text ===\n");
    printf("main:              %p\n", main);
    printf("func:              %p\n", func);

    printf("\n=== .data ===\n");
    printf("&g_init:           %p\n", &g_init);
    printf("&s_init:           %p\n", &s_init);
    printf("&local_static_init:%p\n", &local_static_init);
    printf("&global_str:       %p\n", &global_str);

    printf("\n=== .rodata ===\n");
    printf("global_str points: %p\n", global_str);

    printf("\n=== .bss ===\n");
    printf("&g_zero:           %p\n", &g_zero);
    printf("&g_arr:            %p\n", g_arr);
    printf("&s_zero:           %p\n", &s_zero);
    printf("&local_static_zero:%p\n", &local_static_zero);

    printf("\n=== stack ===\n");
    printf("&local:            %p\n", &local);
    printf("&heap_int:         %p\n", &heap_int);

    printf("\n=== heap ===\n");
    printf("heap_int points:   %p\n", heap_int);

    free(heap_int);
    return 0;
}
