#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 100000

int g[N][N];
bool vis[N];

void Add_edge(int u, int v){
    g[u][v] = true;
}

bool is_connected(int n){
    for(int i=1; i<=n; i++){
        vis[i] = false;
        dfs(i,n);
    }
    
    for(int i=1; i<=n; i++){
        if(!vis[i])
            return false;
    }
    return true;
}

void dfs(int x, int n){
    vis[x]= true;
    for (int i = 1; i <= n; i++)
        if (g[x][i] && !vis[i])
            dfs(i, n);
}

void main()
{
    int n = 4;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)  
            g[i][j] = 0;
    Add_edge(1, 2);
    Add_edge(2, 3);
    Add_edge(3, 4);
    if (is_connected(n))
        printf("Yes");
    else
        printf("No");
}
