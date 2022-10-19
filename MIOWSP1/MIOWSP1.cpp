#include <iostream>
#include <vector>
//kod napisany w Cpp14

class Calculate {
	int V;
	int NoC; 
	std::vector<double> x = { 1 };
	std::vector<double> Prob = {};
	std::vector<double> tempA = { };
	std::vector<int> tempT = { };
	std::vector<double> bi = {};
public:
	Calculate(int volume, int numberOfClasses) : V(volume), NoC(numberOfClasses) {}

	void Addts() {
		for (int i = 0; i < NoC; i++) {
			int temp = 0;
			std::cin >> temp;
			tempT.push_back(temp);
		}
	}

	void AddAs() {
		for (int i = 0; i < NoC; i++) {
			double temp = 0;
			std::cin >> temp;
			tempA.push_back(temp);
		}
	}

	void CalcXs() {
		int n = 1;
		std::vector<double> temp;
		for (int i = 0; i < V; i++) {
			double temporary = 0;
			for (int j = 0; j < NoC; j++) {
				if (n - tempT.at(j) > 0) {
					int id = temp.size() - 1;
					if (j == 0) {
						if (n - tempT.at(j) == 0) {
							temporary += tempA.at(j) * tempT.at(j);
						}
						else {
							temporary = tempA.at(j) * tempT.at(j) * temp.at(id);
						}
					}
					else {
						if (id == 0) {
							temporary += tempA.at(j) * tempT.at(j);
						}
						else {
							temporary += tempA.at(j) * tempT.at(j) * temp.at(id - j);
						}
					}
				}
				else if (n - tempT.at(j) == 0) {
					temporary += tempA.at(j) * tempT.at(j) * x.at(0);
				}
			}
			temp.push_back(temporary / n);
			n++;

		}

		for (int i = 0; i < V; i++) {
			x.push_back(temp.at(i));
		}

		return;
	}
	
	void PerfectP() {
		double temp = 0;

		for (int j = 0; j <= V; j++) {
			temp += x.at(j);
		}

		for (int i = 0; i <= V; i++) {
			Prob.push_back(x.at(i) / temp);
		}
	}

	void CalcBi() {
		int tempID = 0;
		for (int i = 0; i < NoC; i++) {
			double temp = 0;

 			int j = V + 1 - tempT.at(tempID);
			while (j <= V) {
				temp += Prob.at(j);
				j++;
			};
			tempID++;
			bi.push_back(temp);
		}
	}

	void display() {
		for (int i = 0; i < x.size(); i++) {
			std::cout << "x"<<i<<": " <<  x[i] << std::endl;
		}
		for (int i = 0; i < Prob.size(); i++) {
			std::cout << "Prob" << i << ": " << Prob[i] << std::endl;
		}
		for (int i = 0; i < bi.size(); i++) {
			std::cout << "b" << i << ": " << bi[i] << std::endl;
		}
	}

};






int main() {
	int volume = 0;
	int numberOfClasses = 0;
	
	std::cout << "podaj pojemnosc: " << std::endl;
	std::cin >> volume;
	std::cout << std::endl;
	std::cout << "podaj liczbe klas zgloszeniowych: " << std::endl;
	std::cin >> numberOfClasses;
	std::cout << "Podaj " << numberOfClasses << " wartosci t: " << std::endl;
	Calculate rzecz(volume, numberOfClasses);
	rzecz.Addts();
	std::cout << std::endl;
	std::cout << "Podaj " << numberOfClasses << " wartosci a: " << std::endl;
	rzecz.AddAs();
	rzecz.CalcXs();
	rzecz.PerfectP();
	rzecz.CalcBi();
	std::cout << std::endl;
	rzecz.display();
	


	return 0;
}