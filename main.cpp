#include <iostream>
#include <vector>
#include <QTime>
#include <algorithm>
#include <cstdlib>
#include <time.h>

using namespace std;
void fillarr(vector <int> &arr, int n);
void showarr(vector <int> &arr, int n);
void bubblesort(vector <int> &arr, int n);
void shakesort(vector <int> &arr, int n, int start);
void Swap (vector <int> &arr, int i);

int main()
{   int n;
    srand(time(NULL));
    cout<<"input n:";
    cin>>n;
    vector <int> arr;
    vector <int> arrtmp;
    arrtmp.reserve(n+1);
    fillarr(arr,n);

    //cout<<"Array:"<<endl;
    //showarr(arr,n);

    copy(arr.begin(),arr.end(),arrtmp.begin());
    QTime time;

    /////////////bubble sort

    time.start();
    bubblesort(arrtmp,n);
    cout<<time.elapsed()<<"ms---bubble sort"<<endl;
    //showarr(arrtmp,n);
    copy(arr.begin(),arr.end(),arrtmp.begin());

    ///////////func shake

    time.start();
    sort_shake(arrtmp,n,1);
    cout<<time.elapsed()<<"ms---func shake"<<endl;
    //showarr(arrtmp,n);
    copy(arr.begin(),arr.end(),arrtmp.begin());

    ////////////func sort

    time.start();
    sort(arrtmp.begin(),arrtmp.begin()+n);
    cout<<time.elapsed()<<"ms---func sort"<<endl;
    //showarr(arrtmp,n);

    return 0;
}
void fillarr(vector <int> &arr, int n)
{
    for(int i=0;i<n;i++)
        arr.push_back(rand()%10);
}
void showarr(vector<int> &arr, int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<' ';
    cout<<endl;
}
void bubblesort(vector <int> &arr, int n)
{
    for(int i=0;i<n-1;i++)
        for (int j=0;j<n-1;j++)
            if (arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
}
void Swap(vector <int> &arr, int i)
{
    int temp;
    temp=arr[i];
    arr[i]=arr[i-1];
    arr[i-1]=temp;
}

void shakesort(vector <int> &arr, int n, int start)
{
    int left,right, i;
    left=start;
    right=n-1;
    while (left<=right)
    {
        for(i=right;i>=left;i--)
            if(arr[i-1]>arr[i]) Swap(arr,i);
        left++;
        for(i=left;i<=right;i++)
            if(arr[i-1]>arr[i]) Swap(arr,i);
        right--;

    }
}
