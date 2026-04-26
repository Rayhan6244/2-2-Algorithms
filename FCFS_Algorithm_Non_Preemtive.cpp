#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int arrival[n], burst[n], completion[n], tat[n], waiting[n];
    int pid[n]; // to track process IDs after sorting

    // Input
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "P" << i+1 << " - Arrival Time: ";
        cin >> arrival[i];
        cout << "P" << i+1 << " - Burst Time: ";
        cin >> burst[i];
    }

    // Sort by arrival time (bubble sort)
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arrival[j] > arrival[j+1]) {
                swap(arrival[j], arrival[j+1]);
                swap(burst[j],   burst[j+1]);
                swap(pid[j],     pid[j+1]);
            }

    // Calculate Completion, TAT, Waiting Time
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < arrival[i]) time = arrival[i]; // CPU idle
        completion[i] = time + burst[i];
        tat[i]        = completion[i] - arrival[i];
        waiting[i]    = tat[i] - burst[i];
        time          = completion[i];
    }

    // ---- Gantt Chart ----
    cout << "\n--- Gantt Chart ---\n|";
    time = 0;
    for (int i = 0; i < n; i++) {
        if (time < arrival[i]) {
            cout << " IDLE |";
            time = arrival[i];
        }
        cout << " P" << pid[i] << " |";
        time += burst[i];
    }
    cout << "\n0";
    time = 0;
    for (int i = 0; i < n; i++) {
        if (time < arrival[i]) {
            time = arrival[i];
            cout << "    " << time;
        }
        time += burst[i];
        cout << "    " << time;
    }
    cout << "\n";

    // ---- Results Table ----
    cout << "\n--- Process Table ---\n";
    cout << "Process | Arrival | Burst | Completion | TAT | Waiting\n";
    cout << "---------------------------------------------------------\n";

    float totalTAT = 0, totalWT = 0;
    for (int i = 0; i < n; i++) {
        cout << "  P" << pid[i]
             << "    |    " << arrival[i]
             << "    |   " << burst[i]
             << "   |     " << completion[i]
             << "      |  " << tat[i]
             << "  |   " << waiting[i] << "\n";
        totalTAT += tat[i];
        totalWT  += waiting[i];
    }

    // ---- Averages ----
    cout << "---------------------------------------------------------\n";
    cout << "Average Turnaround Time : " << totalTAT / n << " ms\n";
    cout << "Average Waiting Time    : " << totalWT  / n << " ms\n";

    return 0;
}
