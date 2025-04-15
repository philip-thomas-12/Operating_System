#include <stdio.h>
#include <unistd.h>

int main() {
    printf("PID of exec.c: %d\n", getpid());
    return 0;
}
