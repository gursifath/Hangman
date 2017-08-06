#include<iostream>
#include<string.h>
#include<time.h>
#include<string>
#include<stdlib.h>
#include<fstream>
using namespace std;

const int maximum_length=80;
const int maximum_tries=5;
const int maximum_rows=12;

char unknown[maximum_length];
char letter,ch,n;
char word[maximum_length];

class hangman
{
    string name;
    int age;

public:
    int wrong_guesses;

    hangman()
    {
        wrong_guesses=0;
    }

    void input();
    int check(char,char[],char[]);
    void code();
    void menu();
    void output();
}obj[50];


///To check whether the entered letter was correct
int hangman::check(char guess,char secretword[],char guessword[])
{
    int i,matches=0;
    for(int i=0;secretword[i]!='\0';i++)
    {
        if(guess==guessword[i])
            return 0;
        if(guess==secretword[i])
        {
            guessword[i]=guess;
            matches++;
        }
    }
    return matches;
}


///to initialize the unknown word
void hangman::code()
{
    int i,length=strlen(word);

    for(i=0;i<length;i++)
    {
        unknown[i]='*';
        unknown[i+1]='\0';
    }
}


void hangman:: menu()
{
    ///loop until guesses are used up
    while(wrong_guesses<maximum_tries)
    {
        ///to initialize the secret word with star character
        cout<<"\n\n"<<unknown<<endl;
        cout<<"\n\nGuess a letter"<<endl;
        cin>>letter;

        ///fill secretword if guess is correct otherwise increment wrong_guesses
        if(check(letter,word,unknown)==0)
        {
            cout<<endl<<"OOPS! SORRY!! Incorrect word chosen. Try Again :( ";
            wrong_guesses++;
        }
        else
        {
            cout<<endl<<"YOU HAVE FOUND A LETTER!! :) "<<endl;
            cout<<"_______________________________";
        }

        ///tell users how many guesses are left
        cout<<"You have "<<maximum_tries-wrong_guesses<<" guesses left ";

        ///Check if guess was correct
        if(strcmp(word,unknown)==0)
        {
            cout<<"\n\n\n\n\n\n\n\nYES YOU GOT IT!";
            cout<<"\n\n\nWord is  "<<word<<endl;
            break;
        }
    }
}

void hangman:: input()
{
    cout<<"\n\nEnter your First Name\n";
    cin>>name;
    cout<<"\nEnter your Age\n";
    cin>>age;
}

void hangman::output()
{
    cout<<"Your Name "<<name<<endl;
    cout<<"Your Age "<<age<<endl;
}


int main()
{
    fstream f("Game.bin",ios::in|ios::out|ios::binary);

    char word1[][maximum_length]=
    {
        "titanic",
        "avengers",
        "xmen",
        "avatar",
        "inception",
        "transformers",
        "spiderman",
        "saw",
        "mirrors",
        "legion"
    };

    char word2[][maximum_length]=
    {
        "honda",
        "hyundai",
        "toyota",
        "mahindra",
        "audi",
        "bentley",
        "mercedes",
        "nissan",
        "hummer",
        "porsche"
    };

    char word3[][maximum_length]=
    {
        "lindt",
        "toblerone",
        "bournville",
        "silk",
        "hersheys",
        "mars",
        "safari",
        "munch",
        "fivestar",
        "perk"
    };

    ///Introduction
    for(int i=0;i<5;i++)
    {
        cout<<"\n\n\n***********************************WELCOME TO HANGMAN**************************************"<<endl;
        obj[i].input();
        f.write((char*)&obj[i],sizeof(obj[i]));

        cout<<"\n\n    Each letter represented by a star '*'"<<endl;
        cout<<"\n\n    You have to type one letter in one try"<<endl;
        cout<<"\n\n    You have "<<maximum_tries<<" tries to try ans guess the word"<<endl;
        cout<<"\n    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  "<<endl;
        cout<<"          Which game do you want to play?"<<endl;
        cout<<"Enter **M** for Movies Game, **C** for Cars Game, **S** for Chocolate Games"<<endl;
        cin>>ch;

        switch(ch)
        {
        case 'M':
                    ///to choose any word randomly
                    srand(time(NULL));
                    n=rand()%10;
                    strcpy(word,word1[n]);
                    obj[i].code();
                    obj[i].menu();
                    break;

        case 'm':
                   ///to choose any word randomly
                    srand(time(NULL));
                    n=rand()%10;
                    strcpy(word,word1[n]);
                    obj[i].code();
                    obj[i].menu();
                    break;

        case 'C':
                   ///to choose any word randomly
                    srand(time(NULL));
                    n=rand()%10;
                    strcpy(word,word2[n]);
                    obj[i].code();
                    obj[i].menu();
                    break;

        case 'c':
                    ///to choose any word randomly
                    srand(time(NULL));
                    n=rand()%10;
                    strcpy(word,word2[n]);
                    obj[i].code();
                    obj[i].menu();
                    break;

        case 'S':

                   ///to choose any word randomly
                    srand(time(NULL));
                    n=rand()%10;
                    strcpy(word,word3[n]);
                    obj[i].code();
                    obj[i].menu();
                    break;

        case 's':

                  ///to choose any word randomly
                    srand(time(NULL));
                    n=rand()%10;
                    strcpy(word,word3[n]);
                    obj[i].code();
                    obj[i].menu();
                    break;

        default: cout<<"    PLEASE ENTER A VALID CHARACTER"<<endl;
        }

        if(obj[i].wrong_guesses==maximum_tries)
        {
            cout<<endl<<"Sorry You Lose "<<endl;
            cout<<"You're HANGED "<<endl;

            if(ch=='m' || ch=='M')
                cout<<"The movie was "<<word<<endl<<":)";
            else if(ch=='c' || ch=='C')
                cout<<"The car was "<<word<<endl<<":)";
            else if(ch=='S'||ch=='s')
                cout<<"The chocolate was "<<word<<endl<<":)";

        }
    }

    for(int j=0;j<5;j++)
    {
        f.read((char*)&obj[j],sizeof(obj[j]));
        obj[j].output();
    }
}
