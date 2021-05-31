#include <iostream>

void setBubbleFoil(bool array[][12], bool value)
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            array[i][j] = value;
        }
    }
}

void printArray(bool array[][12])
{
    std::cout << "Foil state:\n";
    std::cout << "\t\t";
    for (int i = 0; i < 12; i++)
    {
        std::cout << i + 1 << "\t";
    }
    std::cout << "\n\t\t";
    for (int i = 0; i < 12; i++)
    {
        std::cout << "_\t";
    }
    std::cout << "\n";
    for (int i = 0; i < 12; i++)
    {
        std::cout << i + 1 << "\t|\t";
        for (int j = 0; j < 12; j++)
        {
            if (array[i][j])
                std::cout << "o";
            else
                std::cout << "x";

            std::cout << "\t";
        }
        std::cout << "\n";
    }
}

int getCoord(std::string label)
{
    int coords;
    do {
        std::cout << "Please enter the " << label << " coords:\n";
        std::cin >> coords;
        if (coords < 1 || coords > 12) std::cout << "Bad input. Please enter the integer from 1 to 12\n";
    }while (coords < 1 || coords > 12);

    return coords;
}

void popTheBubbles(bool array[][12], int row_start, int col_start, int row_end, int col_end)
{
    int smallest_row = (row_start > row_end ? row_end : row_start) - 1;
    int biggest_row = (row_start < row_end ? row_end : row_start) - 1;

    int smallest_col = (col_start > col_end ? col_end : col_start) - 1;
    int biggest_col = (col_start < col_end ? col_end : col_start) - 1;

    for (int i = smallest_row; i <= biggest_row; i++)
    {
        for (int j = smallest_col; j <= biggest_col; j++)
        {
            if (array[i][j] == true)
            {
                array[i][j] = false;
                std::cout << "Pop!\n";
            }
        }
    }
}

bool allBubblesArePopped(bool array[][12])
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (array[i][j]) return false;
        }
    }
    printArray(array);
    std::cout << "All bubbles are popped!\n";
    return true;
}

int main() {

    bool bubbleFoil[12][12];
    setBubbleFoil(bubbleFoil, true);

    while (!allBubblesArePopped(bubbleFoil))
    {
        printArray(bubbleFoil);

        int row_start = getCoord("start row");
        int col_start = getCoord("start column");

        int row_end = getCoord("end row");
        int col_end = getCoord("end column");

        popTheBubbles(bubbleFoil, row_start, col_start, row_end, col_end);
    }
    return 0;
}