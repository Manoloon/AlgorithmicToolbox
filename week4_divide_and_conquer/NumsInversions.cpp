#include <iostream>
#include <vector>

using std::vector;

int mergeAndCount(vector<int>& a,vector<int>& tmp, int left, int mid, int right){
	int iLeft = left;// Starting index for left subarray
	int iRight = mid + 1;// Starting index for right subarray
	int iUnsort = left;// Starting index to be sorted
	
	int result = 0;
	
	// Merge the two halves while counting inversions
	while(iLeft <= mid && iRight <= right){
		if(a[iLeft] <= a[iRight])
			tmp[iUnsort++] = a[iLeft++];
		else{
			tmp[iUnsort++] = a[iRight++];
			result += (mid + 1 - iLeft);
		}
			
	}
	// Copy the remaining elements of left subarray, if any
	while(iLeft <= mid){
		tmp[iLeft++] = a[iLeft++];
	}
	// Copy the remaining elements of right subarray, if any
	while(iRight <= right){
		tmp[iUnsort++] = a[iRight++];
	}
	// Copy the sorted subarray into Original array
	for(int i = left ; i <= right; i++){
		a[i] = tmp[i];
	}
	
	return result;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {

  long long number_of_inversions = 0;
  if (right <= left) return number_of_inversions;
  size_t ave = left + (right - left) / 2;  
  
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave + 1, right);
  number_of_inversions += mergeAndCount(a,b,left,ave,right);
  
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
