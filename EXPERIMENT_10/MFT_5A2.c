#include <stdio.h>
int main() {
    int total_mem, os_size, mem_size, bs, nob, ef, n;
    int mp[10], tif = 0;
    int i, p = 0;
    printf("Enter the total memory available (in Bytes) -- ");
    scanf("%d", &total_mem);
    printf("Enter the size of OS (in Bytes) -- ");
    scanf("%d", &os_size);
    mem_size = total_mem - os_size;
    printf("Memory available for processes after OS allocation: %d Bytes\n", mem_size);
    printf("Enter the block size (in Bytes) -- ");
    scanf("%d", &bs);
    nob = mem_size / bs;
    ef = mem_size - nob * bs;
    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter memory required for process %d (in Bytes) -- ", i + 1);
        scanf("%d", &mp[i]);
    }
    printf("\nNo. of Blocks available in memory -- %d", nob);
    printf("\n\nPROCESS\tMEMORY REQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION");
    for (i = 0; i < n && p < nob; i++) {
        printf("\n%d\t\t%d", i + 1, mp[i]);
        if (mp[i] > bs) {
            printf("\t\tNO\t\t---");
        } else {
            printf("\t\tYES\t\t%d", bs - mp[i]);
            tif += bs - mp[i]; 
            p++;
        }
    }
    if (i < n) {
        printf("\nMemory is full; remaining processes cannot be accommodated.");
    }
    printf("\n\nTotal Internal Fragmentation is %d", tif);
    printf("\nTotal External Fragmentation is %d\n", ef);

    return 0;
}