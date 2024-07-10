#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Selection Sort
int selection_sort(int data[], int n, int *comparisons, int *passes) {
  *comparisons = 0;
  *passes = 0;

  for (*passes = 0; *passes < n - 1; ++(*passes)) {
    int min_index = *passes;
    for (int i = *passes + 1; i < n; ++i) {
      (*comparisons)++;
      if (data[i] < data[min_index]) {
        min_index = i;
      }
    }
    if (min_index != *passes) {
      swap(&data[*passes], &data[min_index]);
    }
  }

  return 0;
}

// Bubble Sort
int bubble_sort(int data[], int n, int *comparisons, int *passes) {
  *comparisons = 0;
  *passes = 0;

  for (*passes = 0; *passes < n - 1; ++(*passes)) {
    int swapped = 0;
    for (int i = 0; i < n - 1 - *passes; ++i) {
      (*comparisons)++;
      if (data[i] > data[i + 1]) {
        swap(&data[i], &data[i + 1]);
        swapped = 1;
      }
    }
    if (!swapped) {
      break;  // Early termination if no swaps in a pass
    }
  }

  return 0;
}

// Insertion Sort
int insertion_sort(int data[], int n, int *comparisons, int *passes) {
  *comparisons = 0;
  *passes = 0;

  for (*passes = 1; *passes < n; ++(*passes)) {
    int key = data[*passes];
    int j = *passes - 1;

    while (j >= 0 && data[j] > key) {
      (*comparisons)++;
      data[j + 1] = data[j];
      j--;
    }
    data[j + 1] = key;
  }

  return 0;
}

int main() {
  int data[] = {5, 2, 8, 1, 3};
  int n = sizeof(data) / sizeof(data[0]);

  int comparisons, passes;

  // Selection Sort
  selection_sort(data, n, &comparisons, &passes);
  printf("Selection Sort:\n");
  printf("  Passes: %d\n", passes);
  printf("  Comparisons: %d\n", comparisons);

  // Bubble Sort (reset data)
  for (int i = 0; i < n; ++i) {
    data[i] = {5, 2, 8, 1, 3}[i]; // Reset data for each sort
  }

  bubble_sort(data, n, &comparisons, &passes);
  printf("Bubble Sort:\n");
  printf("  Passes: %d\n", passes);
  printf("  Comparisons: %d\n", comparisons);

  // Insertion Sort (reset data)
  for (int i = 0; i < n; ++i) {
    data[i] = {5, 2, 8, 1, 3}[i]; // Reset data for each sort
  }

  insertion_sort(data, n, &comparisons, &passes);
  printf("Insertion Sort:\n");
  printf("  Passes: %d\n", passes);
  printf("  Comparisons: %d\n", comparisons);

  return 0;
}

