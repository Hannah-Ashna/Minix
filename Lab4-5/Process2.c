#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

// Loop Function
void loop (int iProcessID){
    int iCounter;
    for (iCounter = 0; iCounter < 10; iCounter++) {
        printf("In process %d\n", iProcessID);
    }
}

int main( int argc, char *argv[]) {
    printf("The main program process has id %d\n", getpid() ); 
    pid_t childProcess = fork();

    // Check to see if process has been created
    if( childProcess >= 0 ) {
        if( childProcess == 0 ) {
            // This is the child process
            printf("New process has id %d, parent id %d\n", getpid(), getppid() );
            loop(2);
            exit(0);
        } else {
            // This is the parent process
            loop(1);
        }
    } else 
        printf("Error when trying to create a new process!\n"); 
    return 0;
}
