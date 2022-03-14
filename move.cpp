// robot after the complete movement
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
 
// Function to find  final position of
// robot after the complete movement
void finalPosition(string move)
{
    int l = move.size();
    int countUp = 0, countDown = 0;
    int countLeft = 0, countRight = 0;
 
    // Traverse the instruction string 'move'
    for (int i = 0; i < l; i++)
    {
        // For each movement increment its
        // respective counter
        if (move[i] == 'U')
            countUp++;
        else if (move[i] == 'D')
            countDown++;
        else if (move[i] == 'L')
            countLeft++;
        else if (move[i] == 'R')
            countRight++;
    }
 
    // Required final position of robot
    cout << "Final Position: ("
         << (countRight - countLeft)
         << ", " << (countUp - countDown)
         << ")" << endl;
}
 
// Driver code

int main()
{
    string move;

    cout << "Type U/D/R/L to move : ";
    cin >> move;
    finalPosition(move);
    return 0;
}
