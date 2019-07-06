#include "ftpclient.h"

void pass_command() {

	printf("%s\n",buffer );
	if (strncmp(buffer, "Reply[200]", 10) == 0) {
			
		bzero(buffer, sizeof(buffer));
		recv(clientSocket, buffer, 10, 0);
		
		char cmd[30];
    	strcpy(cmd,"\e]2;");
    	strcat(cmd,"Client - ");
    	strcat(cmd,buffer);
    	strcat(cmd,"\a");
    	printf("%s",cmd);

    	bzero(buffer, sizeof(buffer));
	}
	
}