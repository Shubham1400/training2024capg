#include <stdio.h>
#define SIZE(a)(sizeof(a)/sizeof(a[0]))	// macro which calculates size of array

void sorting (int *a)				//applying bubble sort
{
  for (int i = 0; i < SIZE (a); i++)
	{
	  for (int j = i + 1; j < 5; j++)
		{
		  if (a[i] >= a[j])
			{
			  int t = a[i];
			  a[i] = a[j];
			  a[j] = t;
			}
		}
	}
}

int search (int *a, int n)			//applying linear search
{
  for (int i = 0; i < SIZE (a); i++)
	{
	  if (n == a[i])
		return i;
	}
  return SIZE (a);
}

int main ()
{
  int a[] = { 1, 44, 33, 2, 78 };
  sorting (a);

  printf ("sorted array- ");

  for (int i = 0; i < SIZE (a); i++)
	{
	  printf ("%d ", a[i]);
	}

  printf ("\nenter number to be searched- ");
  int n;
  scanf ("%d", &n);
  int ans = search (a, n);
  if (ans < SIZE (a))
	printf ("found at position %d", ans + 1);
  else
	printf ("not found");
  return 0;
}
