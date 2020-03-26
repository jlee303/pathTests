#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <string>  

using namespace std;

#include "prototypes.h"
void distanceFtCheck();
string simplify(double);

int main(){
    distanceFtCheck();
}

void distanceFtCheck(){
    int k, errors = 0;
    string str, check;
    vector<point> listOne;
    
    listOne.push_back(point(0,0)); 
    listOne.push_back(point(-17.2, 0)); 
    listOne.push_back(point(0, -6.10)); 
    listOne.push_back(point(34, 50.1)); 
    listOne.push_back(point(-13.1, -15.2));
    listOne.push_back(point(-180, 90));
    listOne.push_back(point(180, 90));
    listOne.push_back(point(180, -90));
    listOne.push_back(point(-180, -90));
    
    vector<long> checkList = {6281673, 2227802, 21136299, 7291397, 32869222, 32869222, 32869222, 
                             6653752, 25551019, 5561213, 32869222, 32869222, 32869222, 22839025, 
                             5808728, 30641419, 30641419, 35097025, 28427628, 47293274, 47293274, 
                             18445170, 27465788, 27465788, 38272656, 0, 65738445, 65738445};
    cout << "Testing Function: distanceFt" << endl << endl;
    for(int i = 0; i < listOne.size(); i++){
        for(int j = i + 1; j < listOne.size() - 1; j++){
            str = simplify(distanceFt(listOne.at(i), listOne.at(j)));
            check = to_string(checkList.at(k));
            if(stoi(str) != checkList.at(k)){
                cout << "   ERROR between points: (" << listOne.at(i).log << ", " << listOne.at(i).lat << ") & (" << listOne.at(j).log << ", " << listOne.at(j).lat  << ")" << endl;
                cout << "\tExpected Output: " << check ;
                if(check.size() > 2){
                    cout << " -OR- " << check.at(0) << "." << check.substr(1,3) << "e" << check.size()-1 << endl;
                }else{
                    cout << endl;
                }
                cout << "\tActual Output: "<< distanceFt(listOne.at(i), listOne.at(j)) << endl;
                errors++;
            }else{
                cout << "   Testing points: (" << listOne.at(i).log << ", " << listOne.at(i).lat << ") & (" << listOne.at(j).log << ", " << listOne.at(j).lat  << ")" << endl;
                cout << "\tExpected Output: " << check ;
                if(check.size() > 2){
                    cout << " -OR- " << check.at(0) << "." << check.substr(1,check.size()-3) << "e" << check.size()-1 << endl;
                }else{
                    cout << " <= Answer rounded..." << endl;
                }
                cout << "\tActual Output: "<< distanceFt(listOne.at(i), listOne.at(j)) << endl << endl;
            }
            k++;
        }
    } 
    
    cout << endl;
    cout << "Total Errors: " << errors << "/" << checkList.size() << endl;
}

string simplify(double x){
    string original = to_string(x);
    for(int i = 0; i < original.size(); i++){
        if(int(original.at(i)) == 46){
            original = original.substr(0, i);
        }
    }
    return original;
}
