#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void swap(vector <int> &arr, int i, int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int partition(vector <int> &arr, int l, int r)
{
    int pivot=arr[r];
    int i=l-1;

    for(int j=l; j<r; j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i+1, r);
    return i+1;
}

void quickSort(vector <int> &arr, int l, int r)
{
    if(l<r)
    {
        int pi=partition(arr, l, r);
        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);

    }
}

int main()
{
    vector <int> arr;
    int len;
    cout<<"enter the count of the array yu will be entering\n";
    cin>>len;
    cout<<"Enter the values to be sorted=\n";
    for(int i=0; i<len; i++)
    {
        int num;
        cin>>num;
        arr.push_back(num);
    }
    
    
    char choice;
    cout<<"Press A for sorting in ascending or D for descending sort\n";
    cin>>choice;
    while(choice!='A' && choice!='D')
    {
        cout<<"PLease enter proper choice=\n";
        cin>>choice;
    }
    quickSort(arr, 0, arr.size()-1);
    if(choice=='A')
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    else
    {
        for(int i=arr.size()-1; i>=0; i--)
    {
        cout<<arr[i]<<" ";
    }
    }
    cout<<endl;
    return 0;
}
