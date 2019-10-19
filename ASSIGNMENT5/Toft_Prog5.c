#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

struct Job
{
  int pid;
  int burst;
  int wait;
  int turnA;
};

//prototypes
void waitTime(Job job[], int);
void turnATime(Job job[], int);
void header();
void print(Job job);

int main()
{
  Job job[10];
  char buf[100];
  srand(time(0)); rand(); //random generator for bursts

  cout << "\nHow many processes(2 - 9)?: ";
  cin >> buf;
  int n = atoi(buf);

//assign pid and burst time for each job
  for(int i = 0; i < n; i++)
  {
    job[i].pid = i;
    job[i].burst = rand() % 43;
  }

//FCFS algorithm
//calculate wait time for each process
  job[0].wait = 0; //first process is always 0
  waitTime(job, n);

  //calculate turn around time for each process
  turnATime(job, n);

  //print results
  cout << "\nFCFS\n";
  header();
  for(int i = 0; i < n; i++)
    print(job[i]);

//SJF algorithm
//sort by burst time
  for(int i = 0; i < n; i++)
    for(int j = i + 1; j < n; j++)
      if(job[j].burst < job[i].burst)
        swap(job[i], job[j]);

  //calculate wait time for each process
  job[0].wait = 0;
  waitTime(job, n);

  //calculate turn around time for each process
  turnATime(job, n);

  //print results
  cout << "\n\nSJF\n";
  header();
  for(int i = 0; i < n; i++)
    print(job[i]);

}

void waitTime(Job a[], int n)
{
  for(int i = 0; i < n; i++)
    a[i+1].wait = a[i].burst + a[i].wait;
}

void turnATime(Job a[], int n)
{
  for(int i = 0; i < n; i++)
    a[i].turnA = a[i].burst + a[i].wait;
}

void header()
{
  cout << "----------------------------------------------\n";
  cout << "PROCESS   BURST   WAIT_TIME   TURN_AROUND_TIME\n";
}

void print(Job a)
{
  cout.width(4);
  cout << a.pid; cout.width(10);
  cout << a.burst; cout.width(10);
  cout << a.wait; cout.width(15);
  cout << a.turnA << "\n";
}
