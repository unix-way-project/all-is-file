// Client side C/C++ program to demonstrate Socket programming
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define HOST_IP "127.0.0.1"
#define HOST_PORT 8080

int get_input_fd() {
	int input_fd = 0;

	return input_fd;
}

int get_output_fd() {
	int output_fd = 0;

	struct sockaddr_in address;

	if ((output_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("Socket creation error \n");
		exit(EXIT_FAILURE);
	}

	address.sin_family = AF_INET;
	address.sin_port = htons(HOST_PORT);

	// Convert IPv4 and IPv6 addresses from text to binary form
	if(inet_pton(AF_INET, HOST_IP, &address.sin_addr)<=0)
	{
		perror("Invalid address. Address not supported\n");
		exit(EXIT_FAILURE);
	}

	if (connect(output_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		perror("Connection Failed\n");
		exit(EXIT_FAILURE);
	}

	return output_fd;
}

int main(int argc, char const *argv[])
{

	int input_fd = get_input_fd();
	int output_fd = get_output_fd();

	char buffer[10];

	size_t count = 0;
	while((count = read(input_fd, buffer, sizeof(buffer))) > 0) {
	   printf("Sent to socket: %d chars\n", count);
		 write(output_fd, buffer, count);
	}

	return 0;
}
