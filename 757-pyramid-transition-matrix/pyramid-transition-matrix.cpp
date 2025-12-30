#include <bits/stdc++.h>
#define fori(N) for (int i = 0; i < N; i++)

using namespace std;

class Solution {

private:
    unordered_map<string, vector<char>> allowedMap;
    // vector<set<string>> seen;
    unordered_set<string> seen;
    int size;
    
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        set<string> emptyset;
        vector<string> layers;
        fori(size) {
            layers.push_back("");
            // seen.push_back(emptyset);
        }
        size = bottom.length();
        for (string pattern : allowed) {
            allowedMap[pattern.substr(0, 2)].push_back(pattern[2]);
        }
        
        return canBuildPyramid(bottom, "");
    }

    bool canBuildPyramid(string prevLayer, string layer) {
            if (layer.length() != prevLayer.length() - 1) {
                bool canBuild = false;
                int index = layer.length();
                string pattern = prevLayer.substr(index, 2);
                try {
                    vector<char> possibles = allowedMap[pattern.substr(0, 2)];
                    for (char letter : possibles) {
                        if (canBuildPyramid(prevLayer, layer + letter)) {
                            canBuild = true;
                        }
                    }
                    return canBuild;
                } catch (exception e) {
                    return false;
                }
            } else if (layer.length() == 1) {
                return true;
            } else {
                if (seen.find(layer) != seen.end()) {
                    return false;
                } else {
                    seen.insert(layer);
                    return canBuildPyramid(layer, "");
                }
            }
        }
};