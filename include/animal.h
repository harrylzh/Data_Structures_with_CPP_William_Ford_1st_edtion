#ifndef ANIMAL_CLASSES
#define ANIMAL_CLASSES
#include <iostream>
class Animal
{
   private:
      char animalName[20];
   public:
      Animal(char nma[])
      {
         strcpy(animalName,nma);
      }
      
      virtual void Identify(void)
      {
         std::cout << "I am a " << animalName << " animal" << std::endl;
      }
};

class Cat: public Animal
{
   private:
      char catName[20];
   public:
      Cat(char nmc[], char nma[]): Animal(nma)
      {
         strcpy(catName,nmc);
      }
      
      virtual void Identify(void)
      {
         Animal::Identify();
         std::cout << "I am a " << catName << " cat" << std::endl;
      }
};


class Tiger: public Cat
{
   private:
      char tigerName[20];
   public:
      Tiger(char nmt[], char nmc[], char nma[]): Cat(nmc,nma)
      {
         strcpy(tigerName,nmt);
      }
      
      virtual void Identify(void)
      {
         Cat::Identify();
         std::cout << "I am a " << tigerName << " tiger" << std::endl;
      }
};

// Announce1 - pass an Animal object by value 
void Announce1(Animal a)
{
   // example of static binding; the compiler directs the 
   // execution of the Identify method of an Animal object
   std::cout << "In static Announce1, calling Identify:" << std::endl;
   a.Identify();
   std::cout << std::endl;
}

// Announce2 - pass a pointer to an Animal object 
void Announce2(Animal *pa)
{
   // dynamic binding is used. the Identify method of the
   // object pointed to by pa is called
   std::cout << "In dynamic Announce2, calling Identify:" << std::endl;
   pa->Identify();
   std::cout << std::endl;
}

#endif   // ANIMAL_CLASSES

