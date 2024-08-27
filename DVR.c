#include <stdio.h>

int main() {
    int i, n, r[20], s, de, ns, rns[20], j, m[20][20], d[20];
    int dis[20], min = 0, index;
    
    // Initialize distance array
    for (i = 0; i < 20; i++)
        dis[i] = 0;
    
    printf("Enter number of routers: ");
    scanf("%d", &n);
    
    printf("Enter the names of the routers: ");
    for (i = 0; i < n; i++)
        scanf("%d", &r[i]);
    
    printf("Enter the source router: ");
    scanf("%d", &s);
    
    printf("Enter the destination router: ");
    scanf("%d", &de);
    
    printf("Enter number of neighbors for the source: ");
    scanf("%d", &ns);
    
    printf("Enter the names of the neighbors of the source: ");
    for (i = 0; i < ns; i++)
        scanf("%d", &rns[i]);
    
    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
            if (m[i][j] == 0)
                m[i][j] = 99; // Consider 99 as infinity for non-direct paths
        }
    }
    
    printf("The delays from neighbors are:\n");
    for (i = 0; i < ns; i++) {
        dis[i] = m[s-1][rns[i]-1] + m[rns[i]-1][de-1];
        printf("%d\t", dis[i]);
    }
    
    // Find the minimum distance
    min = dis[0];
    index = 0;
    for (i = 1; i < ns; i++) {
        if (min > dis[i]) {
            min = dis[i];
            index = i;
        }
    }
    
    printf("\nMinimum distance from router %d to %d is through router %d with a cost of %d\n", s, de, rns[index], min);
    
    return 0;
}