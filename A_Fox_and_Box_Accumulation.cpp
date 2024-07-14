#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> strengths(n);
    for (int i = 0; i < n; ++i) {
        cin >> strengths[i];
    }

    // Sort the strengths in non-decreasing order
    sort(strengths.begin(), strengths.end());

    // Priority queue to store the remaining capacities of the piles
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int strength : strengths) {
        if (!pq.empty() && pq.top() <= strength) {
            // If the top pile can support one more box, place it there
            int top = pq.top();
            pq.pop();
            pq.push(top + 1);  // Increment the box count for this pile
        } else {
            // Otherwise, create a new pile
            pq.push(1);
        }
    }

    // The number of piles is the size of the priority queue
    cout << pq.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
