#include <iostream> 
#include <stdlib.h>
#include <time.h> 
 
using namespace std; 
	  const int length = 100000;
      const int length_1k = 1000;
      const int length_1 = 100;
      
	  int array[length];
	  int array_1k[length_1k];
	  int array_1[length_1];

 void BubbleSort (int array[], unsigned int length,long int &steps)
 {
       int hold;
       steps=0;
     for(int i=0; i<length; i++)
 { 
   for(int j=0; j<length; j++)
   {
     if(array[j]>array[j+1])
     {
     	steps++;
      hold=array[j];
      array[j]=array[j+1];
      array[j+1]=hold;        
     }
   }         
 }    
}

 void merge( int a[ ], int tmp_array[ ],  int l_pos, int r_pos, int right_end , long int  &steps ) 
{ 
	int i, left_end, num_elements, tmp_pos; 
	left_end = r_pos - 1; 
	tmp_pos = l_pos; 
	num_elements = right_end - l_pos + 1; 
	
/* main loop */ 
	
	while( ( l_pos <= left_end ) && ( r_pos <= right_end ) ) 
		if( a[l_pos] <= a[r_pos] ) 
	      {
	      tmp_array[tmp_pos++] = a[l_pos++]; 
	      steps++;
	  	 }
		else 
	     {
	       tmp_array[tmp_pos++] = a[r_pos++]; 
	       steps++;
	   	 }

	while( l_pos <= left_end ) 
	{
	
	tmp_array[tmp_pos++] = a[l_pos++]; 
	steps++;
	}
	while( r_pos <= right_end )
	{
	tmp_array[tmp_pos++] = a[r_pos++]; 
	steps++;
	}
for (i=1; i <= num_elements; i++, right_end-- ) 
	{
	a[right_end] = tmp_array[right_end]; 
	steps++;
	}
}
  
void m_sort( int a[], int tmp_array[ ], int left, int right, long int &steps ) 
	{ 
		int center; 
		
		if( left < right ) 
	{ 
		center = (left + right) / 2; 
		m_sort( a, tmp_array, left, center,steps ); 
		m_sort( a, tmp_array, center+1, right,steps ); 
		merge( a, tmp_array, left, center+1, right,steps ); 
	} 
	}
 
void mergesort( int a[], unsigned int n, long int  &steps ) 
	{ 
			int *tmp_array; 
			tmp_array = (int *) malloc ( (n+1) * sizeof (int) ); 
				
				if( tmp_array != NULL ) 
   				 { 
   					 m_sort( a, tmp_array, 0, n-1 , steps); 
    				 free( tmp_array ); 
    			 } 
				
			   else
   			
			     cout<<"No space for tmp array!!!"; 
	}

void merging(int array[], int n,long int & steps)
{
	clock_t start = clock();
	steps=0;
	float x;
	mergesort(array ,n,steps);
	
	clock_t ends = clock(); 
	x=steps/n;
 cout << "Running Time For \"Merge Sort\" : " 
 << (double) (ends - start) / CLOCKS_PER_SEC << endl;
 cout<<"Number of Operations : "<<steps<<endl;
 cout<<"Operations / Number of Elements : "<<x<<endl<<endl;
	
}

void Bubble(int array[], int n, long int & steps)
{
	clock_t start = clock();
	double x;
	BubbleSort(array,n,steps);
	
	clock_t ends = clock(); 
	x=(steps/n);
 cout << "Running Time for \"Bubble Sort\" : " 
 << (double) (ends - start) / CLOCKS_PER_SEC << endl;
 cout<<"Number of Swaps : "<<steps<<endl;
 cout<<"Operation / Number of Elements : "<<x<<endl<<endl;
	
}

void insertion_sort(int arr[], int length,long int & steps)
{
		int j, temp;
		
		
		
	for (int i = 1; i < length; i++)
	{
		j = i;
		
		while (j > 0 && arr[j] < arr[j-1])
		{
			
			  temp = arr[j];
			  arr[j] = arr[j-1];
			  arr[j-1] = temp;
			  j--;
			  steps++;
			  
			  
		}
	} 
}

void Insertion(int array[], int n, long int & steps)
{
	int x=0;
	steps=0;
	clock_t start = clock();
	
	insertion_sort(array,n,steps);
	
	clock_t ends = clock(); 

	x=steps/n;
 cout << "Running Time for \"Insertion Sort\" : " 
 << (double) (ends - start) / CLOCKS_PER_SEC << endl;
 cout<<"Number of Swaps : "<<steps<<endl;
 cout<<" Operations / Number of Elements : "<<x<<endl<<endl;
	
}

inline void Swap(int & item1, int & item2)
{
  int tempItem;

  tempItem = item1;
  item1 = item2;
  item2 = tempItem;
}

int MinIndex(int values[], int startIndex, int endIndex, long int &steps)
{
  int indexOfMin = startIndex;
  for (int index = startIndex + 1; index <= endIndex; index++)
  
    if (values[index] < values[indexOfMin])
    {
      steps++;
      indexOfMin = index;
  	}
  
  return indexOfMin;
}

void Selection_Sort(int values[], int numValues, long int &steps)
{
  int endIndex = numValues-1;
  for (int current = 0; current < endIndex; current++)
  {
  	steps++;
    Swap(values[current], values[MinIndex(values, current, endIndex,steps)]);
  }
}

void Selection(int array[], int n,long int & steps)
{
	int x=0;
	steps=0;
	clock_t start = clock();
	
	Selection_Sort(array,n,steps);
	
	clock_t ends = clock(); 
	x=steps/n;
 cout << "Running Time for \"Selection Sort\" : " 
 << (double) (ends - start) / CLOCKS_PER_SEC << endl;
 cout<<"Number of swaps : "<<steps<<endl;
 cout<<"operation / number of elements : "<<x<<endl;
	
}


void Randomize()
{
	  srand (time(NULL));
      for(int i=0; i<length; i++)
      {
       array[i] = rand();
      }  
      
      
      for(int i=0; i<length_1k; i++)
      {
       array_1k[i] = rand() % 1000;
      }  
      
      for(int i=0; i<length_1; i++)
      {
       array_1[i] = rand() % 1000;
      }  	
}


int main() 


{


 
 	  long int steps=0;
 	  Randomize();
      
		cout<<"*************************************"<<endl;      
		cout<<endl<<"Results with \"100\" Elements"<<endl<<endl;
	 	Bubble(array_1 , 100,steps);    Randomize();
 	    merging(array_1,100,steps);     Randomize();
 	    Insertion(array_1,100,steps);   Randomize();
		Selection(array_1,100,steps);   
	
	 	cout<<"*************************************"<<endl<<endl<<endl;
      
      	cout<<"*************************************"<<endl;
      	cout<<endl<<"Results with \"1000\" Elements"<<endl<<endl;
 	  	Bubble(array_1k , 1000,steps);     Randomize();
 	  	merging(array_1k,1000,steps);      Randomize();
 	  	Insertion(array_1k,1000,steps);	   Randomize();
 	  	Selection(array_1k,1000,steps);    
      	cout<<"*************************************"<<endl<<endl<<endl;

	    cout<<"*************************************"<<endl;
		cout<<endl<<"Results with 100,000 Elements"<<endl<<endl;
  	//  Bubble(array , 100000);
 	  	merging(array,100000,steps);       Randomize();
 	  	Insertion(array,100000,steps);     Randomize();
 	  	Selection(array,100000,steps);     
        cout<<"*************************************"<<endl;
    
 	  
 	  
 	
 return 0; 
} 
