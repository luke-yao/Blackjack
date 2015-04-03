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


int Show(int i )//��ʾ�ƺ� 
{
string hua[4] = {"����", "����" , "÷��" , "����"};
string num[13] =  {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int a = i % 13 ;  // num 
int b = i / 13 ; // hua
cout<<hua[b]<<num[a]<<'\0'; 
}


int Shuffle()// ϴ�� 
{
for( int i = 0 ; i < 52 ; ++i )
	cards [i] = i ; 
srand(time(NULL));
random_shuffle(cards, cards + 52 );
return cards[52];
}


double Show_sentence(int card_num,int n )//�������������&���� 
{
int i , m ;//r_num ʵ������
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



double Transfer(int i )//��ת��Ϊ����Ӧ�ķ�ֵ 
{
string num[13] =  {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
double r_num[13] = {1,2,3,4,5,6,7,8,9,10,0.5,0.5,0.5};
int a = i % 13 ;  // num
return r_num[a];
}



void twenty_one()
{
Shuffle();	//ϴ�� ��������һ������ 
cout<<"��ҽ׶�"<<endl; 
cout<<"��һ����"<<'\0';
int card_num , m ; //card_num ���� , m ����Ӧ���������� 
double sum_p = 0;
sum_p = Show_sentence(2,0);
char flag_card;	
cout<<"�Ƿ����Ҫ��(y/n):"<<endl;
cin>> flag_card;

card_num = 2;
while(flag_card == 'y')
	{
	++card_num;	
	cout<<"����Ҫһ���ƣ�"; 
	sum_p = Show_sentence(card_num,0);
	if (sum_p <= 21)
		{
		cout<<"�Ƿ����Ҫ��(y/n):"<<endl;
		cin>> flag_card;
		}
	else 
		{
		cout<<"�������"<<endl;
		break;
		}
	}

if(sum_p <= 21 ) 
	{
	cout<<"���Խ׶�"<<endl;
	cout<<"���Ի����"<<'\0';
	int card_num_c , m_c ;
	double sum_p_c = 0;
	sum_p_c = Show_sentence(23,21);
	
	card_num_c = 23;
	int t1 = card_num - 0, t2 = card_num_c - 21;
	while(sum_p_c < sum_p )
	{
		++card_num_c;	
		cout<<"����Ҫһ���ƣ�"; 
		sum_p_c = Show_sentence(card_num_c,21);
		if (sum_p_c>21)
			{
			cout<<"���Ӯ��"<<endl;
			break;
			}
		else 
		{
			if(sum_p_c==sum_p)
			{
				if (t1 < t2) 
				{
					cout<<"�������"<<endl;
					break;
				}
				else
				{
					if(t1 == t2) 
					{
						cout<<"ƽ��"<<endl;
						break;
					}
					else 
					{
						cout<<"���Ӯ��"<<endl;
						break;
					}
			 	} 

			}
		}
	}
	if (sum_p_c > sum_p && sum_p_c<21 ) cout<< "�������"<<endl;
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
		cout<<"�Ƿ����(y/n):"<<endl;
		cin>>flag;
	}
	while(flag=='y');
	return 0;
}
