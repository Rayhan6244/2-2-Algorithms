#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int arrival[n], burst[n], completion[n], tat[n], waiting[n];

    // Input
    for (int i = 0; i < n; i++) {
        cout << "P" << i+1 << " - Arrival Time: ";
        cin >> arrival[i];
        cout << "P" << i+1 << " - Burst Time: ";
        cin >> burst[i];
    }

    // Sort by arrival time (simple bubble sort)
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arrival[j] > arrival[j+1]) {
                swap(arrival[j], arrival[j+1]);
                swap(burst[j], burst[j+1]);
            }

    // Calculate times
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < arrival[i]) time = arrival[i]; // CPU idle wait
        completion[i] = time + burst[i];
        tat[i]        = completion[i] - arrival[i];
        waiting[i]    = tat[i] - burst[i];
        time          = completion[i];
    }

    // Output table
    cout << "\nProcess | Arrival | Burst | Completion | TAT | Waiting\n";
    cout << "--------------------------------------------------------\n";
    float totalTAT = 0, totalWT = 0;
    for (int i = 0; i < n; i++) {
        cout << "  P" << i+1 << "    |    " << arrival[i] << "    |   "
             << burst[i] << "   |     " << completion[i]
             << "      |  " << tat[i] << "  |   " << waiting[i] << "\n";
        totalTAT += tat[i];
        totalWT  += waiting[i];
    }

    cout << "\nAverage TAT     : " << totalTAT / n << " ms";
    cout << "\nAverage Waiting : " << totalWT  / n << " ms\n";

    return 0;
}
