//The program is 21 points game. In this game, users should try to make his points closer to the 21 while the computer wants to do it also
//Only the one get the points closer but not bigger than 21 wins.
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<string>

using namespace std;

int cards[52];
int Shuffle();
int Show(int);
double Show_sentence(int, int);
double Transfer(int); 
void twenty_one();



int Show(int i )//show the cards 
{
string hua[4] = {"Hearts", "Spade" , "Club" , "Diamond"};
string num[13] =  {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int a = i % 13 ;  // num 
int b = i / 13 ; // hua
cout<<hua[b]<<'\0'<<num[a]<<'\0'; 
}


int Shuffle()// Ï´ÅÆ 
{
for( int i = 0 ; i < 52 ; ++i )
	cards [i] = i ; 
srand(time(NULL));
random_shuffle(cards, cards + 52 );
return cards[52];
}


double Show_sentence(int card_num,int n )//output the cards
{
int i , m ;
double sum_p = 0 , r_num; 
for(i = n ; i < card_num ; ++i)
	{
	m = cards[i];
	r_num = Transfer(m);
	sum_p += r_num;
	Show(m);
	}
cout<<endl;
return sum_p;
}



double Transfer(int i )// match the cards with the porints 
{
string num[13] =  {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
double r_num[13] = {1,2,3,4,5,6,7,8,9,10,0.5,0.5,0.5};
int a = i % 13 ;  // num
return r_num[a];
}



void twenty_one()
{
Shuffle();	//shuffle the cards, which means make the elements out of order
cout<<"Player's Round'"<<endl; 
cout<<"Player's Cards'"<<'\0';
int card_num , m ; //card_num:the ordinal number , m:number with certain ordinal number 
double sum_p = 0;
sum_p = Show_sentence(2,0);
char flag_card;	
cout<<"Whether to continue?(y/n):"<<endl;
cin>> flag_card;

card_num = 2;
while(flag_card == 'y')
	{
	++card_num;	
	cout<<"Continue£º"; 
	sum_p = Show_sentence(card_num,0);
	if (sum_p <= 21)
		{
		cout<<"Whether to continue?(y/n):"<<endl;
		cin>> flag_card;
		}
	else 
		{
		cout<<"Player Loses"<<endl;
		break;
		}
	}

if(sum_p <= 21 ) 
	{
	cout<<"Computer's Round'"<<endl;
	cout<<"Computer's Cards'"<<'\0';
	int card_num_c , m_c ;
	double sum_p_c = 0;
	sum_p_c = Show_sentence(23,21);
	
	card_num_c = 23;
	int t1 = card_num - 0, t2 = card_num_c - 21;
	while(sum_p_c < sum_p )
	{
		++card_num_c;	
		cout<<"Continue£º"; 
		sum_p_c = Show_sentence(card_num_c,21);
		if (sum_p_c>21)
			{
			cout<<"Player Wins"<<endl;
			break;
			}
		else 
		{
			if(sum_p_c==sum_p)
			{
				if (t1 < t2) 
				{
					cout<<"Player Loses"<<endl;
					break;
				}
				else
				{
					if(t1 == t2) 
					{
						cout<<"Draw"<<endl;
						break;
					}
					else 
					{
						cout<<"Player Wins"<<endl;
						break;
					}
			 	} 

			}
		}
	}
	if (sum_p_c > sum_p && sum_p_c<21 ) cout<< "Player Loses"<<endl;
	//cout<<sum_p_c<<'\0'<<sum_p<<endl;
	//cout<<t1<<'\0'<<t2<<endl; 
	}
}

int main()
{	
	char flag;
	do
	{
		twenty_one();
		cout<<"Whether to continue?(y/n):"<<endl;
		cin>>flag;
	}
	while(flag=='y');
	return 0;
}
