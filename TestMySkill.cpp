#include<iostream>
#include<climits>
using namespace std;



void merge(int arr[],int l,int mid,int h){
	cout << "Value of l = " << l << " value of r = " << h << endl;
	//left-subarray range
	int lft = mid - l + 1;
	//right-subarray range
	int rt = h - mid;

	//left subarray
	int L[lft + 1];
	int R[rt + 1];

	L[lft] = INT_MAX;
	R[rt] = INT_MAX;
	//copying the content of left-subarray to our L-array and ..
	
	for(int i = 0;i<lft;i++){
		L[i] = arr[l + i];
	}
	for(int j = 0;j<rt;j++){
		R[j] = arr[mid + j + 1];
	}

	//compairing left-subarray and right-subarray
	int i = 0,j = 0,k = l;
	while(i<lft && j < rt){
		if(R[j] <= L[i]){
			arr[k] = R[j];
			j++;         
		}else{
			arr[k] = L[i];
			i++;
		}
		k++;
	}

	//check any left element in L_subarray
	while(i<lft){
		arr[k] = L[i];
		i++;k++;
	}
	while(j < rt){

		arr[k] = R[j];
		j++;
		k++;
	}
}
void merge_sort(int arr[],int l,int h){
	if(l<h){

		int mid = l + (h-l) / 2;
		merge_sort(arr,l,mid);
		merge_sort(arr,mid+1,h);
		cout << "Called merge with = " << l << " : " << mid << " : " << h <<endl;
		merge(arr,l,mid,h);
	}

}
int main(){
	int arr[] = {9,-1,4,10,21,7,3,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Size of arr = " << n << endl;
	merge_sort(arr,0,n-1);
	cout << "Printing the array:\n";
	for(int i= 0;i<n;i++){
		cout << arr[i] << " ";
	}
}
