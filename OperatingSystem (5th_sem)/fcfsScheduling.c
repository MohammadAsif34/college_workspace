
#include <stdio.h>

int main() {
    int n;
    float avg_WT=0,avg_TAT=0;
    printf("Enter the number of Processes: ");
    scanf("%d", &n);
    
    int tab[n][5];  // tab[i][0] = AT, tab[i][1] = BT, tab[i][2] = CT, tab[i][3] = TAT, tab[i][4] = WT
    
    // Input arrival time and burst time
    printf("\nFCFS Scheduling (non-preemptive)\n");
    printf("Enter the process data : AT<space>BT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d :: ", i + 1);
        scanf("%d %d", &tab[i][0], &tab[i][1]);
    }
    
    // Calculate CT, TAT, and WT
    tab[0][2] = tab[0][0] + tab[0][1];  // CT of first process is AT + BT
    tab[0][3] = tab[0][2] - tab[0][0];  // TAT of first process
    tab[0][4] = tab[0][3] - tab[0][1];  // WT of first process

    for (int i = 1; i < n; i++) {
        tab[i][2] = tab[i - 1][2] + tab[i][1];  // CT = previous CT + current BT
        tab[i][3] = tab[i][2] - tab[i][0];      // TAT = CT - AT
        tab[i][4] = tab[i][3] - tab[i][1];      // WT = TAT - BT
    }

    // Output the result
    printf("\n+---------------------------------------------------+\n");
    printf("|\tP-id\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\t\t|");
    printf("\n+---------------------------------------------------+\n");
    for (int i = 0; i < n; i++) {
        printf("|\tP%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d \t\t|\n", i + 1, tab[i][0], tab[i][1], tab[i][2], tab[i][3], tab[i][4]);   
    }
    printf("+---------------------------------------------------+\n");
    for(int i=0; i<n; i++) {
        avg_TAT += tab[i][3];
        avg_WT += tab[i][4];
    }
    printf("\t The average TAT = %.2f ms\n",avg_TAT/n);
    printf("\t The average WT = %.2f ms\n",avg_WT/n);

    return 0;
}
