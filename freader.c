#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#define BUFF 100
int main()
{
	int fd;
	char buf[BUFF];
	FILE *fp;
	fd = open("myfifo", O_RDONLY);
	fp = fopen("output.txt", "w+");
	read(fd,buf,BUFF);
	fprintf(fp, "%s", buf);
	close(fd);
	fclose(fp);
	return 0;
}
