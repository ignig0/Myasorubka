#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>


#include "queue.h"



int main(int argc, char *argv[]) {
    int n;

    if (argc>=3){

       if (strcmp(argv[1],"--file")==0){

         FILE *file = NULL;
         char str[50];
         file = fopen("sp.txt","r");
         fseek(file, 0, SEEK_SET);
         if(fgets(str,50,file)!=NULL){

            printf("���������� ���: %s", str);

         }
         if(fgets(str,50,file)!=NULL){

            printf("����������  ��������������� ���: %s", str);
        }

       }
    }
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    printf("������� ��� �����.����� ��������� ���� �������� end\n");
    FILE *file = NULL;
    file = fopen("C:/Users/Velokoleso/Documents/����� �� �/����� 3/sp.txt","w");
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
