#include "gnl.h"
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int i = 0;
	int fd;
	int ret;
	char *buff;

	fd = open("pages.html",O_RDONLY);
	get_next_line(fd,&buff);
	while(1)
	{
		get_next_line(fd,&buff);
		if(buff[i] == '_')
			break;
		while(buff[i])
		{
			write(1,&buff[i],1);
			i++;
		}
		i = 0;
	}
}