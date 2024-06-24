// 10. Write a program to merge two sorted arrays into a single sorted array.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void combine (int *a, int *a2, int l, int l2)
{
  int c[l + l2], count1 = 0, count2 = 0, i = 0;

  for (; count2 != l2; i++)
	{
	  if (a[count1] > a2[count2])
		{
		  c[i] = a2[count2++];
		}
	  else
		{
		  c[i] = a[count1++];
		}
	}

  for (; count1 != l; i++)
	c[i] = a[count1++];

  for (int i = 0; i < l + l2; i++)
	printf ("%d ", c[i]);
}

int main ()
{
  int a[] = { 1, 3, 7, 8, 18 };
  int b[] = { 2, 5, 12, 15, 20, 23, 25 };
  int l = sizeof (a) / sizeof (int);
  int l2 = sizeof (b) / sizeof (int);
  l >= l2 ? combine (a, b, l, l2) : combine (b, a, l2, l);

  return EXIT_SUCCESS;
}

