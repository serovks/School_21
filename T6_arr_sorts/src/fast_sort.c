#include <stdio.h>
#define N 10

int input(int *a);
void output(int *a);
void heapify(int *arr, int n, int i);         // построение max-кучи
void heapSort(int *arr, int n);               // сортировка кучей
void swap(int *a, int *b);                    // Функция для обмена элементов
int partition(int *arr, int low, int high);   // Функция разделения
void quickSort(int *arr, int low, int high);  // Итеративная QuickSort

int main() {
    int arr[N];
    int arr_copy[N];
    if (input(arr) == 1) {
        printf("n/a");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        arr_copy[i] = arr[i];
    }

    // first sort
    quickSort(arr, 0, N - 1);
    output(arr);

    printf("\n");
    // second sort
    heapSort(arr_copy, N);
    output(arr_copy);
    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];  // Опорный элемент (последний)
    int i = low - 1;        // Индекс меньшего элемента

    for (int j = low; j < high; j++) {
        // Если текущий элемент меньше или равен pivot
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);  // Ставим pivot на правильное место
    return i + 1;
}

void quickSort(int *arr, int low, int high) {
    // Создаем стек в виде массива
    int stack[high - low + 1];
    int top = -1;  // Вершина стека

    // Кладем начальные low и high в стек
    stack[++top] = low;
    stack[++top] = high;

    // Пока стек не пуст
    while (top >= 0) {
        // Извлекаем low и high
        high = stack[top--];
        low = stack[top--];

        // Получаем индекс pivot
        int pivot = partition(arr, low, high);

        // Если есть элементы слева от pivot, кладем в стек
        if (pivot - 1 > low) {
            stack[++top] = low;
            stack[++top] = pivot - 1;
        }

        // Если есть элементы справа от pivot, кладем в стек
        if (pivot + 1 < high) {
            stack[++top] = pivot + 1;
            stack[++top] = high;
        }
    }
}

void heapify(int *arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;

    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int input(int *a) {
    char c;
    for (int i = 0; i < N; i++) {
        if (scanf("%d%c", &a[i], &c) != 2 || (i < N - 1 && c != ' ') || (i == N - 1 && c != '\n')) {
            return 1;
        }
    }

    return 0;
}

void output(int *a) {
    printf("%d", a[0]);
    for (int i = 1; i < N; i++) {
        printf(" %d", a[i]);
    }
}
