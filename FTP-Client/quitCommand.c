#include "ftpclient.h"

void quit_command() {

	printf("\e]2;FTP-Client\a");
	printf("%s\n",buffer );
	close(clientSocket);
	exit(1);
	
}

void abor_command() {
	printf("\e]2;FTP-Client\a");	
}