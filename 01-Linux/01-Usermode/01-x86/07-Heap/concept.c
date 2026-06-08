// 傳出去是 stack address，而且函示結束就掛了
int *make_array(int n) {
    int arr[n];
    return arr;   
}

// 傳出去是 heap address，可以一直活著
Player *create_player() {
    Player *p = malloc(sizeof(Player));
    p->hp = 100;
    return p;
}