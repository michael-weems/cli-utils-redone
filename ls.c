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
void _ls(const char *dir, int op_a, int op_l) {
	struct dirent *d;
	DIR *dh = opendir(dir);

	if (!dh) {
		if (errno == ENOENT){
			perror("Directory doesn't exist");
		} 
		else {
			perror("Unable to read directory");
		}
		exit(EXIT_FAILURE);
	}

	while ((d = readdir(dh)) != NULL){
		if (!op_a && d->d_name[0] == '.') {
			continue;
		}
		
		printf("%s ", d->d_name);
		if (op_l) printf("\n");

	}	
}

int main(int argc, char *argv[]) {

	if (argc == 1) {
		_ls(".", 0, 0);
	}
	else if (argc == 2) {
		if (argv[1][0] == '-') {
			// checking if option is passed
			// options supporting: a, l
			int op_a = 0, op_l = 0;
			char *p = (char*)(argv[1] + 1);
			while (*p) {
				if (*p == 'a') op_a = 1;
				else if (*p == 'l') op_l = 1;
				else {
					perror("Option not available");
					exit(EXIT_FAILURE);
				}
				p++;
			}
			_ls(".", op_a, op_l);
		}
	}

	return 0;
}
