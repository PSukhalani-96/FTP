#include "ftp.h"

char list[1024];

int list_directories() {

    /*
        Objective:      To list all the directories/files present in currently working directory
        Return Type:    Integer
                            return 346: Error in Opening Directory.
                            return 0: Display directories/files in currently working directory.
        Parameter:      None
        Approach:       perform by reading the currently working directory using structure 'dirent'.
    */

        DIR * directory;
        struct dirent * entry;
        *list = '\0';

        if (strlen(arg) > 1) {
            strtok(arg, "\n");
            if ((directory = opendir(arg)) == NULL)
                return 346;
        }
        else {
            if((directory = opendir("./")) == NULL) {
                return 346;
            }
        }
	
	    while((entry = readdir(directory)) != NULL) {
            if((strcmp(entry->d_name, ".") != 0) && (strcmp(entry->d_name, "..") != 0)) {
                strcat(list, "-> ");
                strcat(list, entry->d_name);
                strcat(list,"\n");
            
            }
        }

        closedir(directory);
    
    return 0;
}