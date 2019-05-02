#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
const float kappa = 200;
const float sph = 900;
const float rho = 2700;
const float dx = 1.0/100;
const float dt = 5.0/10;
const int Nx = 201;
const int Nt = 201;
const float cons = kappa*dt/(sph*rho*dx*dx);


int main(){
    float T[Nx][2] = {0};
    for(int i = 0; i < Nx; i ++){
        T[i][0] = 300;
    }
    ofstream outline;
    outline.open("datos.txt");
    for(int i = 80; i <= 120; i ++){
        T[i][0] = 500.0;
    }
    for(int i = 0; i < Nx; i ++){
        outline << T[i][0] << " ";
    }
    outline <<  endl;
    for(int i = 1; i < Nt; i++){
        outline << T[0][0] << " ";
        for(int j = 1; j < Nx-1; j ++){
            T[j][1] = T[j][0] + cons*(T[j+1][0]+T[j-1][0]-2*T[j][0]);
            outline << T[j][1] << " ";
        }
        outline << T[Nx-1][0] << endl;
        for(int j = 1; j < Nx-1; j ++){
            T[j][0] = T[j][1];
        }
    }
    return 0;
}

    