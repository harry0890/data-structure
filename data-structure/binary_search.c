#include <stdio.h>

// recursive
// time = O(log(n))
int binary_search_1(int arr[], int l, int r, int key)
{
	if(r >= l) {
		int mid = l + (r - l)/2;
		if(arr[mid] == key) return mid;
		if(arr[mid] > key)  return binary_search_1(arr, l, mid - 1, key); 
		return binary_search_1(arr, mid + 1, r, key);
	}
	return -1;
}

// iteration
int binary_search_2(int arr[], int l, int r, int key)
{
	while(r >= l) {
		int mid = l + (r - l)/2;
		if(arr[mid] == key) return mid;
		if(arr[mid] > key)  r = mid - 1;
		else l = mid + 1;	
	}
	return -1;
}


int main(void)
{
	int ans;
	int a[6] = {1, 3, 7, 12, 15, 18};
	int size = sizeof(a) / sizeof(a[0]);
	ans = binary_search_2(a, 0, size - 1, 15);
	printf("%d\n",ans);
	return 0;
}
