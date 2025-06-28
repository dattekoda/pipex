//置き換えだけを体験するシンプル版

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

extern char	**environ;

int	main(void)
{
	printf("Before execve\n");
	fflush(stdout);
	char *const argv[] = {"ls", "-l", NULL};
	//execveが成功すると、この先は実行されない。
	execve("/bin/ls", argv, environ);
	//失敗時は戻ってくる。
	perror("execve");
	return (1);
}