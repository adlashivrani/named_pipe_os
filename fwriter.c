#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define BUFF 100
int main()
{
	int fd;
	FILE *fp;
	int i;
	char ch;
	char buf[BUFF];
	mkfifo("myfifo", 0666);
	fd = open("myfifo", O_WRONLY);
	fp = fopen("input.txt", "r");
	while ((ch = fgetc(fp)) != EOF) {
		buf[i] = ch;
		i++;
	}
	write(fd, buf, BUFF);
	close(fd);
	fclose(fp);
	return 0;
}
