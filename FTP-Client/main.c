#include "ftpclient.h"

char buf[MAXLINE];
char file_name[1024];
int clientSocket;
char buffer[1024];

int main(int argc, char const *argv[])
{
	/*
        Objective:      To create a socket between FTP-CLIENT and FTP-SERVER & sending  
                        request to server using send-line and receiving server replies using
                        recv-line.

    */
	
	if(argc != 2) {
		printf("Use Following Command to execute Client.\n\t%s <server-hostname> \n\n", argv[0]);
        exit(EXIT_SUCCESS);
	}

	int ret;
	struct sockaddr_in serverAddr;		// Server Socket Address Structure

	/*================================================SOCKET-CREATION================================================*/
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);		// create socket
	if(clientSocket < 0){
		printf("Error in connection.\n");
		exit(1);
	}
	printf("\n");
	
	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr(argv[1]);

	/*==============================================SOCKET-CONNECTION===============================================*/
	ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));		// create connection
	// connect initiates three-way handshaking

	if(ret < 0){
		printf("Error in connection.\n");
		exit(1);
	}

	system("clear");

	printf("Client Socket is created.\n");
	printf("Connected to File Transfer server.\n");

	/*------------------------------------------------------------------------------------------------------------*/

	// Receive Menu from Server if connection is succesfully established.
	recv(clientSocket, buffer, MAXLINE, 0);
	printf("%s", buffer);
	bzero(buffer, sizeof(buffer));

	recv(clientSocket, buffer, MAXLINE, 0);
	printf("%s", buffer);
	bzero(buffer, sizeof(buffer));

	/*------------------------------------------------------------------------------------------------------------*/

	printf("\n");

	while(1){

		printf("\n%s",PROMPT);
		fgets (buffer, MAXLINE, stdin);	// take input from command line
		buffer[strlen(buffer)] = '\0';
		/*------------------------------------------------------------------------------------------------------------*/

		// Send the command to the server
		send(clientSocket, buffer, MAXLINE, 0);
		strcpy(buf,buffer);
		buf[strlen(buf)] = '\0';
		bzero(buffer, sizeof(buffer));

		/*===============================================STORE-COMMAND===============================================*/

		if (strncmp(buf,"STOR",4) == 0 || strncmp(buf,"stor",4) == 0) 
			store_command();	// will work only when STOR command is called.

		/*===========================================================================================================*/

    	bzero(buffer, sizeof(buffer));
		if(recv(clientSocket, buffer, MAXLINE, 0) < 0){
			printf("Error in receiving Line.\n");
			exit(1);
		}

		/*============================================PASS-COMMAND====================================================*/
		
		if ((strncmp(buf,"PASS",4) == 0 || strncmp(buf,"pass",4) == 0 ))
			pass_command();			// will work only when PASS command is called.

		else if(strncmp(buf,"QUIT",4) == 0 || strncmp(buf,"quit",4) == 0  )
			quit_command();			// will work only when QUIT command is called.

		else if(strncmp(buffer,"Reply[610]",10) == 0)
			retr_result();			// will work only when RETR command is called.

		else {
			if (strncmp(buf,"ABOR",4) == 0 || strncmp(buf,"abor",4) == 0)
				abor_command();		// will only when Abort command is called.
			printf("%s\n",buffer);	
		}
		bzero(buffer, sizeof(buffer));

		/*===========================================================================================================*/

	}
	return 0;
}