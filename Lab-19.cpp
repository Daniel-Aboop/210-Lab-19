// COMSC-210 | Lab 18 | Daniel Santisteban
// IDE used: VS Code
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct moviedata{
    double rating;
    string comment;
    moviedata* next;
};
void output(moviedata *head);
moviedata * choice2(moviedata *head,double rating,const string& comment);

class Movie{
    private:
    string movietitle;
    moviedata* head = nullptr;

};

int main(){
    vector<Movie> list;


    return 0;
}
moviedata* choice2(moviedata *head,double rating,const string& comment){
    moviedata* newNode = new moviedata{rating,comment,nullptr};
    //if this is the first thing inside of our list it will become the new head.
    if(head==nullptr){
        return newNode;
    }
    moviedata* current = head;
    while(current->next!=nullptr){
        current=current->next;
    }
    current->next=newNode;
    return head;
}