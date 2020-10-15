#include <bits/stdc++.h>
using namespace std;
  
int main() 
{
      int n;
      cout<<"Enter number of processes\n";
      cin>>n;
      int wait[n];
      int burst[n];
      int arrival[n];
      int turn[n];
      int remaining[n];
      int priority[n+1];
       for(int i =0;i<n;i++)
        {
            cout<<"Enter burst time for process P"<<i<<"\n";
            cin>>burst[i];
            cout<<"Enter arrival time for process P"<<i<<"\n";
            cin>>arrival[i];
            cout<<"Enter priority for process P"<<i<<"\n";
            cin>>priority[i];
            remaining[i]=burst[i];
        }
      int count =0;
      int process =n;
      priority[n]=INT_MAX;
      double wait_time = 0, turnaround_time = 0, end;
      float average_waiting_time, average_turnaround_time;
     
      for(int time = 0; count != n; time++)
      {
            process = n;
            for(int i = 0; i < n; i++)
            {
                  if(arrival[i] <= time && priority[i] < priority[process] && remaining[i] > 0)
                  {
                        process = i;
                  }
            }
            remaining[process]--;
            if(remaining[process] == 0)
            {
                  count++;
                  end = time + 1;
                  wait[process]=  end - arrival[process] - burst[process];
                  turn[process]= end - arrival[process];
                  wait_time = wait_time + end - arrival[process] - burst[process];
                  turnaround_time = turnaround_time + end - arrival[process];
            }
      }
      for(int i =0;i<n;i++)
      {
        cout<<"Waiting Time for P"<<i<<" = "<<wait[i]<<"\n";
        cout<<"Turn Around Time for P"<<i<<" = "<<turn[i]<<"\n";
      }
      average_waiting_time = wait_time / n; 
      average_turnaround_time = turnaround_time / n;
      cout<<"Average Waiting Time = "<< average_waiting_time<<"\n";
      cout<<"Average Turnaround Time = "<< average_turnaround_time;
      return 0;
}