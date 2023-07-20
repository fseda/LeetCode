#include <vector>
#include <cstdlib>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int lowPrice = pricing[0];
        int highPrice = pricing[1];
        int startRow = start[0];
        int startCol = start[1];
        vector<vector<int>> visited(m, vector<int>(n, false));
        vector<vector<int>> list;

        std::priority_queue<Item, std::vector<Item>, ItemComparator> minHeap;
        minHeap.push({ 0, grid[startRow][startCol], startRow, startCol });
        
        while (!minHeap.empty() && list.size() != k) {
            Item item = minHeap.top();
            minHeap.pop();

            if (visited[item.row][item.col])
                continue;
            
            // update item to visited status
            visited[item.row][item.col] = true;
            
            // Add element to return list
            if ((lowPrice <= item.price && item.price <= highPrice) &&
                item.price != 1)
                list.push_back({ item.row, item.col });
            
            int dx[4] = { -1, 1, 0, 0};
            int dy[4] = { 0, 0, -1, 1};

            for (int i = 0; i < 4; i++) {
                int newRow = item.row + dx[i];
                int newCol = item.col + dy[i];

                if (!isOutOfBounds(newRow, newCol, m, n)) {
                    int price = grid[newRow][newCol];

                    if (price == 0) 
                        continue;
                    
                    minHeap.push({item.distance + 1, price, newRow, newCol});
                }
            }
        }
    
        return list;
    }

private:
    struct Item {
        int distance;
        int price;
        int row;
        int col;

        Item(int distance, int price, int row, int col) : distance(distance), price(price), row(row), col(col) {}
    };

    struct ItemComparator {
        bool operator()(const Item& item1, const Item& item2) const {
            if (item1.distance != item2.distance)
                return item1.distance > item2.distance;

            if (item1.price != item2.price)
                return item1.price > item2.price;

            if (item1.row != item2.row)
                return item1.row > item2.row;

            return item1.col > item2.col;
        }
    };
    
    bool isOutOfBounds(int row, int col, int m, int n) {
        return !(
            0 <= row &&
            row < m &&
            0 <= col &&
            col < n
        );
    }
};

