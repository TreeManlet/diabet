#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//  keeps track of players stats and max stats.
int Health{ 100 };
int Weight{ 95 };
int Hunger{ 100 };
int Anger{ 100 };
int Strength{ 100 };
int Stamina{ 100 };
int Money{ 100 };
int CurrentTime{ 24 };
int MaxTime{ 24 };
int MaxHunger{ 100 };
int MaxStamina{ 200 };
// keeps track of how much bonus money you get
int n{ 20 };
// keeps track of what actions can be preformed, 0 = cant 1 = can
int valid[8] = { 1,1,1,1,1,1,1,1 };
// keeps track of date
int day{ 1 };
int month{ 1 };
//food arrays
string foodname[8] = { "Sandra's Cooking","Adrian's Cooking","Rain","Redvines","Flying Saucers","Megabox","Mcdonald's Brekfast","Half Grilled Chicken Meal" };
int availible[8] = { 0,0,0,0,0,0,0,0 };
int cost[8] = { 0,0,2,5,10,5,10,7 };
int nurishment[8] = { 30,15,1,1,1,20,20,30 };
string bonus[8] = { "Strength -5","Anger +40","Stamina +10, Anger +20","Weight +5, Anger -5","Weight +15","Weight +10","Weight +30" };
int caneat[8] = { 0,0,0,0,0,0,0,0 };
//function to clear the screen
void ClearScreen()
{
    cout << string(100, '\n');
};


// responsible for printing stats
void printstats()
{
    cout << "Health:" << Health << endl;
    cout << "Weight:" << Weight << "KG" << endl;
    cout << "Hunger:" << Hunger << "/" << MaxHunger << endl;
    cout << "Anger:" << Anger << endl;
    cout << "Strength:" << Strength << endl;
    cout << "Stamina:" << Stamina << "/" << MaxStamina << endl;
    cout << "Money:" << Money << endl;
    cout << "Day:" << day << "|| Month:" << month << "|| Time:" << CurrentTime << "/" << MaxTime << endl;
}



//actions

//eat
void eat()
{
    int i;
    // checks for avalible foods to eat
    for (int i = 0; i < 7; i++)
    {
        if (availible[i] > 0)
        {
            cout << "Press:" << i << " to eat " << foodname[i] << "  ||  Hunger restored:" << nurishment[i] << "  ||  Bonus:" << bonus[i] << endl;
        }
    }


    // asks for input for which food to eat
    int f;
    cin >> f;
    switch (f)
    {
    case 0:
        if (f == 0 && availible[0] > 0)
        {
            cout << "you ate:  " << foodname[0] << endl;
            Hunger += 30;
            Strength -= 5;
            availible[0] -= 1;
        }
    case 1:
        if (f == 1 && availible[1] > 0)
        {
            cout << "you ate:  " << foodname[1] << endl;
            Hunger += 15;
            Anger += 40;
            availible[1] -= 1;
        }
    case 2:
        if (f == 2 && availible[2] > 0)
        {
            cout << "you ate:  " << foodname[2] << endl;
            Hunger += 1;
            Stamina += 10;
            availible[2] -= 1;
        }
    case 3:
        if (f == 3 && availible[3] > 0)
        {
            cout << "you ate:  " << foodname[3] << endl;
            Hunger += 1;
            Anger += 20;
            availible[3] -= 1;
        }
    case 4:
        if (f == 4 && availible[4] > 0)
        {
            cout << "you ate:  " << foodname[4] << endl;
            Hunger += 1;
            Weight += 5;
            availible[4] -= 1;
        }
    case 5:
        if (f == 5 && availible[5] > 0)
        {
            cout << "you ate:  " << foodname[5] << endl;
            Hunger += 20;
            Anger -= -5;
            availible[5] -= 1;
        }
    case 6:
        if (f == 6 && availible[6] > 0)
        {
            cout << "you ate:  " << foodname[6] << endl;
            Hunger += 20;
            Weight += 15;
            availible[6] -= 1;
        }
    case 7:
        if (f == 7 && availible[7] > 0)
        {
            cout << "you ate:  " << foodname[7] << endl;
            Hunger += 30;
            Weight += 30;
            availible[7] -= 1;
        }
    }

}

//buy
void buy()
{
    for (int i = 0; i < 7; i++)
    {
        cout << "Press" << i << " to buy" << foodname[i] << "  ||  Hunger restored:" << nurishment[i] << "  ||  Price:" << cost[i] << endl;
    }

    int f;
    cin >> f;
    switch (f)
    {
    case 0:
        if (f == 0 && Money > 0)
        {
            cout << "you bought:  " << foodname[0] << endl;
        }
    case 1:
        if (f == 1 && Money > 0)
        {
            cout << "you bought:  " << foodname[1] << endl;
        }
    case 2:
        if (f == 2 && Money > 2)
        {
            cout << "you bought:  " << foodname[2] << endl;
            Money -= 2;
        }
    case 3:
        if (f == 3 && Money > 5)
        {
            cout << "you bought:  " << foodname[3] << endl;
            Money -= 5;
        }
    case 4:
        if (f == 4 && Money > 10)
        {
            cout << "you bought:  " << foodname[4] << endl;
            Money -= 10;
        }
    case 5:
        if (f == 5 && Money > 5)
        {
            cout << "you bought:  " << foodname[5] << endl;
            Money -= 5;
        }
    case 6:
        if (f == 6 && Money > 10)
        {
            cout << "you bought:  " << foodname[6] << endl;
            Money -= 10;
        }
    case 7:
        if (f == 7 && Money > 7)
        {
            cout << "you bought:  " << foodname[7] << endl;
            Money -= 7;
        }
    }
}

//work
void work()
{
    ClearScreen();
    Hunger -= 30;
    Anger += 10;
    Stamina -= 50;
    Money += n;
    CurrentTime -= 8;
    printstats();
}


//train
void train()
{
    ClearScreen();
    Health += 10;
    Weight -= 5;
    Hunger -= 40;
    Anger -= 10;
    Strength += 10;
    Stamina += 5;
    CurrentTime -= 4;
}


//play leauge
void leauge()
{
    ClearScreen();
    Weight += 10;
    Hunger -= 20;
    Anger += 90;
    Stamina -= 20;
    CurrentTime -= 1;
    printstats();
}


//read
void read()
{
    n += 5;
    CurrentTime -= 1;
}


//make fun of dylan
void dylanjoke()
{
    cout << "haha dylan haha!" << endl;
}



//drink
void drink()
{
    ClearScreen();
    Health -= 20;
    Weight += 10;
    Hunger -= 40;
    Anger += 50;
    Stamina -= 50;
    Money -= 20;
    CurrentTime -= 12;
    printstats();
}

// sleep
void sleep()
{
    if (Stamina > 60)
    {
        Health += 5;
    };
    if (Hunger > 50)
    {
        Weight += 10;
    }
    if (Weight < 90)
    {
        MaxStamina += 5;
    }
    if (Anger > 30)
    {
        Health - 10;
    }

    Hunger = MaxHunger;
    Anger = 0;
    Stamina = MaxStamina;

    day = +1;
    CurrentTime = MaxTime;

    valid[2] = 1;
    valid[3] = 1;
    valid[4] = 1;
    valid[5] = 1;
    valid[6] = 1;
    valid[7] = 1;

    if (day == 31)
    {
        cout << "winner winner chicken diner. sike diabetus" << endl;
    };
}

// checks the valid array to see what actions can be preformed and prints them
void checkvalid()
{
    for (int i = 0; i < 1; i++)
    {
        if (valid[0] == 1)
        {
            cout << "press 1 to eat" << endl;
        };
        if (valid[1] == 1)
        {
            cout << "press 2 to buy food" << endl;
        };
        if (valid[2] == 1)
        {
            cout << "press 3 to work" << endl;
        };
        if (valid[3] == 1)
        {
            cout << "press 4 to train" << endl;
        };
        if (valid[4] == 1)
        {
            cout << "press 5 to play leauge" << endl;
        };
        if (valid[5] == 1)
        {
            cout << "press 6 to read" << endl;
        };
        if (valid[6] == 1)
        {
            cout << "press 7 to make fun of dylan" << endl;
        };
        if (valid[7] == 1)
        {
            cout << "press 8 to drink" << endl;
        };
        if (valid[8] == 1)
        {
            cout << "press 9 to sleep" << endl;
        };
    }
    int a = 0;
    cin >> a;
    switch (a)
    {
    case 1:
        if (a == 1)
        {
            eat();
        }
    case 2:
        if (a == 2)
        {
            buy();
        }
    case 3:
        if (a == 3)
        {
            work();
            valid[2] = 0;
        }
    case 4:
        if (a == 4)
        {
            train();
            valid[3] = 0;
        }
    case 5:
        if (a == 5)
        {
            leauge();
            valid[4] = 0;
        }
    case 6:
        if (a == 6)
        {
            read();
            valid[5] = 0;
        }
    case 7:
        if (a == 7)
        {
            dylanjoke();
            valid[6] = 0;
        }
    case 8:
        if (a == 8)
        {
            drink();
            valid[7] = 0;
        }
    case 9:
        if (a == 9)
        {
            sleep();
        }
    }
}

//main loop
int main()
{
    bool running = true;
    int a;
    while (running == true)
    {
        printstats();
        checkvalid();
        ClearScreen();
        if (CurrentTime == 0)
        {
            cout << "you didint sleep so you died" << endl;
            running = false;
            cin >> a;
        };
    }
    return 0;
}