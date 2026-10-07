#include <stdio.h>
int main() {
    int m, i = 0, p[15];
    char ch;
    printf("Enter memory to be allocated: ");
    scanf("%d", &m);
    
    printf("Enter process size: ");
    scanf("%d", &p[i]);
    
    do {
        m = m - p[i];
        printf("\nRemaining memory is %d\n", m);
        
        printf("Do you want to continue (y/n): ");
        fflush(stdin);
        scanf(" %c", &ch); 
        
        if (ch == 'y') {
            i++;
            if (i >= 15) {
                printf("Maximum number of processes reached.\n");
                break;
            }
            printf("Enter the process size: ");
            scanf("%d", &p[i]);
        } else {
            printf("\nExternal fragmentation is %d\n", m);
            break;
        }
        
        if (m < p[i]) {
            printf("\nRequired memory is not available\n");
        
            m += p[i];
            i--; 
        }
    } while ((ch == 'y') && (m >= 0));

    return 0;
}
