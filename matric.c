#include <stdio.h>
#include<stdlib.h>
int** creatematrix(int r,int c){
    int** mat=(int**)malloc(r*sizeof(int*));
    for(int i=0;i<r;i++){
        mat[i]=(int*)malloc(c*sizeof(int));
    }
    return mat;
}
void input(int** mat, int r, int c) {
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}
void display(int** mat,int r, int c){
    for(int i= 0; i < r; i++){
        for ( int j =0; j< c;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}
void freed(int** mat, int r){
    for(int i=0;i<r;i++){
        free(mat[i]);
    }
    free(mat);
}
int main(){
    int r1,r2,c1,c2;
    printf("enter row and column for matrix one:");
    scanf("%d %d",&r1,&c1);
    printf("enter row and column for matrix two:");
    scanf("%d %d",&r2,&c2);
    int** mat1 =creatematrix(r1,c1);
    int** mat2 = creatematrix(r2,c2);
    input(mat1,r1,c1);
    input(mat2,r2,c2);
    display(mat1,r1,c1);
    display(mat2,r2,c2);
    freed(mat1,r1);
    freed(mat2,r2);
}