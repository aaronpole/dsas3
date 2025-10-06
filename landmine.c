#include <stdio.h>

int main(){

    int grid[4][4] ={
        {0,0,0,0},
        {0,0,0,0},
        {0,1,0,0},
        {0,0,0,0}
    };

    int data[4][4];
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            data[i][j] = -1;
        }
    }

    int mineX, mineY;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (grid[i][j] == 1){
                mineX = i;
                mineY = j;
            }
        }
    }
    data[mineX][mineY] = 0;

    printf("Landmine found at (%d,%d)\n", mineX, mineY);

    typedef struct {
        int x,y;
    } Point;

    Point queue[16];
    int front = 0, rear = 0;
    queue[rear++] = (Point){mineX,mineY};

    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};

    while (front < rear){
        Point p = queue[front++];
        int x = p.x ,y = p.y;

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && data[nx][ny] == -1){
                data[nx][ny] = data[x][y] + 1;
                queue[rear++] = (Point){nx, ny};
            }
        }
    }
    printf("Distance from landmine:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            printf("%d ", data[i][j]);
        printf("\n");
    }
}