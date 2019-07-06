#include "ftp.h"

int remove_directory(const char *path_name) {

	/*
		Objective:      To remove a directory given by path-name when Ftp-Client requests
										RMD <path-of-directory-to-be-removed>
		Return Type:    Integer
							return 339: Permission Denied
							return 340: Invalid Directory
							return 341: could not change directory(while parsing the path).
							return 0  : Directory successfully removed.
							return -1 : Directory can't be removed.
		Parameter:      
			char *path_name:    specifies the path to be removed.
		Approach:       First resolving the path using structure 'dirent', until last directory is 
						reached.
						For a directory to be removed, it needs to be empty(which is done by unlink()).
						then, rmdir() is used to remove the directory.

	*/

	char path[256];
	strcpy(path, path_name);
	strtok(path, "\n");
	
	DIR *d = opendir(path);
	size_t path_len = strlen(path);
	int r = -1;

	// struct stat statbuf;
	// if (stat(path, &statbuf) == 0) {
	// 	char ans[1024];
	// 	strcpy(ans, "rm -r ");
	// 	strcat(ans, path);
	// 	strcat(ans, "/");
	// 	system(ans);
	// 	return 0;
	// }

	if (d) {
		struct dirent *p;

		r = 0;

		while (!r && (p=readdir(d)))
		{
			int r2 = -1;
			char *buf;
			size_t len;

			if (!strcmp(p->d_name, ".") || !strcmp(p->d_name, ".."))
				continue;

			len = path_len + strlen(p->d_name) + 2; 
			buf = malloc(len);

			if (buf)
			{
				struct stat statbuf;
				snprintf(buf, len, "%s/%s", path, p->d_name);

				if (!stat(buf, &statbuf))
				{
					/* Check if current item is a directory or not. */
					if (S_ISDIR(statbuf.st_mode))
						r2 = remove_directory(buf);
					else
						r2 = unlink(buf);
				}
				else {
					if(errno == EACCES) 
						return 339;
					else if(errno == ENOTDIR || errno == ENOENT) 
						return 340;
					else 
						return 341;
				}
				
				free(buf);
			}
			r = r2;
		}
		closedir(d);
	}

	if (!r)
		r = rmdir(path);

   return r;
}