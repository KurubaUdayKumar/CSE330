#include<iostream>
using namespace std;

int main()
{
	bool arr[50];
	bool flag;
	for(int i=0;i<50;i++)
		arr[i] = true;	
	cout << "\n Prime Numbers from 1 to 100 are : \n";
	for(int i=2;i<50;i++)
	{
		for(int j=i*i;j<50;j+=i)
		{
			arr[j-1] = false;
		}
	}
	
	for(int i=2;i<50;i++)
	{
		if(arr[i-1] == true)
			cout<< i << "  ";
	}
	
	cout<<"\n";
	return 0;
}
