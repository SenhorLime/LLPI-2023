#include "iostream"

using namespace std;

class Gato{
  public:
    int getAge();
    void setAge (int Age);
    void meow();

  private:
    int itsAge;
};

int Gato::getAge() {
  return itsAge;
}

void Gato::setAge(int age){
  itsAge = age;
}

void Gato::meow() {
  cout << "Meow.\n";
}

int main(){
  Gato garfield;
  Gato tom;

  garfield.setAge(3);
  garfield.meow();
  
  tom.setAge(7);
  tom.meow();

  cout << "O Garfield tem " << garfield.getAge() << " anos de idade.\n";
  garfield.meow();

  cout << "O Tom tem " << tom.getAge() << " anos de idade.\n";
  tom.meow();

  return 0;
}
