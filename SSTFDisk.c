#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, head;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    
    int requests[n], served[n];
    printf("Enter the request sequence: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
        served[i] = 0; // mark as unserved
    }
    
    printf("Enter initial head position: ");
    scanf("%d", &head);
    
    int seek_count = 0;
    for(int done = 0; done < n; done++) {
        int min = INT_MAX, index = -1;
        for(int i = 0; i < n; i++) {
            if(!served[i] && abs(head - requests[i]) < min) {
                min = abs(head - requests[i]);
                index = i;
            }
        }
        seek_count += min;
        head = requests[index];
        served[index] = 1;
    }
    
    

     printf("Total seek operations = %d\n", seek_count);
    return 0;
}
