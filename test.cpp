#include<iostream>
using namespace std;

int binearysearch(int arr[], int n, int target)
{
    int low=0;
    int high=n-1;
    while (low<high)
    {
        int middle= (low+high)/2;
        if(target==arr[middle])
        {
            return middle; 
        }
        
        else if(target>arr[middle]) 
        {
            low=middle+1;
        }
        else{
            high=middle-1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cout<<"Enter "<<i<<"th element: "<<endl;
        cin>>arr[i];
    }

    int target;
    cout<<"Enter target : "<<endl;
    cin>>target;

    
    int ans=binearysearch(arr, n, target);
    cout<<"Ans is :"<<ans;
    return 0;
}