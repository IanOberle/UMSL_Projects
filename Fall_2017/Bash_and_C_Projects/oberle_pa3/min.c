//Ian Oberle
//cs2750 PA 3
//date 10/20/17

float min ( float a[], int N)
{
    int i;    
    float minVal = a[0];
    for ( i = 0; i < N; i++)
    {
	if ( a[i] < minVal)
	 minVal = a[i];
    }
    return minVal;
}
