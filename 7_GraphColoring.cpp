#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &matrix, int vertex, int color, int nodeColor[])
{
    for (int i = 0; i < matrix[0].size(); i++)
    {
        if (matrix[vertex][i] == 1 && nodeColor[i] == color)
        {
            return false;
        }
    }
    return true;
}

void checkGraphColoring(vector<vector<int>> &matrix, int start, int noOfColor, int nodeColor[])
{
    if (start == matrix.size())
    {
        for (int i = 0; i < 4; i++)
        {
            cout << nodeColor[i] << " ";
        }
        cout << endl;
        return;
    }
    if (nodeColor[start] == 0)
    {
        for (int color = 1; color <= noOfColor; color++)
        {
            if (isSafe(matrix, start, color, nodeColor))
            {
                nodeColor[start] = color;
                checkGraphColoring(matrix, start + 1, noOfColor, nodeColor);
                nodeColor[start] = 0;
            }
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}};

    int noOfColor = 2;
    int nodeColor[4] = {0};

    checkGraphColoring(matrix, 0, noOfColor, nodeColor);

    return 0;
}
