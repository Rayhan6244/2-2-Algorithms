#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int profit;
    int weight;
    double ratio;
};

bool comp(const Item &a, const Item &b)
{
    return a.ratio > b.ratio;
}

int main()
{
    int n;
    cout << "Number of items: ";
    cin >> n;

    int capacity;
    cout << "Bag capacity: ";
    cin >> capacity;

    vector<Item> items(n);

    cout << "Profits: ";
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].profit;
    }

    cout << "Weights: ";
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].weight;
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }

    sort(items.begin(), items.end(), comp);

    double totalProfit = 0.0;
    int bakiAse = capacity;

    cout << "\nSelected items (profit, weight, ratio):\n";

    for (int i = 0; i < n; i++)
    {
        if (items[i].weight <= bakiAse)
        {
            totalProfit += items[i].profit;
            bakiAse -= items[i].weight;
            cout << items[i].profit << " " << items[i].weight << " " << items[i].ratio << " (Full)\n";
        }
        else
        {
            double fraction = (double)bakiAse / items[i].weight;
            totalProfit += items[i].profit * fraction;
            cout << items[i].profit << " " << items[i].weight << " " << items[i].ratio << " (Fraction: " << fraction << ")\n";
            break;
        }
    }

    cout << "\nMaximum profit = " << totalProfit << endl;

    return 0;
}
