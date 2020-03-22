#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> removeDuplicates(int* arr , int n){

	vector<int> v;
	unordered_map<int, bool> maps;

	for(int i = 0 ; i < n ; i++){
		
		if(maps.count(arr[i]) > 0){
			continue;
		}
		maps[arr[i]] = true;
		v.push_back(a[i]);
	}

	return v;
}

int main()
{
	int arr[] = {1,2,3,2,3,1,4,5,6,3};
	int size = sizeof(arr)/sizeof(arr[0]);

	vector<int> v = removeDuplicates(arr , size);

	for(int i = 0  ; i < v.size() ; i ++){
		cout << v[i] << " ";
	}

	return 0;
}