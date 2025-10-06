#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 11  // Max 10-liter +1 for array

typedef struct {
    int x, y, z;  // amount in 10L, 7L, 4L
} State;

int visited[MAX][8][5];  // visited[x][y][z]

int min(int a, int b){ return (a < b)? a : b; }

int bfs(){
    State queue[1000];
    int front=0, rear=0;

    State start = {0,7,4};
    queue[rear++] = start;
    visited[start.x][start.y][start.z] = 1;

    while(front < rear){
        State s = queue[front++];

        // Check goal
        if(s.y == 2 || s.z == 2){
            printf("Found solution: (%d, %d, %d)\n", s.x, s.y, s.z);
            return 1;
        }

        int capacities[3] = {10, 7, 4};
        int amounts[3] = {s.x, s.y, s.z};

        // Try all pourings between containers
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==j) continue;
                if(amounts[i]==0 || amounts[j]==capacities[j]) continue;

                int pour = min(amounts[i], capacities[j]-amounts[j]);
                int newAmounts[3] = {amounts[0], amounts[1], amounts[2]};
                newAmounts[i] -= pour;
                newAmounts[j] += pour;

                if(!visited[newAmounts[0]][newAmounts[1]][newAmounts[2]]){
                    visited[newAmounts[0]][newAmounts[1]][newAmounts[2]] = 1;
                    State newState = {newAmounts[0], newAmounts[1], newAmounts[2]};
                    queue[rear++] = newState;
                }
            }
        }
    }

    return 0; // No solution
}

int main(){
    memset(visited,0,sizeof(visited));
    if(!bfs())
        printf("No solution found.\n");
    return 0;
}
