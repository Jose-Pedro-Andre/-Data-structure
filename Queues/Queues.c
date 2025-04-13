#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *enqueue(int *queue, int new, int *size)
{
    int j = *size;
    if (queue && *size > 0)
    { 
        j++;
        *size = j;
        int *newQueue = malloc(j * sizeof(int));
        int i = 0;
        while(i < j - 1)
        {
            
            newQueue[i] = queue[i];
            i++;
        }
        newQueue[i] = new;
        free(queue);
        return (newQueue);
    }
    else
    {
        *size = 1;
        queue = malloc(sizeof(int));
        queue[0] = new;
        return (queue);
    }
    return (NULL);
}

int *dequeue(int *queue, int *size)
{
    if (*size < 2)
    {
        free(queue);
        return NULL;
    }
    else
    {
        (*size)--;
        int i = 0;
        int j = 1;
        int *new = malloc(*size * sizeof(int));
        while (i < *size)
        {
            new[i] = queue[j];
            j++;
            i++;
        }
        free(queue);
        return (new);
    }
}

void peek(int *queue, int size)
{
    if (queue && size > 0)
        printf("%d\n", queue[0]);
}

bool is_empty(int *queue, int size)
{
    if (!queue || size == 0)
    {
        printf("the queue is empty\n");
        return (true);
    }
    else 
    {
        printf("there is element in queue\n");
        return (false);
    }
}


int main(int ac, char **av)
{
    int tm = 1;
    int *vet;
    vet = NULL;
    vet = enqueue(vet, 12, &tm);
    vet = enqueue(vet, 13, &tm);
    is_empty(vet, tm);
    vet = dequeue(vet, &tm);
    peek(vet, tm);
    vet = dequeue(vet, &tm);
    is_empty(vet, tm);
    free(vet);
}
