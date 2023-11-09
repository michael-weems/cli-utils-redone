#include <string.h>
// Used for basic input/output stream
#include <stdio.h>
#include <stdlib.h>
// Used for handling directory files
#include <dirent.h>
// For EXIT codes and error handling
#include <errno.h>

// VIM Alt keybindings remap: https://stackoverflow.com/questions/7501092/can-i-map-alt-key-in-vim
// to identify Opt + j/k --> sed -n l

// Reference implementation: https://iq.opengenus.org/ls-command-in-c/
void _ls(const char *dir, int op_a, int op_1) {
	struct dirent *d;
	DIR *dh = opendir(dir);

	if (!dh) {
		if (errno = ENOENT){
			perror("Directory doesn't exist");
		} 
		else {
			perror("Unable to read directory");
		}
		exit(EXIT_FAILURE);
	}

	
}

int main(int argc, char *argv[]) {
	
	printf("argc: %d   argv: %s\n", argc, argv[1]);

	char * directory_path = ".";	
	if (argc > 1) {
		// ! Only get the first arg passed (for now)
		directory_path = argv[1];
	}

	DIR *d;
	struct dirent *dir;
	d = opendir(directory_path);
	
	if (!d) {
		printf("Failed to read dir %s\n", directory_path);
	}
	
	while ((dir = readdir(d)) != NULL) {
		printf("%-10s   ", dir->d_name);
	}	
	closedir(d);
	
	return 0;
}
