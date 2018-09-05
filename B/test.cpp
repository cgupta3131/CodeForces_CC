#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
  int temp=*a;
  *a=*b;
  *b=temp;
}


int partition(int input[],int si,int ei)
{
  int pivot = input[si];
  int count =0;
  for(int i=si;i<=ei;i++)
    if(pivot > input[i])
      count++;

  swap(input+si,input+si+count);

  int index = si+ count;
  int i =si,j = ei;

  while(i<j)
	{
		while(input[i] <= pivot && i<ei)
			i++;

		while(input[j] > pivot && j>si)
			j--;

		if(i<j)
			swap(input+i,input+j);
	}
/*
	while(i<index && j>index)
	{
	    int a1=0,a2=0;

	    if(input[i] < pivot)
	      i++;
	    else
	      a1++;
	    if(input[j] > pivot)
	      j--;
	    else
	      a2++;
	    if(a1 ==1 && a2==1)
	      swap(input+i,input+j);

  	}  
  */


  return j;


}
void quickSort1(int input[], int si,int ei)
{
  if(si<ei)
  {
    //int mid = (si + ei)/2;
    int c = partition(input,si,ei);
    quickSort1(input,si,c-1);
    quickSort1(input,c+1,ei);
  }

}

void quickSort(int input[], int size)
{
  quickSort1(input,0,size-1);
}

int main()
{
	int a[] = {6,5,4,3,7,7,6,2,1};
	int n1 = sizeof(a)/sizeof(a[0]);
	
	//partition(a,0,n1-1);
	for(int i=0;i<n1;i++)
 		cout << a[i] << " ";

 	cout << endl;
 	
 	
	quickSort(a,n1);


	for(int i=0;i<n1;i++)
 		cout << a[i] << " ";
 	cout << endl;
      
}