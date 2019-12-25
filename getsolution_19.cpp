#include "getsolution_19.h"

Gaussian::Gaussian()
{

}
string Gaussian::solve(string s_in)
{
    qDebug()<<"getsolution_19";

    vector<double> vec = stringtoVectordouble(s_in);
    int N  = vec[0];
    int index = 1;
    double mat [N][N+1];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            mat[i][j] = vec[index];
            index = index + 1;
        }
    for(int i=0;i<N;i++)
    {
        mat[i][N] = vec[index];
        index = index + 1;
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N+1;j++)
        {
            qDebug() << mat[i][j];
        }
    double* mat_real[N];
    for(int i=0;i<N;i++)
    {
        mat_real[i] = mat[i];
    }

    return gaussianElimination(mat_real,N);

}
string Gaussian::gaussianElimination(double** mat,int N)
{
    /* reduction into r.e.f. */
    int singular_flag = forwardElim(mat,N);

    /* get solution to system and print it using
       backward substitution */
    string s_result = backSub(mat,N);
    return s_result;
}
void Gaussian::swap_row(double** mat, int i, int j,int N)
{
    //printf("Swapped rows %d and %d\n", i, j);

    for (int k=0; k<=N; k++)
    {
        double temp = mat[i][k];
        mat[i][k] = mat[j][k];
        mat[j][k] = temp;
    }
}
int Gaussian::forwardElim(double** mat, int N)
{
    for (int k=0; k<N; k++)
    {
        // Initialize maximum value and index for pivot
        int i_max = k;
        int v_max = mat[i_max][k];

        /* find greater amplitude for pivot if any */
        for (int i = k+1; i < N; i++)
            if (abs(mat[i][k]) > v_max)
                v_max = mat[i][k], i_max = i;

        /* if a prinicipal diagonal element  is zero,
         * it denotes that matrix is singular, and
         * will lead to a division-by-zero later. */
        if (!mat[k][i_max])
            return k; // Matrix is singular

        /* Swap the greatest value row with current row */
        if (i_max != k)
            swap_row(mat, k, i_max,N);


        for (int i=k+1; i<N; i++)
        {
            /* factor f to set current row kth element to 0,
             * and subsequently remaining kth column to 0 */
            double f = mat[i][k]/mat[k][k];

            /* subtract fth multiple of corresponding kth
               row element*/
            for (int j=k+1; j<=N; j++)
                mat[i][j] -= mat[k][j]*f;

            /* filling lower triangular matrix with zeros*/
            mat[i][k] = 0;
        }

        //print(mat);        //for matrix state
    }
    //print(mat);            //for matrix state
    return -1;
}

// function to calculate the values of the unknowns
string Gaussian::backSub(double** mat,int N)
{
    double x[N];  // An array to store solution

    /* Start calculating from last equation up to the
       first */
    for (int i = N-1; i >= 0; i--)
    {
        /* start with the RHS of the equation */
        x[i] = mat[i][N];

        /* Initialize j to i+1 since matrix is upper
           triangular*/
        for (int j=i+1; j<N; j++)
        {
            /* subtract all the lhs values
             * except the coefficient of the variable
             * whose value is being calculated */
            x[i] -= mat[i][j]*x[j];
        }

        /* divide the RHS by the coefficient of the
           unknown being calculated */
        x[i] = x[i]/mat[i][i];
    }

    //printf("\nSolution for the system:\n");
    stringstream ss;
    for (int i=0; i<N; i++)
        ss << fixed<< setprecision(2) << x[i] <<" ";

    return (ss.str()).substr(0,(ss.str()).length()-1);

}

