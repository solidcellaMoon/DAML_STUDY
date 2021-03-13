# [12] Inheritance

**[[링크]](https://www.hackerrank.com/challenges/30-inheritance/problem?h_r=email&unlock_token=bf14e550f71c989368442e111b71527420f7ce73&utm_campaign=30_days_of_code_continuous&utm_medium=email&utm_source=daily_reminder)**



``` c++
#include <iostream>
#include <vector>
using namespace std;

class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
};

// My code =====
class Student : public Person{
	private:
		vector<int> testScores;
	public:
        Student(string first, string last, int id, vector<int> scores) : Person(first, last, id){
            this->testScores = scores;
        }

        char calculate(){
            int avg = 0;
            string grade = "OEAPDT";
            
            for(int i=0; i < testScores.size(); i++){
                avg += testScores[i];
            }
            avg /= testScores.size();
            
            if (avg >= 90) return grade[0];
            else if (avg >= 80) return grade[1];
            else if (avg >= 70) return grade[2];
            else if (avg >= 55) return grade[3];
            else if (avg >= 40) return grade[4];
            else return grade[5];
        }
};

// End ======

int main() {
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}
```

