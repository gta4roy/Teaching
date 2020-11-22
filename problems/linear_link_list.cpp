#include <iostream>
using namespace std;

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

    void printData(){
        std::cout << "\n---- Concepts Details -----";
        std::cout << "\t Concept Name :"<< this->conceptName;
        std::cout << "\t TimeRequiredToDo :"<< this->timeRequiredToDo;
        std::cout << "\t OtherInfomation :"<< this->otherInformation;
        std::cout << "\t Concept Info :"<< this->conceptInfo;
    }
};

struct LinkList {
    Concept * conceptData;
    LinkList * next;
};

void addNodeAtEnd(LinkList ** startNodeAddress, Concept * conceptData){

    if ( *startNodeAddress == NULL){
        //create First Node 
       LinkList * firstNode = new LinkList();
       firstNode->conceptData = conceptData;
       firstNode->next = NULL;
       *startNodeAddress = firstNode;
    } else {
        //find the end node 
        LinkList * temp = *startNodeAddress;
        while (temp->next != NULL){
            temp= temp->next;
        }

        LinkList * endNode = new LinkList();
        endNode ->conceptData = conceptData;
        endNode -> next = NULL;
        temp ->next = endNode;
    }
}

void addNodeAtMiddle(LinkList ** startNodeAddress, Concept * conceptData,int pos){
    //check if the linkllist is completely empty add the node in begining 

    if (*startNodeAddress == NULL){
        addNodeAtEnd(startNodeAddress,conceptData);
    }else {
        //if the index is 0th want to add in the begining 
        if(pos == 0){
            //Linklist has to be added in the starting 
            LinkList * firstNode = new LinkList();
            firstNode->conceptData = conceptData;
            firstNode->next = *startNodeAddress;
            *startNodeAddress = firstNode;
            //shifting the first node 
        }else {
            //loop in the list to find the correct position to add the node 
            LinkList * temp = *startNodeAddress;
            LinkList * prev = NULL;
            int i = 0;
            while(temp->next != NULL){
                if (i == pos){
                    break;
                }else {
                    prev = temp;
                    temp = temp->next;
                }
            }
            //If we reach end of the node then add in the end 
            if(temp->next == NULL){
                LinkList * newNode = new LinkList();
                newNode ->conceptData = conceptData;
                newNode ->next = NULL;
                temp->next = newNode; // Add the node in the end 
            }else {
                LinkList * newNode = new LinkList();
                newNode ->conceptData = conceptData;
                newNode ->next = prev ->next;
                prev ->next = newNode;
                //shifting and inserting in the middle;
            }
        }
    }
}

void deleteANode(LinkList ** startNodeAddress,char conceptName[]){
    int index = 0;
    LinkList * temp = *startNodeAddress;
    LinkList * prev = NULL;
    while(temp->next != NULL){
        if (strcmp(temp->conceptData->conceptName,conceptName) == 0){
            break;
        }
        prev = temp;
        temp = temp->next;
        index ++;
    }
    if (prev == NULL){
        //first node to be deleted 
        *startNodeAddress = temp->next;
        delete(temp);

    }else if (temp ->next == NULL){  //last node
        prev->next = NULL;
        delete(temp);
    }else {
        prev ->next = temp->next; 
        delete(temp);
    }   
}

bool searchANode (LinkList ** startNodeAddress,char conceptName[]){
   
    LinkList * temp = *startNodeAddress;
    bool ifFound = false;
    while(temp->next != NULL){
        if (strcmp(temp->conceptData->conceptName,conceptName) == 0){
            ifFound = true;
            break;
        }
        temp = temp->next;      
    }
    return ifFound;
}

void displayAllNodes(LinkList ** startNodeAddress){
    LinkList * temp = *startNodeAddress;
    while(temp != NULL){
        /* code */
        temp->conceptData->printData();
        temp= temp->next;
    }  
}

Concept * askUserForTheConceptDetails(){
    Concept * conceptInfo = NULL;
    conceptInfo = new Concept(); 
    std::cout << "\n Please enter Concept Name :";
    conceptInfo->conceptName = new char[40];
    std::cin >> conceptInfo->conceptName;

    std::cout << "\n Please enter Concept Time Required :";
    std::cin >> conceptInfo->timeRequiredToDo;

    std::cout << "\n Please Provide Other Info :";
    conceptInfo->otherInformation = new char[40];
    std::cin >> conceptInfo->otherInformation;

    std::cout << "\n Please Provide concept info :";
    conceptInfo->conceptInfo = new char[40];
    std::cin >> conceptInfo->conceptInfo;

    return conceptInfo;
}


int main(){

    LinkList * startPointer = NULL;

    //add an element 
    Concept * element = askUserForTheConceptDetails();
    addNodeAtEnd(&startPointer,element);
 
    //add an element 
    Concept * element1 = askUserForTheConceptDetails();
    addNodeAtEnd(&startPointer,element1);

    //add an element 
    Concept * element2 = askUserForTheConceptDetails();
    addNodeAtEnd(&startPointer,element2);

    displayAllNodes(&startPointer);

    //0 1 2 3 ...
    //add node in 0th position
    std::cout << "\n Adding element in the 0th Pos";
    Concept * element3 = askUserForTheConceptDetails();
    addNodeAtMiddle(&startPointer,element3,0);
    displayAllNodes(&startPointer);

    //add node in 1st position
     std::cout << "\n Adding element in the 1th Pos";
    Concept * element4 = askUserForTheConceptDetails();
    addNodeAtMiddle(&startPointer,element4,1);
    displayAllNodes(&startPointer);

     //add node in 5th position
     std::cout << "\n Adding element in the 5th Pos";
    Concept * element5 = askUserForTheConceptDetails();
    addNodeAtMiddle(&startPointer,element5,5);

    displayAllNodes(&startPointer);

    //search a node 
    std::cout << "\n Please Enter a Concept name to be searched :....";
    char conceptNameToSearch[40];
    std::cin >> conceptNameToSearch;

    if (searchANode(&startPointer,conceptNameToSearch)){
        std::cout << "Node has been found Hurray .....";
    }else {
        std::cout << "Not able to find the Node Ooops.....";
    }

    displayAllNodes(&startPointer);
    //deleting a node 

    std::cout << "\n Please enter a Concept name to be deleted ...";
    char conceptNameToBeDeleted[40];
    std::cin >> conceptNameToBeDeleted;
    deleteANode(&startPointer,conceptNameToBeDeleted);

    displayAllNodes(&startPointer);
    return 0;
}