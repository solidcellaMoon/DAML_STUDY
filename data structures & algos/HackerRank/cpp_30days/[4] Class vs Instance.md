# [4] Class vs. Instance



**[[링크]](https://www.hackerrank.com/challenges/30-class-vs-instance/problem?h_r=email&unlock_token=c2167028aab23a88a98382080cc2e1e4c92b6cb1&utm_campaign=30_days_of_code_continuous&utm_medium=email&utm_source=daily_reminder)**



``` c++
using namespace std;
#include <iostream>

class Person{
    public:
        int age;
        Person(int initialAge);
        void amIOld();
        void yearPasses();
    };

    Person::Person(int initialAge){
        // Add some more code to run some checks on initialAge
        if (initialAge < 0){
            cout << "Age is not valid, setting age to 0." << endl;
            age = 0;
        } else{
            age = initialAge;
        }

    }

    void Person::amIOld(){
        // Do some computations in here and print out the correct statement to the console 
        if(age < 13){
            cout << "You are young." << endl;
        } else if (age < 18){
            cout << "You are a teenager." << endl;
        } else {
            cout << "You are old." << endl;
        }

    }

    void Person::yearPasses(){
        // Increment the age of the person in here
        age += 1;

    }
```





``` c++
using namespace std;
#include <iostream>

class Person{
    public:
        int age;
        Person(int initialAge);
        void amIOld();
        void yearPasses();
    };

    Person::Person(int initialAge){
        // Add some more code to run some checks on initialAge
        if (initialAge < 0){
            cout << "Age is not valid, setting age to 0." << endl;
            age = 0;
        } else{
            age = initialAge;
        }

    }

    void Person::amIOld(){
        // Do some computations in here and print out the correct statement to the console 
        if(age < 13){
            cout << "You are young." << endl;
        } else if (age < 18){
            cout << "You are a teenager." << endl;
        } else {
            cout << "You are old." << endl;
        }

    }

    void Person::yearPasses(){
        // Increment the age of the person in here
        age += 1;

    }

int main(){
    int t;
	int age;
    cin >> t;
    for(int i=0; i < t; i++) {
    	cin >> age;
        Person p(age);
        p.amIOld();
        for(int j=0; j < 3; j++) {
        	p.yearPasses(); 
        }
        p.amIOld();
      
		cout << '\n';
    }

    return 0;
}
```

