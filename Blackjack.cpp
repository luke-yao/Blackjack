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


int Show(int i )//显示牌号 
{
string hua[4] = {"红桃", "黑桃" , "梅花" , "方块"};
string num[13] =  {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int a = i % 13 ;  // num 
int b = i / 13 ; // hua
cout<<hua[b]<<num[a]<<'\0'; 
}


int Shuffle()// 洗牌 
{
for( int i = 0 ; i < 52 ; ++i )
	cards [i] = i ; 
srand(time(NULL));
random_shuffle(cards, cards + 52 );
return cards[52];
}


double Show_sentence(int card_num,int n )//输出玩家所获得牌&计算 
{
int i , m ;//r_num 实际数字
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



double Transfer(int i )//牌转化为所对应的分值 
{
string num[13] =  {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
double r_num[13] = {1,2,3,4,5,6,7,8,9,10,0.5,0.5,0.5};
int a = i % 13 ;  // num
return r_num[a];
}



void twenty_one()
{
Shuffle();	//洗牌 乱序排列一个数组 
cout<<"玩家阶段"<<endl; 
cout<<"玩家获得牌"<<'\0';
int card_num , m ; //card_num 牌序 , m 所对应的数组中数 
double sum_p = 0;
sum_p = Show_sentence(2,0);
char flag_card;	
cout<<"是否继续要牌(y/n):"<<endl;
cin>> flag_card;

card_num = 2;
while(flag_card == 'y')
	{
	++card_num;	
	cout<<"继续要一张牌："; 
	sum_p = Show_sentence(card_num,0);
	if (sum_p <= 21)
		{
		cout<<"是否继续要牌(y/n):"<<endl;
		cin>> flag_card;
		}
	else 
		{
		cout<<"玩家输了"<<endl;
		break;
		}
	}

if(sum_p <= 21 ) 
	{
	cout<<"电脑阶段"<<endl;
	cout<<"电脑获得牌"<<'\0';
	int card_num_c , m_c ;
	double sum_p_c = 0;
	sum_p_c = Show_sentence(23,21);
	
	card_num_c = 23;
	int t1 = card_num - 0, t2 = card_num_c - 21;
	while(sum_p_c < sum_p )
	{
		++card_num_c;	
		cout<<"继续要一张牌："; 
		sum_p_c = Show_sentence(card_num_c,21);
		if (sum_p_c>21)
			{
			cout<<"玩家赢了"<<endl;
			break;
			}
		else 
		{
			if(sum_p_c==sum_p)
			{
				if (t1 < t2) 
				{
					cout<<"玩家输了"<<endl;
					break;
				}
				else
				{
					if(t1 == t2) 
					{
						cout<<"平局"<<endl;
						break;
					}
					else 
					{
						cout<<"玩家赢了"<<endl;
						break;
					}
			 	} 

			}
		}
	}
	if (sum_p_c > sum_p && sum_p_c<21 ) cout<< "玩家输了"<<endl;
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
		cout<<"是否继续(y/n):"<<endl;
		cin>>flag;
	}
	while(flag=='y');
	return 0;
}
