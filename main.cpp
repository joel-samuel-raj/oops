#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

int input;

void postman(int input, string location);
vector <int> integerToArray(int x);
vector <vector <const char*>> writer (int, string);
const char* mapping(int);
vector <vector<const char*>> transpose (vector <vector<const char*>> vec);

int main(int args, char * argv[])
{
    string name;
    ofstream MyExcelFile;
    string location;
    cout << "\n\nEnter the name of the file ";
    cin >> name;
    location = "C:\\Users\\Joel Samuel\\Desktop\\mini project cpp\\forms\\" + name + ".csv";
    cout << "\nAvailable data\n\t(1)Name\n\t(2)Roll Number\n\t(3)DOB\n\t(4)Mob Number\n\t(5)Mail ID\n\n";
    cin >> input;
//    MyExcelFile.open(location);
    //MyExcelFile << "First Name, Last Name, Middle Initial" << endl;
    //MyExcelFile << "Michael, Jackson, B." << endl;
    //MyExcelFile.close();
//    postman(input, location);

    //XMLDocument doc;
    //doc.LoadFile("main.xml");
    //const char* title = doc.FirstChildElement( "root" )->FirstChildElement( "row" )->FirstChildElement( "Name" )->GetText();
    //cout << title;
    writer(input,location);
    return 0;
}

//void postman (int input, string location) {
//    ofstream MyExcelFile;
//    MyExcelFile.open(location);
//    vector <vector<const char*>> vec =  writer(input);
//    for (int i = 0; i < vec.size(); i++) {
//        for(int j = 0; j < vec[i].size(); j++) {
//            string data = vec[i][j];
//            MyExcelFile << arrayOne[i] << ",";
//            cout << i  << vec[i][j] << " ";
//        }
//
//        MyExcelFile << "\n";
//    }
//
//    MyExcelFile.close();
//}

vector <vector <const char*>> writer (int keys, string location) {
    XMLDocument doc;
    doc.LoadFile("main.xml");
    vector <const char*> data = {};
    vector <vector <const char*>> result = {};
    vector <int> index = integerToArray(keys);
    while(index.size()) {
        //cout << index.back()<<"\n";
        int indice = index.back();
        //cout << key << "\n";
        XMLElement* element = doc.FirstChildElement( "root" )->FirstChildElement( "row" );
        while (element != 0) {
            const char* temp;
            const char* key = mapping(indice);
            temp =  element->FirstChildElement(key)->GetText();
            data.push_back(temp);
            element = element->NextSiblingElement("row");
        }
        //cout << key << "\n";
        //for(int i = 0; i < data.size(); i++) {
          //  cout << data[i] << ",";
        //};
        result.push_back(data);
        data = {};
//        cout << "\n";
        index.pop_back();
    }
//    result = transpose(result);
    for(int i = 0; i < result.size(); i++) {
          for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
          }
    };
    ofstream myfile;
    myfile.open(location);
    for(int i = 0; i < result.size(); i++) {
          for (int j = 0; j < result[i].size(); j++) {
            myfile << result[i][j] << ",";
          }
          myfile << "\n";
    }
    myfile.close();
    return result;
}

//vector <const char*> constructor (vector <vector <int>> x) {
//    vector <const char*> y = {};
//    for (int i = 0; i < x.size(); i++) {
//        for (int j = 0; j < x[i].size(); j++) {
//            y.push_back(x[i][j]);
//        }
//    }
//}
vector <int> integerToArray(int x)
{
    vector <int> resultArray;
    while (true)
    {
        resultArray.insert(resultArray.begin(), x%10);
        x /= 10;
    if(x == 0) {
            reverse(resultArray.begin(), resultArray.end());
            return resultArray;
        }
    }
}

const char* mapping (int i) {
    if (i == 1 ) {
        return "Name";
    }
    if (i == 2 ) {
        return "Roll";
    }
    if (i == 3 ) {
        return "DOB";
    }
    if (i == 4 ) {
        return "Phone";
    }
    if (i == 5 ) {
        return "Mail";
    }
}

vector<vector<const char*>> transpose(vector<vector<const char*>> A) {
        vector<vector<const char*>> transposed(A[0].size(),vector<const char*>(A.size()));
        for(int i = 0; i < A.size(); ++i){
            for(int j = 0; j < A[i].size(); j++)
            {
                transposed[j][i] = A[i][j];
            }
        }
//        for(int i = 0; i < transposed.size(); ++i){
//            for(int j = 0; j < transposed[i].size(); ++j)
//            {
//                cout << transposed[i][j];
//                cout << "\n";
//            }
//        }
        return transposed;
}


