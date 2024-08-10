#include <bits/stdc++.h> 
#include <limits>
using namespace std;
int main(){
    int rows, columns;
    int justicePoints = 0, villainsPoints = 0;
    cin >> rows >> columns;
    int justice_league [rows][columns], villains [rows][columns];
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            cin >> justice_league[i][j];
        }
    }
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            cin >> villains[i][j];
        }
    }
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            if (justice_league[i][j] > villains[i][j]){
                justicePoints++;
            }
            else if (justice_league[i][j] < villains[i][j]){
                villainsPoints++;
            }
        }
    }
    if (justicePoints > villainsPoints){
        cout << "Justice League";
    }
    else if (justicePoints < villainsPoints){
        cout << "Villains";
    }
    else{
        cout << "Tie";
    }
    return 0;
}