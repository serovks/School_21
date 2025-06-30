#include <stdio.h>

#define N 15
#define M 13

void transform(int *buf, int **matr, int n, int m);
void make_picture(int **picture, int n, int m);
void reset_picture(int **picture, int n, int m);
void print_picture(int **picture, int n, int m);

int main() {
    int picture_data[N][M];
    int *picture[N];
    transform((int *)picture_data, picture, N, M);

    make_picture(picture, N, M);
    print_picture(picture, N, M);

    return 0;
}

void make_picture(int **picture, int n, int m) {
    int frame_w[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int frame_h[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int tree_trunk[] = {7, 7, 7, 7};
    int tree_foliage[] = {3, 3, 3, 3};
    int sun_data[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                          {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

    reset_picture(picture, n, m);
    // tree
    for (int i = 0; i < 4; i++) {
        picture[6 + i][3] = tree_trunk[i];
        picture[6 + i][4] = tree_trunk[i];
        picture[10][2 + i] = tree_trunk[i];

        picture[3][2 + i] = tree_foliage[i];
        picture[4][2 + i] = tree_foliage[i];
        picture[2 + i][3] = tree_foliage[i];
        picture[2 + i][4] = tree_foliage[i];
    }

    // sun
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            picture[i + 1][m - 6 + j] = sun_data[i][j];
        }
    }

    // boards
    for (int i = 0; i < m; i++) {
        picture[0][i] = frame_w[i];      // top
        picture[n - 1][i] = frame_w[i];  // bottom
        picture[7][i] = frame_w[i];      // middle
    }
    for (int i = 0; i < n; i++) {
        picture[i][0] = frame_h[i];      // left
        picture[i][m - 1] = frame_h[i];  // right
        picture[i][6] = frame_h[i];      // middle
    }
}

void reset_picture(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            picture[i][j] = 0;
        }
    }
}

void transform(int *buf, int **matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        matr[i] = buf + i * m;
    }
}

void print_picture(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", picture[i][j]);
        }
        if (i != n - 1) {
            printf("\n");
        }
    }
}