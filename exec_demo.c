#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"Hello", "S4_IT", NULL};  // Arguments for exec

    printf("PID of exec_demo.c = %d\n", getpid());

    // Execute another program
    execv("./exec", args);

    // If exec() fails, print error message
    perror("exec failed");
    printf("Ending...\n");

    return 0;
}
