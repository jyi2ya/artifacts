
#include <iostream>
#include <algorithm>

using namespace std;

void InsSort(int *arr, int n, int x)
{
	arr[n++] = x;
	sort(arr, arr + n);
}

int main()

{

    int data[11]={12,34,56,78,90,167,258,389,945,1890};

    int num, i ;

    cin>>num;

    InsSort(data,10,num);

      for(i=0;i<11;i++)

        cout<<data[i]<<" ";

    cout<<endl;

    return 0;

}


