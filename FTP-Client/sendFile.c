#include "ftpclient.h"

void store_command() {
		
	char file[1024];
	char ch;
	char ans[1024];
	int k = 0;
			
	/*------------------------------------------------------------------------------------------------------------*/
	for(int i=5; i < strlen(buf); i++) {
		ans[k] = buf[i];
		k++;
	}
	strtok(ans,"\n");
	/*------------------------------------------------------------------------------------------------------------*/

	FILE *fp;
	if((fp = fopen(ans, "r")) != NULL) {
        		
        k = 0;
        ch = fgetc(fp);
    	while (ch != EOF) {
        	file[k] = ch;
        	k++;
        	ch = fgetc(fp);
    	}
    	file[k] = '\0';
    	fclose(fp);
    			
    	printf("Source-File-Path : %s\n", ans);
    	printf("File-Size        : %ld bytes\n", strlen(file));

    	strcpy(buffer, file);
    	send(clientSocket, buffer,MAXLINE, 0);
    	bzero(buffer, sizeof(buffer));
    }
    
    else {
			
		if(errno == ENOENT) {
            printf("Invalid Filename: File does not exist.\n");
        }
        else
        	printf("Error opening file.\n");
        send(clientSocket, "NULL", 4, 0);
    }
    /*------------------------------------------------------------------------------------------------------------*/
}