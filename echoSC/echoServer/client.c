#include "main.h"

int main (int argc, char *argv[])
{
	
	int sockFd = 0, clientFd = 0, bytesReceived = 0, bytesSent = 0, backlog = 4;
	struct sockaddr_in addr = {0};
	if(argc !=2)
	{
		//TODO give a usage message and exit the program
		printf("This is an error message!\n");
		exit(EXIT_FAILURE);
	}

}
