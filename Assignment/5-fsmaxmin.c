#include<stdio.h>

int main()
{
    int a[30], n, i, fmax, smax, temp, fmin, smin;
    printf("Enter the no. of elements in the array : ");
    scanf("\n%d", &n);
    printf("\nEnter %d elements of the array\n", n);

    for(i=0; i<n; i++)
        scanf("%d",&a[i]);

    fmax=a[0];          //assume that first maximum is the first element of the array
    smax=a[1];          //and second maximum is the second element of the array

    if(smax > fmax)     //compare fmax and smax and swap the values
    {
        temp=smax;
        smax=fmax;
        fmax=temp;
    }

    for(i=2; i<n; i++)
        if(a[i]>fmax)
            {
                smax=fmax;
                fmax=a[i];
            }
    else if(a[i]>smax && a[i]!=fmax)
    smax=a[i];
    printf("\nFirst and second maximum element in array is %d , %d respectively\t", fmax, smax);


// for first minimum and second minimum

    fmin=a[0];
    smin=a[1];

    if(smin<fmin)       //compare fmin and smin and swap the values
    {
        temp=smin;
        smin=fmin;
        fmin=temp;
    }

    for(i=2; i<n; i++)
    if(a[i]<fmin)
    {
        smin=fmin;
        fmin=a[i];
    }
    else if(a[i]<smin && a[i]!=fmin)
        smin=a[i];
        printf("\nFirst and second minimum element in array is %d , %d respectively\t", fmin, smin);

    return 0;
}
