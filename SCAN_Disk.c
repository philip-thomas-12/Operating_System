#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, disk_size;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    
    int requests[n];
    printf("Enter the request sequence: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &requests[i]);
    
    printf("Enter initial head position: ");
    scanf("%d", &head);
    
    printf("Enter total disk size: ");
    scanf("%d", &disk_size);

    // Sort requests
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(requests[i] > requests[j]) {
                int temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }

    int seek_count = 0, pos = 0;
    while(pos < n && requests[pos] < head) pos++;

    for(int i = pos; i < n; i++) {
        seek_count += abs(head - requests[i]);
        head = requests[i];
    }
    
    seek_count += abs(head - (disk_size - 1));
    head = disk_size - 1;

    for(int i = pos-1; i >= 0; i--) {
        seek_count += abs(head - requests[i]);
        head = requests[i];
    }
    
    printf("Total seek operations = %d\n", seek_count);
    return 0;
}
