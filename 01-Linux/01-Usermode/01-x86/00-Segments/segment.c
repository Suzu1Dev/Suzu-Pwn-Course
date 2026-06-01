#include<stdio.h>

int a; // .bss

int b = 10; // .data

const int c = 100; // .text


void owl (void){
	int owl_a; // .stack
	int owl_b = 2; // .stack
	static int owl_c = 999; // .data 的 static 區域
	printf("owl_d is handsome!"); // .rodata

	int owl_d; // handsome
}

