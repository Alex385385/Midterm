#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Child;

class Human
{
private:
   string name;
   int age;
   char sex;
   Human()
   {
      name = "";
      age = 0;
      sex = ' ';
   }
protected:
   Human(string n, int a, char s)
   {
      name = n;
      age = a;
      sex = s;
   }
public:
   void setName(string n)
   {
      name = n;
   }
   void setAge(int a)
   {
      age = a;
   }
   void setSex(char s)
   {
      sex = s;
   }
   string getName()
   {
      return name;
   }
   int getAge()
   {
      return age;
   }
   char getSex()
   {
      return sex;
   }
   virtual void work()
   {

   }

};

class Parent : public Human
{
private:
   vector<Child> children;
public:
   void setChildren(Child c)
   {
      children = c;
   }
   Child getChildren()
   {
      return children;
   }
};

class Child : public Human
{
private:
   Parent Mom;
   Parent Dad;
   Child() : Human()
   {
      Mom;
      Dad;
   }
public:
   Child(string n, int a, char s, Parent m, Parent d) : Human(n, a, s)
   {
      Mom = m;
      Dad = d;
   }
   friend class Parent;
};

int main()
{
   Parent Homer();
   Parent March();
   Child Bart("Bart", 10, 'M', Homer, March);
   Child Lisa("Lisa", 12, 'F', Homer, March);
   Child Maggie("Maggie", 3, 'F', Homer, March);

   return 0;
}
