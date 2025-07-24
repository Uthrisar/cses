#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005; // Maximum number of nodes
vector<int> tree[MAXN];
bool centroidMarked[MAXN];
int subtreeSize[MAXN];

// Function to calculate the size of each subtree
void calculateSubtreeSizes(int node, int parent) {
    subtreeSize[node] = 1; // Initialize size of the current node
    for (int neighbor : tree[node]) {
        if (neighbor != parent && !centroidMarked[neighbor]) {
            calculateSubtreeSizes(neighbor, node);
            subtreeSize[node] += subtreeSize[neighbor]; // Add size of child subtrees
        }
    }
}

// Function to find the centroid of the tree
int findCentroid(int node, int parent, int totalSize) {
    for (int neighbor : tree[node]) {
        if (neighbor != parent && !centroidMarked[neighbor] && subtreeSize[neighbor] > totalSize / 2) {
            return findCentroid(neighbor, node, totalSize);
        }
    }
    return node; // Return current node as centroid
}

// Function to calculate distances from a given node
void calculateDistances(int node, int parent, int depth, vector<int> &distances) {
    distances.push_back(depth);
    for (int neighbor : tree[node]) {
        if (neighbor != parent && !centroidMarked[neighbor]) {
            calculateDistances(neighbor, node, depth + 1, distances);
        }
    }
}

// Function to count pairs of distances that sum to k
int countPairsWithDistanceK(vector<int> &distances, int k) {
    unordered_map<int, int> distanceCount; // Use unordered_map for faster access
    int count = 0;

    for (int d : distances) {
        count += distanceCount[k - d]; // Check for pairs
        distanceCount[d]++; // Update the count of this distance
    }

    return count;
}

// Function to count paths from the centroid
int countPathsFromCentroid(int centroid, int k) {
    vector<int> distances;
    int pathCount = 0;

    // Calculate distances from each child of the centroid
    for (int neighbor : tree[centroid]) {
        if (!centroidMarked[neighbor]) {
            distances.clear(); // Clear previous distances
            calculateDistances(neighbor, centroid, 1, distances); // Start from depth 1
            pathCount += countPairsWithDistanceK(distances, k); // Count pairs for the current subtree
        }
    }

    return pathCount;
}

// Main function to solve the problem
int solve(int node, int k) {
    calculateSubtreeSizes(node, -1);
    int totalSize = subtreeSize[node];
    int centroid = findCentroid(node, -1, totalSize);

    // Count paths passing through the centroid
    int pathCount = countPathsFromCentroid(centroid, k);

    // Mark the centroid as processed
    centroidMarked[centroid] = true;

    // Recurse on subtrees
    for (int neighbor : tree[centroid]) {
        if (!centroidMarked[neighbor]) {
            pathCount += solve(neighbor, k);
        }
    }

    return pathCount;
}

int main() {
    int n, k;
    cin >> n >> k;

    // Input the edges
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    // Call the solve function and output the result
    cout << solve(1, k) << endl;

    return 0;
}
