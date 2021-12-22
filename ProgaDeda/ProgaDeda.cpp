
#include <iostream>
#include<fstream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm>  // sort
using namespace std;

//Размерности массивов СР1, СР2, СР3, СР4, СР5
int size_CP1 = 0;
int size_CP2 = 0;
int size_CP3 = 0;
int size_CP4 = 0;
int size_CP5 = 0;
int size_All = 0;

int i = 0;
int j = 1;
int l = 2;
int o = 3;
int z = 4;

void openFille(double *mass) {
    string buff;
    string buff2;
    ifstream mass1;
    mass1.open("Mass1.txt");
    if (!mass1.is_open()) 
        cout << "Файл не может быть открыт!\n"; 
    else
    {
        cout << "Массив загружен успешно\n";
        while (getline(mass1, buff))
        {
            buff2 += buff + "\n";
        }
    }
       // cout << "===========================================\n" << buff2 << endl; 

        
        int k = 0;
        int t = buff2.length();
        string blokInt;
        for (int i = 1; i < t; i++) {
            if (buff2[i] == '\n') {
                stringstream str;
                str << blokInt; str >> mass[k];
                k++;
                blokInt.clear();
            }
            else {
                blokInt += buff2[i];
            }
        }
}

void vse_razmer(double *mass, vector<double> &CP) {
    
    
    int endEl = 0; //CP2
    int endEl1 = 1;//CP3
    int endEl2 = 2;//CP4
    int endEl3 = 3;//CP5
    
    
    
    double buff; //Вспомагательная переменная, в которую идет запись решений

    //CP(1)
    if (CP.size() == 0) {
        for (int i = 0; i < 88; i++) {
            CP.push_back(mass[i]);
        }
        size_CP1 = CP.size();
    }

    //CP(2)
    for (i = 0; i < j; i++) {
        for (j = endEl; j < 88; j++) {
            if (j > i) {
                buff = mass[i] + mass[j];
                CP.push_back(buff);
            }
        }
        if(endEl != 87)
        endEl++;
    }
    size_CP2 = CP.size() - size_CP1;

    //CP(3)
    endEl = 0;

    for (i = 0; i < j; i++) {

        for (j = endEl; j < l; j++) {
            for (l = endEl1; l < 88; l++) {
                if ((l > j)&&(j > i)) {
                    buff = mass[i] + mass[j] + mass[l];
                    CP.push_back(buff);
                }
            }
            if (endEl1 != 87) {
                endEl1++;
            }
        }
        if (endEl != 87) {
            endEl++;
            endEl1 = endEl + 1;
        }
    }
    size_CP3 = CP.size() - (size_CP1 + size_CP2);
    endEl = 0; endEl1 = 1;

    //CP(4)
    for (i = 0; i < j; i++) {

        for (j = endEl; j < l; j++) {

            for (l = endEl1; l < o; l++) {

                for (o = endEl2; o < 88; o++) {

                    if ((o > l) && (l > j) && (j > i)) {
                        //if (endEl == 78) {cout << " ================= \n";}
                            
                        buff = mass[i] + mass[j] + mass[l] + mass[o];
                        CP.push_back(buff);
                    }
                }
                if (endEl2 != 87) {
                    endEl2++;
                } 
            }
            if (endEl1 != 86) {
                endEl1++;
                endEl2 = endEl1 + 1;
            }
        }
        if(endEl != 85) {
            endEl++;
            endEl1 = endEl + 1;
        }
        
    }

    size_CP4 = CP.size() - (size_CP1 + size_CP2 + size_CP3);


    endEl = 0; endEl1 = 1; endEl2 = 1; 

    
    //CP(5)
    for (i = 0; i < j; i++) {

        for (j = endEl; j < l; j++) {

            for (l = endEl1; l < o; l++) {

                for (o = endEl2; o < z; o++) {

                    for (z = endEl3; z < 88; z++) {

                        if ((z > o)&& (o > l)&& (l > j)&& (j > i)) {
                           // if (endEl == 78) {
                          //      cout << " ================= \n";
                           // }
                            buff = mass[i] + mass[j] + mass[l] + mass[o] + mass[z];
                            CP.push_back(buff);
                        }
                    }
                    if(endEl3 != 87)
                    endEl3++;
                }
                if (endEl2 != 86) {
                    endEl2++;
                    endEl3 = endEl2 + 1;
                }
                
            }
            if (endEl1 != 85) {
                endEl1++;
                endEl2 = endEl1 + 1;
            }
        }
        if (endEl != 84) {
            endEl++;
            endEl1 = endEl + 1;
        }
    }
    
    size_CP5 = CP.size() - (size_CP1 + size_CP2 + size_CP3 + size_CP4);
    size_All = CP.size();
    
}



void delEl(vector<double>& CP) {
   /* int k = 0;
    int c = 0;
    for (int i = 0; i < CP.size(); i++) {

        if((CP[i] != CP[k])&&(i != k)) {
            c = i - 1 ; //break;
            auto iter = i;
            CP.erase(p);
        }
        if (CP[k]==CP[i]) {

            k++;
        }
    }*/


    //Тест неудача
   /* for (int i = 0; i < CP.size(); i++) {
        cout << "Процент" << (i / CP.size())*1000000 << "%\n";
        for (int j = 1; j < CP.size(); j++) {
            if ((CP[i] == CP[j])&&(i != j)) {
                CP.erase((CP.begin() + j));
            }
        }
    } */
   /* vector<double> CP1;
    CP1.push_back(2);
    CP1.push_back(2);
    CP1.push_back(2);
    CP1.push_back(3);
    CP1.push_back(3);
    CP1.push_back(4);
    CP1.push_back(5);
    CP1.push_back(5);
    CP1.push_back(6);*/
    int k = 0;
    for (int i = 1; i < CP.size(); i++) {
       // cout << "Процент сборки" << (i / CP.size()) << "%\n";
        if (i == 100) {
            cout << "ssd\n";
        }


        if ((CP[k] == CP[i]) && (i != k)) {
            CP.erase((CP.begin() + i));
            i--;
            continue;
        }
        if (CP[k] != CP[i]) {
            k = i;
            
        }
            
    }

}

int main()
{
   
    setlocale(LC_ALL, "Russian");
    const int n = 88; // размер массива
    double mass[n];
    vector<double> CP;
    clock_t start = clock();
    openFille(mass); // Считывание изначального массива и перевод в double значение
    vse_razmer(mass, CP);
    sort(CP.begin(), CP.end());

    CP.erase(unique(begin(CP), end(CP)), end(CP));

    //CPNew.reserve(CP.size());
    //copy(CP.begin(), CP.end(), back_inserter(CPNew));

   // CPNew.erase(unique(begin(CPNew), end(CPNew)), end(CPNew));
    delEl(CP);
    /*for (int i = 0; i < 88; i++) {
        cout << mass[i] << "\n";
    }
    cout << "===============================D" << "\n";
    */
    for (int i = 0; i < CP.size(); i++) {

       // cout << CP[i] <<"  {" << i << "}  " << "\n";
    }
    size_All = CP.size();
    cout << CP[CP.size() - 5] << "\n";
    cout << CP[CP.size() - 4] << "\n";
    cout << CP[CP.size() - 3] << "\n";
    cout << CP[CP.size() - 2] << "\n";
    cout << CP[CP.size() - 1] << "\n";
    
    cout << "Размер CP1 - "<< size_CP1 <<endl;
    cout << "Размер CP2 - " << size_CP2 << endl;
    cout << "Размер CP3 - " << size_CP3 << endl;
    cout << "Размер CP4 - " << size_CP4 << endl;
    cout << "Размер CP5 - " << size_CP5 << endl;
    cout << "Размер вектора - " << size_All << endl;



    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);

    return 0;
}
