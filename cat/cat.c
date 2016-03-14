#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char ** argv) {
	char buf[256];
	ssize_t toDo = -1;
	while (!(toDo == 0)) {
		toDo = read(STDIN_FILENO, (void *)buf, 256);
		if(toDo == -1) {
			perror("Reading error.");
			return 1;
		} else if(toDo > 0) {
			ssize_t done = 0;
			while(toDo != done) {
				ssize_t btz = write(STDOUT_FILENO, (void *)(buf + done), toDo - done);
				if(btz == -1) {
					perror("Writing error.");
					return 1;
				}
				done += btz;

			}
		}
	}
	return 0;
}
