int c[MAX][MAX];
for (int i=0; i<m1; i++){
        for (int j=0; j<n2; j++){
                C[i][j]=0;
                for(int k=0;k<n1;k++){
                        C[i][j]+=A[i][k]*B[k][j];
                }
        }
}
