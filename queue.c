#include "queue.h"


void queue_put(Queue *queue, int inf) {
    Elem *new = (Elem *) malloc(sizeof(Elem));
    new->inf = inf;
    new->link = NULL;
    if (!queue->BegQ) {
        queue->BegQ = new;
        queue->EndQ = new;
    }
    else {
        queue->EndQ->link = new;
        queue->EndQ = new;
    }

}

void queue_delete(Queue *queue) {
    Elem *current = queue->BegQ;
    while (current) {
        Elem *prev = current;
        current = current->link;
        free(prev);
    }
    free(queue);
}

void queue_print(const Queue *queue) {
    Elem *current = queue->BegQ;
    while (current) {
        printf("%d ", current->inf);
        current = current->link;
    }
    printf("\n");
}
void queue_fprint(const Queue *queue,FILE  *file) {
    Elem *current = queue->BegQ;
    while (current) {
        fprintf(file,"%d ", current->inf);
        current = current->link;
    }
    fprintf(file,"\n");
}

void queue_sort(Queue *queue) {
    if (queue->BegQ == NULL) {
        return;
    }

    Elem *current = queue->BegQ;

    while (current != NULL) {

        Elem *max  = current;
        Elem *link = current->link;

        while (link != NULL) {
            if (link->inf > max->inf) {
                max = link;
            }
            link = link->link;
        }


        if (max != current) {
            int temp = current->inf;
            current->inf = max->inf;
            max->inf = temp;
        }

        current = current->link;
    }
}
