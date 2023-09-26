#include <stdio.h>
#include <string.h>

int main(void)
{
  int n = 5;
  int i, j;
  int p = 0;
  int x0, x1, x2, x3;
  int y0, y1, y2, y3;
  int count = 1;
  printf("input :");
  scanf("%d", &n);

  int arr[n][n];
  y0 = 0;
  y1 = n-1;
  x2 = n-1;
  x3 = n-1;
  y3 = 0;

  memset(arr, 0, sizeof(arr));
  for (i = 0; i < n*n; i++)
  {
    if (p%4 == 0)
    {
      arr[p/4][y0] = count++;
      y0++;
      if (y0 == n - p/4)
      {
	y0 = p/4 + 1;
	x1 = y0;
	p++;
      }
    }
    else if (p%4 == 1)
    {
      arr[x1][y1] = count++;
      x1++;
      if (x1 == n -p/4)
      {
	y1--;
	y2 = y1;
	p++;
      }
    }
    else if (p%4 == 2)
    {
      arr[x2][y2] = count++;
      y2--;
      if (y2 == p/4 - 1)
      {
	x2--;
	x3 = x2;
	p++;
      }
    }
    else if (p%4 == 3)
    {
      arr[x3][y3] = count++;
      x3--;
      if (x3 == p/4)
      {
	y3++;
	p++;
      }
    }
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      printf("%2d ",arr[i][j]);
    }
    printf("\n");
  }

  return 0;
}

