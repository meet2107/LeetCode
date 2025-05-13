class Solution {
public:
    int ans = 0 ;
    void mergeSort(vector<int>& arr, int s, int mid, int e){
        
        vector<int> temp(e-s+1);
        int i=s, j=mid+1;
        int k=0;
        while(i<=mid && j<=e){
            if(arr[i] > arr[j]){
                temp[k] = arr[j++];
            }
            else{
                temp[k] = arr[i++];
            }
            k++;
        }
        
        while(i<=mid) temp[k++] = arr[i++];
        while(j<=e) temp[k++] = arr[j++];
        
        for(int i=s; i<=e; i++){
            arr[i] = temp[i-s];
            // cout<<arr[i]<<" ";
        }
        // cout<<endl;
    }
    // Function to count inversions in the array.

    void countPairs(vector<int>& arr, int s, int mid, int e){
        int right = mid+1;
        for(int i=s; i<=mid; i++){
            while(right<=e && arr[i]>(long long)2*arr[right]) right++;
            ans += (right-(mid+1));
        }
    }
    void merge(vector<int>& arr, int s, int e){
        if(s<e){
            int mid = s+((e-s)/2);
            merge(arr, s, mid);
            merge(arr, mid+1, e);
            countPairs(arr, s, mid, e);
            mergeSort(arr, s, mid, e);
        }
    }
    int reversePairs(vector<int>& arr) {
        // Your Code Here
        ans = 0;
        int n = arr.size()-1;
        merge(arr, 0, n);
        // for(int i=0; i<n; i++) cout<<arr[i]<<" ";
        return ans;
        
    }
};
