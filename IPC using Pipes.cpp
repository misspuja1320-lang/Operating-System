#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int p1[2], p2[2], p3[2], p4[2];
    int i, j = 0, k = 0, l = 0;
    char r[10], s[10], t[10], u[10];

    printf("\t PROCESS 1. ENTER THE STRING: ");
    scanf("%s", r);
    
    // Create pipes
    pipe(p1);
    pipe(p2);
    
    // Write the string to both pipes
    write(p1[1], r, strlen(r) + 1); // Include null terminator
    write(p2[1], r, strlen(r) + 1); // Include null terminator

    int a = fork();
    if (a == 0) { // Child process 2
        printf("\n\t PROCESS 2: it splits the given string\n");
        read(p1[0], r, sizeof(r));
        int n = strlen(r);
        
        // Split the string into two halves
        for (i = 0; i < n / 2; i++) {
            s[i] = r[i];
        }
        s[i] = '\0'; // Null terminate the first half
        
        for (i = n / 2; i < n; i++) {
            t[j++] = r[i];
        }
        t[j] = '\0'; // Null terminate the second half

        // Create pipes for child processes
        pipe(p3);
        pipe(p4);
        
        // Write the halves to the respective pipes
        write(p3[1], s, strlen(s) + 1);
        write(p4[1], t, strlen(t) + 1);
        
        int b = fork();
        if (b == 0) { // Child process 4
            printf("p4 %d\t", getpid());
            printf("p2 %d\n", getppid());
            read(p3[0], s, sizeof(s));
            printf("\t PROCESS 4: sub string \t %s \t", s);
            printf("no of char=%d \n", strlen(s));
        } else {
            int c = fork();
            if (c == 0) { // Child process 5
                printf("p5 %d\t", getpid());
                printf("p2 %d\n", getppid());
                read(p4[0], t, sizeof(t));
                printf("\t PROCESS 5: sub string \t %s \t", t);
                printf("no of char=%d \n", strlen(t));
            } else {
                wait(NULL); // Wait for child 4
                wait(NULL); // Wait for child 5
                printf("p2 %d\t", getpid());
                printf("p1 %d\n", getppid());
            }
        }
    } else { // Parent process
        wait(NULL); // Wait for child 2
        int d = fork();
        if (d == 0) { // Child process 3
            printf("p3 %d\t", getpid());
            printf("p1 %d\n", getppid());
            read(p2[0], r, sizeof(r));
            for (i = strlen(r) - 1; i >= 0; i--) {
                u[l++] = r[i];
            }
            u[l] = '\0'; // Null terminate the reversed string
            
            // Check if the string is a palindrome
            for (i = 0; i < strlen(r); i++) {
                if (u[i] == r[i]) {
                    k++;
                }
            }
            if (k == strlen(r)) {
                printf("\t PROCESS 3: the given string is palindrome\n");
            } else {
                printf("\t PROCESS 3: the given string is not palindrome\n");
            }
        } else {
            printf("p1 %d\t", getpid());
            printf("kernel %d\t\n", getppid());
        }
    }

    return 0;
}
