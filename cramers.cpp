#include <iostream>
#include <cmath>
using namespace std;
float determinanOfMatrix(float **arr, int n)
{
    int flag = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[j][0] != 0)
        {
            flag = 1;
        }
    }
    if (flag == 0)
    {
        return 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i][i] == 0)
        {
            for (int m = 0; m < n; m++)
            {
                arr[i][m] = arr[i][m] + arr[i + 1][m];
            }
        }
        int r = i + 1;
        float a;
        while (r < n)
        {
            a = (float)arr[r][i] / (float)arr[i][i];
            for (int k = 0; k < n; k++)
            {
                if (r != k)
                    arr[r][k] = (arr[r][k] - a * (arr[i][k]));
                else
                    arr[r][k] = arr[r][k] - a * (arr[i][k]);
            }
            r++;
        }
    }
    float a = 1;
    for (int i = 0; i < n; i++)
    {
        a = round(a * arr[i][i]);
    }
    return a;
}

void display(float **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int count;
    cin >> count;
    float **arr = new float *[count];
    for (int i = 0; i < count; i++)
        arr[i] = new float[count + 1];

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count + 1; j++)
        {
            cin >> arr[i][j];
        }
    }
    // display(arr,count);
    // float d = determinanOfMatrix(arr,count);
    // cout<<d<<endl;
    // display(arr,count);
    float d1[100];

    for (int i = 0; i < count; i++)
    {
        float **a1 = new float *[count];
        for (int i = 0; i < count; i++)
            a1[i] = new float[count];
        for (int m = 0; m < count; m++)
        {
            a1[m][i] = arr[m][count];
        }

        for (int j = 0; j < count; j++)
        {
            for (int k = 0; k < count; k++)
            {
                if (k != i)
                {
                    a1[j][k] = arr[j][k];
                }
            }
        }
        // cout<<endl;
        // display(a1,count);
        // cout<<endl;
        d1[i] = determinanOfMatrix(a1, count);
    }
    float d = determinanOfMatrix(arr, count);
    printf("D is : %.6f\n", d);
    printf("D1 is : %.6f\n", d1[0]);
    printf("D2 is : %.6f\n", d1[1]);
    printf("D3 is : %.6f\n", d1[2]);
    printf("Value of x is : %.6f\n", d1[0] / d);
    printf("Value of y is : %.6f\n", d1[1] / d);
    printf("Value of z is : %.6f\n", d1[2] / d);

    return 0;
}
