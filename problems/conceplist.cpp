#include <iostream>
using namespace std;

#define MAX_CONCEPTS 100
struct Concept{
    char * conceptName;
    int timeRequiredToDo;
    char * otherInformation;
    char * conceptInfo;
    Concept(){
        conceptName = "default";
        timeRequiredToDo = 0;
        otherInformation = "";
        conceptInfo = "";
    }
    Concept(char * name, int timeRequired , char * otherInfo, char * cInfo){
        conceptName = name;
        timeRequiredToDo = timeRequired;
        otherInformation = otherInfo;
        conceptInfo = cInfo;
    }
};


class Concept_List {
    public:
        Concept_List();
        ~Concept_List();
        void Add(Concept &toAdd);
        void Display_all();
        void Display_name(char concept_name[]);
        Concept getConcept(int index);
    
    private:
        Concept * arrayOfConcepts;
        int stackPointer;
};

//Constructor 
Concept_List::Concept_List(){
    arrayOfConcepts = new Concept[MAX_CONCEPTS];
    this->stackPointer = 0;
}

Concept_List::~Concept_List(){
    delete(arrayOfConcepts);
}

 void Concept_List::Add(Concept &toAdd){
     if (this->stackPointer < MAX_CONCEPTS){
         arrayOfConcepts[this->stackPointer] = toAdd;    
         this->stackPointer++;
     }
 }

 void Concept_List::Display_name(char concept_name[]){
     for (int i = 0; i < this->stackPointer; i++){
         if(strcmp(concept_name,arrayOfConcepts[i].conceptName) == 0){
            std::cout << arrayOfConcepts[i].conceptInfo;
            break;
         }
     }
 }

 void Concept_List::Display_all(){
      for (int i = 0; i < this->stackPointer; i++){
        std::cout << std::endl;
        std::cout << "\n Concept Name:"<< arrayOfConcepts[i].conceptName;
        std::cout << "\n Time Required :"<< arrayOfConcepts[i].timeRequiredToDo;
        std::cout << "\n Other Information :"<<arrayOfConcepts[i].otherInformation;
        std::cout << "\n Concept Info :"<< arrayOfConcepts[i].conceptInfo;
     }
 }

  Concept Concept_List::getConcept(int index){
      Concept c;
      if(index >=0 && index < MAX_CONCEPTS){
          c= arrayOfConcepts[index];
      }
      return c;
  }

int main(){

    Concept_List list;
    Concept c1("Linklist",45,"data Structures","Mid Sem");
    std::cout << "\n Added a Concept ";
    list.Add(c1);

    Concept c2("DoubleLinklist",45,"data Structures","Third Sem");
    list.Add(c2);
    std::cout << "\n Added a Concept ";

    Concept c3("priorityList",45,"data Structures","Fourth Sem");
    list.Add(c3);
    std::cout << "\n Added a Concept ";

    std::cout << "\n Display All ";
    list.Display_all();

    std::cout << "\n Display Single ";
    list.Display_name("DoubleLinklist");

    std::cout << "\n Get a Random one ";
    Concept random =list.getConcept(2);
    std::cout << std::endl;
    std::cout << "\n Concept Name:"<< random.conceptName;
    std::cout << "\n Time Required :"<< random.timeRequiredToDo;
    std::cout << "\n Other Information :"<< random.otherInformation;
    std::cout << "\n Concept Info :"<< random.conceptInfo;

    return 0;
}