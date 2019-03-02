//Ian Oberle
//cs2750 PA 3
//date 10/20/17

float max ( float a[], int N)
{
	float maxVal = a[0]; 
	int i;
	for ( i = 0; i < N; i++)
	{
		if ( a[i] > maxVal)
			 maxVal= a[i];
	}
	return maxVal;	
}
