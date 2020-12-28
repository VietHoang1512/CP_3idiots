class SubrectangleQueries
{
public:
    int height;
    int width;

    vector<vector<int>> matrix;

    SubrectangleQueries(vector<vector<int>> &rectangle)
    {
        height = rectangle.size();
        width = rectangle[0].size();
        matrix = rectangle;
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)
    {
        assert((row1 >= 0) && (row1 < height) && (row2 >= 0) && (row2 < height));
        assert((col1 >= 0) && (col1 < width) && (col2 >= 0) && (col2 < width));

        for (int i = row1; i <= row2; i++)
        {
            for (int j = col1; j <= col2; j++)
            {
                matrix[i][j] = newValue;
            }
        }
    }

    int getValue(int row, int col)
    {
        return matrix[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */