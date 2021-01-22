#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(int nums[],int n)
{
    int x = 1;

    for(int i=1; i<n; i++)
    {
        if(nums[i]!=nums[i-1])
            nums[x++] = nums[i];
    }

    return x;
}
int main()
{
    int n;

    printf("Enter number of elements (zero to exit):");
    while(scanf("%d",&n)==1&&n!=0)
    {

        int nums[n];
        printf("The elements are :");
        for(int i=0; i<n; i++)
        {
            scanf("%d",&nums[i]);
        }

        int len = removeDuplicates(nums,n);

        printf("new length = %d\n",len);

        for(int i=0; i<len; i++)
        {
            printf("%d ",nums[i]);
        }
        printf("\n\nEnter number of elements (zero to exit):");
    }

    return 0;
}
