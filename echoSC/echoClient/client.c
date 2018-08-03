#include "main.h"
#include <errno.h>
#define SIZE 100

int main (int argc, char *argv[])
{
	
	int sockFd = 0; // clientFd = 0, bytesReceived = 0, bytesSent = 0, backlog = 4;
	struct sockaddr_in addr = {0};
	char *userMessage = NULL;
	//uint input = {0};
	if(argc !=2)
	{
		//TODO give a usage message and exit the program
		printf("This is an error message!\n");
		exit(EXIT_FAILURE);
	}

	//create a socket that can connect with TCP/IP
	sockFd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockFd == -1 )
	{
		exit(EXIT_FAILURE);
	}
	printf("Socket Created %d\n", sockFd);

	//TODO - populate the addr variable with the port and ip address
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8888);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	socklen_t addrlen = sizeof(addr);

	//Connect to remote server
	if (connect(sockFd , (struct sockaddr *)&addr, addrlen) < 0)
	//if (connect(sockFd , (struct sockaddr *)&addr, sizeof(addr)) < 0)
	{
		perror("Connection to server failed");
		printf("Error number = %d\n", errno);
	}

	printf("Connected!\n");
	while(1)
	{
		char* buf = calloc(SIZE, sizeof(char));
		//Get user input for a message to the server
		printf("Enter a message: ");
		if((fgets(buf, SIZE, stdin)) < 0)	
		//if(buf < 0)
		{
			printf("Must enter a message!\n");
		}
		
		//Send user message to server
		if(send(sockFd, buf, 2, 0) < 0)
		{
			printf("Send failed\n");
		}
		
		//Receive message back from the server
		if(recv(sockFd, buf, 2, 0) < 0)
		{
			printf("Receive Failed\n");
		}
		printf("Reply from Server: %s\n", buf);

		//clean up buffer memory to avoid memory leak
		free(buf);
	}
	
}
