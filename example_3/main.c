#include <stdio.h>
#include <stdlib.h>

int get_input_fd() {
  FILE *input_fptr;
  if ((input_fptr = fopen("./input.txt","r")) == NULL){
      perror("Error! opening file\n");
      exit(EXIT_FAILURE);
  }

  int input_fd = fileno(input_fptr);

  printf("File descriptior of ./input.txt is %d\n", input_fd);

  return input_fd;
}

int get_output_fd() {
  FILE *output_fptr;
  if ((output_fptr = fopen("./output.txt","w+")) == NULL){
      perror("Error! opening file\n");
      exit(EXIT_FAILURE);
  }

  int output_fd = fileno(output_fptr);

  printf("File descriptior of ./output.txt is %d\n", output_fd);

  return output_fd;
}

int main(int argc, char const *argv[])
{
   int input_fd = get_input_fd();
   int output_fd = get_output_fd();

   char buffer[10];

   size_t count = 0;
   while((count = read(input_fd, buffer, sizeof(buffer))) > 0) {
      printf("Got from socket: %d chars\n", count);
      write(output_fd, buffer, count);
   }

   close(input_fd);
   close(output_fd);

   return 0;
}
