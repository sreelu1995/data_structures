#include<iostream>
using namespace std;

void mergesort(int*,int*,int ,int );
void merge(int*,int*,int ,int );

main()
{
    int n;
    cout<<"enter the array size:";
    cin>>n;
    cout<<"enter the array to be sorted:";
    int ar[n],temp[n];

    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }

    int f,l;
    f=0;
    l=n-1;

     mergesort(ar,temp,f,l);

    cout<<"\n the sorted array is:";
    for(int i=0;i<n;i++)
    {
        cout<<"\t"<<ar[i]<<"\t";
    }



 return 0;

 }

void mergesort(int *ar,int *temp,int f,int l)
    {
        while(f<l)
    {
        int mid=(f+l)/2;

        if(l!=(f+1))
        {
          mergesort(ar,temp,f,mid);
          mergesort(ar,temp,mid+1,l);
          merge(ar,temp,f,l);

        }

     

        }


   }

   void merge(int *ar,int *temp,int f,int l)
   {
       int mid=(f+l)/2;

       int i1=0;

       for(int i2=f,i3=mid+1;i2<=mid,i3<=l;i1++,i2++,i3++)
       {
           if(ar[i2]<ar[i3])
               temp[i1]=ar[i2];
           else
               temp[i1]=ar[i3];
       }

        for(int i=0;i<l;i++)
        {
            ar[i]=temp[i];
        }



       }
