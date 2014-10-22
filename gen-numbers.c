#include <stdio.h>
#include <assert.h>

typedef struct {
  int x;
  int y;
} div_value;

int main() {
  div_value values[] = {
    {7331, 1},
    {14662, 2},
    {21994, 3},
    {29326, 4},
    {36657, 5}
  };
  FILE * output = fopen("numbers.dat", "w");
  assert(output != NULL);
  fwrite((void *)values, 1, sizeof(values), output);
  fclose(output);
  return 0;
}
