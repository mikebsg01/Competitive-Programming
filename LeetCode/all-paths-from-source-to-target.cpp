class Solution {
public:
    void traverse(vector<vector<int>>& graph, int endNode, int currentNode, vector<int>& currentPath, vector<vector<int>>& foundPaths) {
        currentPath.push_back(currentNode);

        if (currentNode == endNode) {
            foundPaths.push_back(currentPath);
            currentPath.pop_back();
            return;
        }
        
        for (int i = 0; i < graph[currentNode].size(); ++i) {
            traverse(graph, endNode, graph[currentNode][i], currentPath, foundPaths);
        }
        currentPath.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> currentPath;
        vector<vector<int>> foundPaths;

        traverse(graph, graph.size() - 1, 0, currentPath, foundPaths);
        
        return foundPaths;
    }
};