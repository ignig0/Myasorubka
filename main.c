#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>


#include "queue.h"



int main() {
    int n;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    printf("Введите ряд чисел.Чтобы закончить ввод ввведите end\n");
    FILE *file = NULL;
    file = fopen("C:/Users/Velokoleso/Documents/проги на с/Прога 3/sp.txt","w");
    Queue *q = (Queue *) calloc(1, sizeof(Queue));

    while (scanf("%d",&n)==1){
        queue_put(q, n);
    }



    queue_fprint(q,file);
    queue_print(q);
    queue_sort(q);
    fseek(file, 0, SEEK_END);
    queue_fprint(q,file);
    queue_print(q);

    fclose(file);
    queue_delete(q);
    return 0;
}
