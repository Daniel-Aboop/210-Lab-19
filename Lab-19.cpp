// COMSC-210 | Lab 19 | Daniel Santisteban
// IDE used: VS Code

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <random>
#include <ctime>
#include <iomanip>

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
    public:
    void setmovietitle(string title){
        this->movietitle=title;
    }
    void setmoviedata(double rating,string comment){
        this->head=choice2(head,rating,comment);
    }
    string getmovietitle(){
        return this->movietitle;
    }
    moviedata* getmoviedata(){
        return this->head;
    }
};

int main(){
    srand(time(0));
    ifstream file("C:\\Users\\hope4\\Desktop\\COMSC 210 Work\\210-Lab-19\\Text.txt");
    if(!file){
		cout<<"error opening file"<<endl;
		return 1;
	}
	else{
		cout<<"file opened"<<endl;
	}
	cout<<endl;


    vector<Movie> list;
    string line;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(1.0, 5.0);
    
    
    while(getline(file,line)){
        cout<<fixed << setprecision(1)<<dis(gen)<<endl;
    }
    cout<<"some shit man"<<endl;
    



    return 0;
    file.close();
}

//Functions for linked list.
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
void output(moviedata * head){
    if(!head){
        cout<<"Empty list.\n";
        return;
    }
    int count = 1;
    double avg=0;
    moviedata * current = head;
    cout<<"Outputting all reviews:"<<endl;
    while (current) {
        cout<<"> Review #"<<count++<<": "<< current->rating<<": "<<current->comment<<endl;
        avg+=current->rating;
        
        current = current->next;
    }
    // to find the average it would be 2, so since it loops 1 more time for nullptr i did -1 to make sure its okay for average
    cout<<"> Average: "<<avg/(count-1)<<endl;
}
