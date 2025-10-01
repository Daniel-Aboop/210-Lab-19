// COMSC-210 | Lab 19 | Daniel Santisteban
// IDE used: VS Code

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <random>
#include <iomanip>

using namespace std;

struct moviedata{
    double rating;
    string comment;
    moviedata* next;
};
//Linked List Functions
void output(moviedata *head);
moviedata * choice2(moviedata *head,double rating,const string& comment);
//Random Number Function
double randomNumber();

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

const int SIZE=4;


//C:\\Users\\hope4\\Desktop\\COMSC 210 Work\\210-Lab-19\\Text.txt
int main(){
    vector<Movie> list;
    string filepath;
    cout<<"Enter File Path: ";
    getline(cin,filepath);
    ifstream file(filepath);
    if(!file){
		cout<<"error opening file"<<endl;
		return 1;
	}
	else{
		cout<<"file opened"<<endl;
	}
	cout<<endl;

    
    
    for(int i=0;i<SIZE;i++){
        Movie temp;
        string tempname;
        string line,line2,line3;
        getline(file,line);
        getline(file,line2);
        getline(file,line3);

        cout<<"Enter a Movie title: ";
        getline(cin,tempname);
        temp.setmovietitle(tempname);
        temp.setmoviedata(randomNumber(),line);
        temp.setmoviedata(randomNumber(),line2);
        temp.setmoviedata(randomNumber(),line3);
        list.push_back(temp);
    }
    cout<<endl;
    for(int i=0;i<SIZE;i++){
        moviedata* temp;
        string temp1;
        temp=list[i].getmoviedata();
        cout<<list[i].getmovietitle()<<endl;
        output(temp);
        cout<<endl;
    }


    file.close();
    return 0;
}
//Function for random Number
double randomNumber(){
    static mt19937 gen(static_cast<unsigned int>(time(nullptr))); 
    static uniform_real_distribution<double> dis(1.0, 5.0);
    return dis(gen);
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
        cout<<"> Review #"<<count++<<": "<<fixed<<setprecision(1)<< current->rating<<": "<<current->comment<<endl;
        avg+=current->rating;
        
        current = current->next;
    }
    // to find the average it would be 2, so since it loops 1 more time for nullptr i did -1 to make sure its okay for average
    
}
