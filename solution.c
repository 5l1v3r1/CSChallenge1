#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int x;
  int y;
} div_value;

int evaluate(div_value v);

int main() {
  FILE * file = fopen("numbers.dat", "r");
  assert(file != NULL);
  
  // Get the size of the file
  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  fseek(file, 0, SEEK_SET);
  
  // Allocate enough values and read them from the file
  div_value * values = (div_value *)malloc(size);
  fread((void *)values, 1, size, file);
  
  // Don't need the file anymore
  fclose(file);
  
  // Compute the mean
  int i, sum = 0;
  int count = (int)(size / sizeof(div_value));
  for (i = 0; i < count; ++i) {
    sum += evaluate(values[i]);
  }
  int mean = sum / count;
  
  // Don't need the values anymore
  free(values);
  
  // Convert it to a string
  char numStr[32];
  sprintf(numStr, "%d", mean);
  
  // Reverse the string
  for (i = 0; i < strlen(numStr) / 2; ++i) {
    int endIdx = strlen(numStr) - (i + 1);
    
    char old = numStr[i];
    numStr[i] = numStr[endIdx];
    numStr[endIdx] = old;
  }
  
  printf("Result: %s\n", numStr);
  return 0;
}

int evaluate(div_value v) {
  return v.x / v.y;
}
