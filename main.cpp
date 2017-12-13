#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std; 


template<typename T>
void print(T*arr, int N){
	for (int i = 0; i < N; i++){
		cout << arr[i];
	}
}

int main(){
	int N;
	int C;
	cout << "Input the number of things" << endl;
	cin >> N;
	cout << "Input the capacity" << endl;
	cin >> C;

	//Iitializing
	bool *curPack = new bool[N];
	bool *finalPack = new bool[N];
	for (int i = 0; i < N; i++){
		curPack[i] = 0;
		finalPack[i] = 0;
	}
	double  curWeight = 0;
	double finalWeight = 0;
	double * things = new double[N];
	cout << "Input weights of the objects" << endl;
	for (int i = 0; i < N; i++){
		double temp;
		cin >> temp;
		things[i] = temp;
	}

	double * profits = new double[N];
	double finalProfit = 0;
	double curProfit = 0;
	cout << "Input profits of the objects" << endl;
	for (int i = 0; i < N; i++){
		double temp;
		cin >> temp;
		profits[i] = temp;
	}


	//Computing
	for (int i = 0; i < pow(2, N) - 1; i++){
		int k = N - 1;
		while ((curPack[k] == 1) && (k>0)){
			curPack[k] = 0;
			k--;
		}
		curPack[k] = 1;

		curWeight = 0;
		curProfit = 0;
		for (int j = 0; j < N; j++){
			if (curPack[j] == 1){
				curWeight += things[j];
				curProfit += profits[j];
			}
		}

		if ((curWeight <= C) && (curProfit>finalProfit)){
			finalWeight = curWeight;
			finalProfit = curProfit;
			for (int l = 0; l < N; l++)
				finalPack[l] = curPack[l];
		}

	}


	cout << endl<<"Final pack: ";
	print(finalPack, N);
	cout << endl << "Final profit: " << finalProfit << endl << "Final weight: "<<finalWeight << endl;
	

	delete things;
	delete curPack;
	delete finalPack;
	delete profits;

	cin.get();
	cin.get();
	return 0;




	}