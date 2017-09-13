#include "inlcudes.h"

class Player
{
private:
    int numberOfGoals{};
public:
    Player(string name) : name{name} {}
    string name;
//    signal<void(Player*)> Scores;
    signal<void(string, int)> Scores;

    void Gol(){
        ++numberOfGoals;
//        Scores(this);
        Scores(name, numberOfGoals);
    }

    getGol(){
        return numberOfGoals;
    }
};

class Coach
{
public:
    void PlayerScored(string name, int wynik){
        cout <<" well donek,2 " << name << " " << wynik << endl;
    }
} coach;

void BylyPlayer(string name, int wynik){
    cout <<" byly " << name << " " << wynik << endl;
}

int main()
{
    Player p("John");
    cout << "hej siup" << endl;
    auto baka {BylyPlayer};
    auto faka {boost::bind(&Coach::PlayerScored, &coach, _1, _2)};
    auto saka {[](string name, int wynik){cout <<" lambda " << name << " " << wynik << endl <<endl;}};

    p.Scores.connect(2, faka);
    p.Scores.connect(1, baka);
    p.Scores.connect(3, saka);

    p.Gol();
    p.Gol();
    p.Scores("dope mam", 12);
    p.Gol();
    p.Gol();

    return 0;
}


    //    auto dodawanie = std::bind(&Test::add, test, _2, 51, _1);
    //    std::cout << dodawanie(15,22,31) << '\n';



        //cout << run(dodawanie) << endl;
        //    cout << add(1, 2, 3) << endl;
//    p.Gol();
//    p.Gol();

//    auto w{
//        p.Scores.connect( 1,
//        [](Player* pa){cout << "brawo labmda " << pa->name << " Wynik: " << pa->getGol() << endl;})
//    };
//    p.Gol();


//class Test
//{
//public:
//    Test() {}

//int add (int a, int b, int c){
//    std::cout << a << ", " << b << ". " << c << '\n';
//    return a+b+c;
//}
//}test;
//int run(function<int (int, int) > func){
//    return func(31, 14);
//}
