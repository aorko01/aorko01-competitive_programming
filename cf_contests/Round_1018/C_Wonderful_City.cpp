#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

// Check if the current grid is beautiful (no adjacent buildings with same height)
bool isBeautiful(const vector<vector<int>>& h, int n) {
    // Check rows
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (h[i][j] == h[i][j + 1]) {
                return false;
            }
        }
    }
    
    // Check columns
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n - 1; ++i) {
            if (h[i][j] == h[i + 1][j]) {
                return false;
            }
        }
    }
    
    return true;
}

void solve() {
    int n;
    cin >> n;
    
    vector<vector<int>> h(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> h[i][j];
        }
    }
    
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];  // Cost to hire worker i from company A
    }
    
    for (int i = 0; i < n; ++i) {
        cin >> b[i];  // Cost to hire worker i from company B
    }
    
    // We need to check if we can make the city beautiful using only rows and columns operations
    // For each pair of adjacent buildings, if they have the same height, we need to increase one
    // of them by hiring a worker from either company A or B
    
    // This is a bipartite graph matching problem:
    // - We have rows and columns that need to be incremented
    // - We need to find minimum cost to make all adjacent buildings have different heights
    
    // Create a binary mask to represent which rows and columns to increment
    ll minCost = 1e18;
    
    // Try all possible combinations of rows to increment (2^n possibilities)
    for (int rowMask = 0; rowMask < (1 << n); ++rowMask) {
        // Create a modified grid with incremented rows
        vector<vector<int>> newH = h;
        
        // Apply row increments based on rowMask
        for (int i = 0; i < n; ++i) {
            if ((rowMask >> i) & 1) {  // If we decided to hire worker i from company A
                for (int j = 0; j < n; ++j) {
                    newH[i][j]++;
                }
            }
        }
        
        // For each column, determine if it needs to be incremented
        vector<bool> needColIncrement(n, false);
        bool possible = true;
        
        // Check for each column if adjacent buildings in the column have the same height
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n - 1; ++i) {
                if (newH[i][j] == newH[i + 1][j]) {
                    needColIncrement[j] = true;
                    break;
                }
            }
        }
        
        // Check if incrementing columns would fix row adjacency issues
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                if (newH[i][j] == newH[i][j + 1]) {
                    // If both columns have the same need for increment, it's impossible to distinguish them
                    if (needColIncrement[j] == needColIncrement[j + 1]) {
                        possible = false;
                        break;
                    }
                }
            }
            if (!possible) break;
        }
        
        // If it's possible with this combination of row increments
        if (possible) {
            ll cost = 0;
            
            // Calculate the cost of hired row workers
            for (int i = 0; i < n; ++i) {
                if ((rowMask >> i) & 1) {
                    cost += a[i];
                }
            }
            
            // Calculate the cost of hired column workers
            for (int j = 0; j < n; ++j) {
                if (needColIncrement[j]) {
                    cost += b[j];
                }
            }
            
            // Update minimum cost
            minCost = min(minCost, cost);
        }
    }
    
    // If we couldn't make the city beautiful
    if (minCost == 1e18) {
        cout << -1 << endl;
    } else {
        cout << minCost << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}