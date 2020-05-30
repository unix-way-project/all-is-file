
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

	int server_fd;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);

	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
			perror("socket failed");
			exit(EXIT_FAILURE);
	}

	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
																								&opt, sizeof(opt)))
	{
			perror("setsockopt");
			exit(EXIT_FAILURE);
	}

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons( HOST_PORT );

	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
	{
			perror("bind failed");
			exit(EXIT_FAILURE);
	}

	if (listen(server_fd, 3) < 0)
	{
			perror("listen");
			exit(EXIT_FAILURE);
	}

	if ((input_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
	{
			perror("accept");
			exit(EXIT_FAILURE);
	}

	return input_fd;
}

int get_output_fd() {
	int output_fd = 1;
}

int main(int argc, char const *argv[])
{
		char buffer[10];

		int input_fd = get_input_fd();
		int output_fd = get_output_fd();

		size_t count = 0;
		while((count = read(input_fd, buffer, sizeof(buffer))) > 0) {
		   printf("Got from socket: %d chars\n", count);
			 write(output_fd, buffer, count);
		}

    return 0;
}
