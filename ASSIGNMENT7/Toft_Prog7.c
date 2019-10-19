#include <stdio.h>
#include <iostream>

using namespace std;

//prototype
int LRU(int count[], int);

int main()
{
  int num_Pages, num_Frames;
  int frames[10], pages[20], time[10];
  int count = 0;
  int faults = 0;
  int flag, flag2 = 0;

//prompt
  cout << "Number of virtual pages: ";
  scanf("%d", &num_Pages);

  cout << "Number of page frames available: ";
  scanf("%d", &num_Frames);

  cout << "Reference string: ";
  for(int i = 0; i < num_Pages; i++)
    scanf("%d", &pages[i]);

//create table
  for(int i = 0; i < num_Frames; i++)
    frames[i] = -1;

  for(int i = 0; i < num_Pages; i++)
  {
    for(int i = 0; i < num_Pages; i++)
    {
      flag = 0;
      flag2 = 0;

      for(int j = 0; j < num_Frames; j++)
        if(frames[j] == pages[i])
        {
          count++;
          time[j] = count;
          flag = 1;
          flag2 = 1;
          break;
        }
    }

    if(flag == 0)
    {
      for(int j = 0; j < num_Frames; j++)
        if(frames[j] == -1)
        {
          count++;
          faults++;
          frames[j] = pages[i];
          time[j] = count;
          flag2 = 1;
          break;
        }
    }

    if(flag2 == 0)
    {
      int pos = LRU(time, num_Frames);
      count++;
      faults++;
      frames[pos] = pages[i];
      time[pos] = count;
    }

    cout << "\n";
    for(int j = 0; j < num_Frames; j++)
      cout << "\t" << frames[j];
  }
  cout << "\n\nTotal number of faults: " << faults;
  return 0;
}


int LRU(int a[], int n)
{
  int min = a[0];
  int p = 0;

  for(int i = 1; i < n; i++)
  {
    if(a[i] < min)
    {
      min = a[i];
      p = i;
    }
  }
  return p;
}
