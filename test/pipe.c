#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main( void )
{
    int fd[2];
    char buffer[20];

    if ( pipe(fd) < 0 ) {
        perror( "pipe" );
        exit( 1 );
    }

    switch( fork() ) {
        case -1:
            perror( "fork" );
            exit( 1 );

        case 0:
            /*child process*/
            close(fd[1]);
            ssize_t count = read( fd[0], buffer, sizeof(buffer)-1 );
            if ( count <= 0 ) {
                perror( "read" );
                exit( 1 );
            }
            buffer[count] = '\0';
            printf( "Child read message from parent: %s\n", buffer );
            exit(1);

        default:
            /*parent process*/
            close(fd[0]);
            char *message = "Hello from parent";
            size_t length = strlen( message );
            write( fd[1], message, length );
            break;
    }

    return 0;
}