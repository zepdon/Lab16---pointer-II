#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void showData(double *dPtr,int N,int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << *(dPtr+i);
        if(i%M==M-1) cout << endl;
        else cout << " ";
    }
}

void findRowSum(const double *a,double *b,int N,int M){
	for(int i = 0 ;i < N ; i++){
		b[i] = 0;
	}

	for(int i = 0 ;i < N ; i++){
		for(int j = i*M ; j < M+(i*M) ; j++ ){
			b[i] += a[j];
		}
	}
}

void findColSum(const double *a,double *b,int N,int M){
	for(int i = 0 ;i < M ; i++){
		b[i] = 0;
	}

	for(int i = 0 ;i < M ; i++){
		for(int j = i ; j < (N*M) ; j += M ){
			b[i] += a[j];
		}
	}
}

void randData(double *dPtr,int N,int M){
    for(int i = 0; i < N*M; i++){
        *(dPtr+i) = (rand()%101)/100.0;
    }
}