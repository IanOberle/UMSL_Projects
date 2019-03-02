//Ian Oberle
//cs2750 PA 3
//date 10/20/17

float avg (float a[],  int N)
{
	int i;
	float sum = 0, average;
	for (i = 0; i < N; i++)
	{	
		sum += a[i];
	}
	average = (sum / N);
	return average;
}
