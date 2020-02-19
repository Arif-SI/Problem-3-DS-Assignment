#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

int cnt = 0 ;
int B[100][100];

// function for checking highest and lowest limit.
bool isSafe(int N,int M,int i,int j)
{
    if(i < 0 || i >= N)
        return false;
    if(j < 0 || j >= M)
        return false;
    return true;
}

//
void checkOrganism(char **A,int N,int M,int i,int j)
{
    if(isSafe(N,M,i,j) && A[i][j] == '*')
    {

        A[i][j] = 0;
        B[i][j] = cnt;
        checkOrganism(A, N, M, i-1, j);
        checkOrganism(A, N, M, i, j-1);
        checkOrganism(A, N, M, i, j+1);
        checkOrganism(A, N, M, i+1, j);
    }
}

//this function finds the total number of organisms
int TotalOrganisms(char **A, int N, int M)
{
    for(int x=0;x<N;x++){
        for(int y=0;y<M;y++)
        {
            B[x][y] = 0;
        }
    }
    //int cnt = 0 ;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
            if(A[i][j] == '*')
            {
                cnt++;
                checkOrganism(A,N,M,i,j);
            }
    }

    if(cnt == 0)
        return 0;
    return cnt;
}

int main()
{
    int N,M;
    //freopen("input.txt", "r", stdin);
    cout << "\nEnter the order of the organisms :" ;
    cin >> N >> M;

    char **A = (char **)malloc(N * sizeof(char *));
    for (int i = 0; i < N; i++){
        A[i] = (char *)malloc(M * sizeof(char));
    }
    cout << "\nEnter the organism matrix : \n";
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < M; j++){
            cin >> A[i][j];
        }
    }

    cout << "Total Number of organisms : " << TotalOrganisms(A,N,M)<<endl;
     for(int i = 0; i < N ; i++){
        for(int j = 0; j < M; j++){
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }
    /*for(int z=0;z<5;z++){
        printf("%d\n",rand()%2);
    }*/
    return 0;
}
