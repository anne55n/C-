// Name: Anastassiya Neznanova
// ID: 1093
// MAC281, Section 3013
// Project 2, Part 3, number 2b
// This program displays all the equivalence relations on a set of seven elements.

#include <iostream>
#include <fstream>
using namespace std;

bool isSymmetric(int m[7][7]);
bool isReflexive(int m[7][7]);
int transitiveClosure(int graph[7][7]);
bool isTransitive(int graph[7][7]);
int matrix4[4][4];

int main(){
	
	int matrix[7][7];
	for(int i = 0; i < 7; ++i){
		for(int j = 0; j < 7; ++j){
			matrix[i][j] = 0;
		}
	}
    
	ofstream myFile;
    myFile.open("myFile1.txt", ios :: app); // opens file
    if(!myFile) // if not found
        cout << "File could not be opened"<<endl; //display not found
	
	for(int h = 0; h < 28; ++h){
		for(int i = h; i < 7; ++i){
			for(int j = h; j < 7; ++j){
				matrix[h][j] = 1;
				matrix[j][h] = 1;
				
				matrix[i][j] = 1;
				matrix[j][i] = 1;
                
				for(int i = 0; i < 7; ++i){
					for(int j = 0; j < 7; ++j){
						matrix[0][0] = 1, matrix[1][1] = 1, matrix[2][2] = 1, matrix[3][3] = 1, matrix[4][4] = 1;
						matrix[i][j] = matrix[i][j];
						if(isReflexive(matrix) && isSymmetric(matrix) && isTransitive(matrix))
        					myFile << matrix[i][j] << " ";
    				}
					myFile << endl;
				}
				myFile<< endl;
				
				matrix[i][j] = 0;
				matrix[j][i] = 0;
			}
		}
	}
    
	myFile.close();
	return 0;
}



int transitiveClosure(int graph[7][7]) // finds the transitive closure of matrix
{
    int count = 0;
    
    for (int k = 0; k < 7; k++){
        for (int i = 0; i < 7; i++){
            for (int j = 0; j < 7; j++){
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }
    
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            count = graph[i][j] ;
    
    return count;
}

bool isTransitive(int graph[7][7]){ // if transitive closure equal original matrix, then matrix is transitive
    
    int k = 0;
    
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            matrix4[i][j] = graph[i][j];
    
    transitiveClosure(graph);
    
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            if(matrix4[i][j] == graph[i][j])
                k++;
    
    if(k == 49)
        return true;
    else
        return false;
}
bool isReflexive(int matrix2[7][7]){
    for(int i = 0; i < 7; i++)
        if(!matrix2[i][i]) // if m[i][i] (is 1) then 0 return false
            return false;
    return true;
}

bool isSymmetric(int matrix2[7][7]){
    for(int i = 0; i < 7; i++)
        for(int j = 0; j < 7; j++)
            if(matrix2[i][j] && !matrix2[j][i]) // if equal 1 and 0, would be 1, else return false
                return false;
    return true;
}