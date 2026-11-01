#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int stack_var = 42;
    int *heap_array = (int *)calloc(3, sizeof(int));
    if (heap_array == NULL) {
        perror("calloc");
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        heap_array[i] = (i + 1) * 10;
    }

    printf("=== 1. Дослідження адрес (Stack vs Heap) ===\n");
    printf("[STACK] Адреса змінної stack_var:      %p\n", (void *)&stack_var);
    printf("[STACK] Адреса вказівника heap_array:  %p\n", (void *)&heap_array);
    printf("[HEAP]  Адреса динамічного масиву:     %p\n", (void *)heap_array);

    int *temp = (int *)realloc(heap_array, 5 * sizeof(int));
    if (temp == NULL) {
        perror("realloc");
        free(heap_array);
        return 1;
    }
    heap_array = temp;
    heap_array[3] = 40;
    heap_array[4] = 50;

    printf("\n=== 2. Стан масиву після realloc ===\n");
    printf("[HEAP]  Адреса масиву після realloc:   %p\n", (void *)heap_array);

    printf("\nВміст масиву в купі:\n");
    for (int i = 0; i < 5; i++) {
        printf("  heap_array[%d] = %d   (адреса елемента: %p)\n",
               i, heap_array[i], (void *)(heap_array + i));
    }

    free(heap_array);
    heap_array = NULL;
    return 0;
}