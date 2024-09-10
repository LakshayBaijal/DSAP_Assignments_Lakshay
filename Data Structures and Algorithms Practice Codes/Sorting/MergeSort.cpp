
void merge(vector <int> &arr, int low, int mid, int high)
{
    vector <int> a;
    int left = low;
    int right = mid + 1;
    while(left <= mid && right <= high )
    {
        if(arr[left]<=arr[right])
        {
            a.push_back(arr[left]);
            left++;
        }
        else if(arr[left]>arr[right])
        {
            a.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid)
    {
        a.push_back(arr[left]);
        left++;
    }

    while(right<=high)
    {
        a.push_back(arr[right]);
        right++;
    }

    for(int i = low; i<=high; i++)
    {
        arr[i] = a[i-low];
    }
}


void mergesortfunction(vector <int> &arr,int low,int high)
{
    if(low == high)
    {
        return;
    }

    int mid = ( high + low ) / 2;

    mergesortfunction(arr,low,mid);
    mergesortfunction(arr,mid+1,high);

    merge(arr,low,mid,high);


}




void mergeSort(vector < int > & arr, int n) {
    // Write your code here.
    mergesortfunction(arr,0,n-1);
}
