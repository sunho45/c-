#include <iostream>
#include <fstream>
using namespace std;
int main(){
ofstream outFile("data.txt");
outFile<<"data"<<endl;
outFile.close();

}