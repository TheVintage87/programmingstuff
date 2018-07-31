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

	//create a socket that can connect with TCP/IP
	sockFd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockFd == -1 )
	{
		exit(EXIT_FAILURE);
	}
	printf("Socket Created\n");

	//TODO - populate the addr variable with the port and ip address
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8888);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	socklen_t addrlen = sizeof(addr);

	//TODO - bind the socket to the ip address and port
	if(bind(sockFd, (struct sockaddr *)&addr, addrlen) < 0)
      	{
		perror("bind failed. Error");
	}	
	printf("Socket is bound\n");

	//TODO - set up the socket to be listening
	if(listen(sockFd, backlog) == -1)
	{
		perror("Listening error");
	}
	printf("Listening...\n");
	while(1)
	{
		//TODO - accept connection
		clientFd = accept(sockFd, (struct sockaddr *)&addr, &addrlen);
		printf("Recieved Connection!\n");
	
		//TODO - once connections is accepted, receive entire message
		//	from the client and then send it back.
		while(1)
		{
			//TODO - allocate memory for receiving
			char* buf = calloc(10, 1);


			//TODO - receive the message until it has been completely received
			if(recv(clientFd, buf, 2, 0) < 0)
			{
				printf("Receive Failed\n");
			}

			//TODO - send the message to the client
			if(send(clientFd, buf, 2, 0) < 0)
			{
				printf("Send failed\n");
			}
			
			//TODO - clean up buffer memory to avoid memory leak
			free(buf);
		}
		//TODO - shutdown connection with client gracefully
	}

	return 0;

}

/*int createTcpSocket()
{
	int sockFd = 0;

	sockFd = socket(AF_INET, SOCK_STREAM, 0);

	//check for error
	if(sockFd == -1)
	{
		perror("socket");
	}

	//TODO - make socket reusable (man setsockopt, man 7 socket)
	int setsockopt(
		
	return sockFd;
}

int populateAddrInfo (char *port, char *ipAddr, struct sockaddr_in *addr)
{*/
	
