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
    pid_t pProcessID;
    int iCounter;

    // Loop 5 times
    for (iCounter = 0 ; iCounter < 5 ; iCounter++) {
        pProcessID = fork();

        // Check to see if process has been created
        if (pProcessID >= 0) {
            // This is the child process
            if (pProcessID == 0) {
                loop(iCounter);
                print("This child processes has finished!\n");
                exit(0);
            }
        }
    }
    return 0;
}
