#include <stdio.h>
int main() {
    int total_mem, os_size, ms, mp[10], i, temp, n = 0;
    char ch = 'y';
    printf("\nEnter the total memory available (in Bytes) -- ");
    scanf("%d", &total_mem);
    printf("Enter the size of OS (in Bytes) -- ");
    scanf("%d", &os_size);
    ms = total_mem - os_size;
    temp = ms;
    printf("Memory available for processes after OS allocation: %d Bytes\n", ms);
    for (i = 0; ch == 'y'; i++, n++) {
        printf("\nEnter memory required for process %d (in Bytes) -- ", i + 1);
        scanf("%d", &mp[i]);
        if (mp[i] <= temp) {
            printf("\nMemory is allocated for Process %d ", i + 1);
            temp = temp - mp[i];  // Reduce available memory
        } else {
            printf("\nMemory is Full");
            break;
        }
        printf("\nDo you want to continue (y/n) -- ");
        scanf(" %c", &ch);  // Include space before %c to consume newline
    }
    printf("\n\nTotal Memory Available -- %d", total_mem);
    printf("\nMemory allocated for OS -- %d", os_size);
    printf("\nMemory available for processes -- %d", ms);
    printf("\n\n\tPROCESS\t\tMEMORY ALLOCATED ");
    for (i = 0; i < n; i++)
        printf("\n\t%d\t\t%d", i + 1, mp[i]);
    printf("\n\nTotal Memory Allocated is %d", ms - temp);
    printf("\nTotal External Fragmentation is %d\n", temp);

    return 0;
}