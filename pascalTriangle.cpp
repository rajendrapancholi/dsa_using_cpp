/* Pascal Triangle using 2d vector
        1
       1 1
      1 2 1
     1 3 3 1
    1 4 6 4 1
  */
#include <iostream>
#include <vector>

using namespace std;

// Create pascal triangle
vector<vector<int>> pascalTriangle(int &n)
{
    // declare n size of temp vector <pascal>
    vector<vector<int>> pascal(n);
    for (int i = 0; i < n; i++)
    {
        pascal[i].resize(i + 1);
        for (int j = 0; j < i + 1; j++)
        {
            if (j == 0 || j == i)
            {
                pascal[i][j] = 1;
            }
            else
            {
                pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
            }
        }
    }

    return pascal;
}
int main()
{
    int n;
    cout << "Enter the size of pascal triangle: \n";
    // cin >> n;
    n = 5;
    // Declare 2d vector
    vector<vector<int>> result;
    // Invoked pascalTriangle()
    result = pascalTriangle(n);
    // Display result
    for (int i = 0; i < result.size(); i++)
    {
        // print space for pyramid
        for (int k = result.size() - (i + 1); k > 0; k--)
        {
            cout << " ";
        }
        // print elements
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}