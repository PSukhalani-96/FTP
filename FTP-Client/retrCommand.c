#include "ftpclient.h"

void store_file(char *dest, char file[1024]) {

	FILE *fp1;
	fp1 = fopen(dest, "w");
	fprintf(fp1,"%s",file);
	fclose(fp1);
}

void retr_result() {

	/*Store File at client-site.*/
	if(strncmp(buffer,"Reply[610]",10) == 0) {
				
		char res[1024];
		bzero(buffer, sizeof(buffer));
			
		recv(clientSocket, buffer, MAXLINE, 0);
			
		strcpy(res, buffer);
		bzero(buffer, sizeof(buffer));

		recv(clientSocket,buffer, MAXLINE,0);
		strcpy(file_name, buffer);
			
		getcwd(buf,256);
    	strcat(buf,"/");
		strcat(buf, file_name);
		bzero(buffer, sizeof(buffer));
		store_file(buf, res);

		printf("File-Name: %s.\n", file_name);
		printf("File-Size: %ld bytes.\n", strlen(res));
		printf("Received Successfully.\n");
		printf("FILE OK...Transfer Completed.");
		printf("\n");
	}
}