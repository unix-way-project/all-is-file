#include <stdio.h>
#include <stdlib.h>

FILE *get_input_file() {
  FILE *input_fptr;
  if ((input_fptr = fopen("./input.txt","r")) == NULL){
      perror("Error! opening file\n");
      exit(EXIT_FAILURE);
  }

  return input_fptr;
}

FILE *get_output_file() {
  FILE *output_fptr;
  if ((output_fptr = fopen("./output.txt","w+")) == NULL){
      perror("Error! opening file\n");
      exit(EXIT_FAILURE);
  }

  return output_fptr;
}

int main(int argc, char const *argv[])
{
   FILE *input_fptr = get_input_file();
   FILE *output_fptr = get_output_file();

   while(1) {}

   char buffer[10];

   size_t count = 0;
   while((count = fread(buffer, 1, sizeof(buffer), input_fptr)) > 0) {
      printf("Got from file: %d chars\n", count);
      fwrite(buffer, 1, count, output_fptr);
   }

   fclose(input_fptr);
   fclose(output_fptr);

   return 0;
}
