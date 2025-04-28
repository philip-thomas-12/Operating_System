#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    
    int requests[n];
    printf("Enter the request sequence: ");
    for(i = 0; i < n; i++)
        scanf("%d", &requests[i]);
    
    printf("Enter initial head position: ");
    scanf("%d", &head);
    
    int seek_count = 0;
    for(i = 0; i < n; i++) {
        seek_count += abs(requests[i] - head);
        head = requests[i];
    }
    
    printf("Total seek operations = %d\n", seek_count);
    return 0;
}
