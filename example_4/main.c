#include <stdio.h>
#include <stdlib.h>

int get_input_fd() {
  int input_fd = 0;

  return input_fd;
}

int get_output_fd() {
  int output_fd = 1;

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

   return 0;
}
