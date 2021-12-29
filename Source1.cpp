#include<iostream>
using namespace std;
int total;
class Player {
	string name;
	int battingscore;
	int ballscore;
	int wickets;
	int balls;
	int sixshot;
	int foursshot;
	int dottedshot;
	int ballsix;
	int ballfour;
	int balldotted;
	int status;
	int ballingscore;
	int extraball;
public:
	Player()
	{
		name = "";
		battingscore = 0;
		wickets = 0;
		balls = 0;
		status = 0;
		sixshot = 0;
		foursshot = 0;
		dottedshot = 0;
		ballingscore = 0;
		extraball = 0;
	}
	string Getname()
	{
		return name;
	}
	void increase_extras()
	{
		extraball++;
	}
	int score()
	{
		return battingscore;
	}
	int getwickets()
	{
		return wickets;
	}
	void increase_balls()
	{
		balls++;
	}
	void increase_balling_score(int s)
	{
		ballingscore = ballingscore + s;
	}
	int Getballs()
	{
		return balls;
	}
	void setname(string n)
	{
		name = n;
	}
	void increase_score(int s)
	{
		battingscore=battingscore+s;
	}
	void increase_six()
	{
		sixshot++;
	}
	void increase_wickets()
	{
		wickets++;
	}
	
	int getstatus()
	{
		return status;
	}
	void setstatus(int i)
	{
		status = i;
	}
	void increase_fourshot()
	{
		foursshot++;
	}
	void increase_dottedShot()
	{
		dottedshot++;
	}
	void increase_balling_six()
	{
		ballsix++;
	}
	void increase_balling_four()
	{
		ballfour++;
	}
	void increase_balling_dotted()
	{
		balldotted++;
	}

	friend ostream& operator<<(ostream &ou, const Player obj)
	{
		ou << "Player Name: " << obj.name << " score: " << obj.battingscore << "  wickets: " << obj.wickets << " Balls:  " << obj.balls << endl;
		ou<<"BatsmanSixes: "<<obj.sixshot<<"Batsmanfour"<<obj.foursshot<<endl;
		return ou;
	}
};
class Team {
	Player arr[12];
	string name;
	int status;
public:
	Team()
	{
		status = 0;
	}
	void setTeamName(string n)
	{
		name = n;
	}
	void Setteam()
	{
		for (int i = 0; i < total; i++)
		{
			cout << "Enter: " << i + 1 << " Player Name";
			string x;
			cin >> x;
			arr[i].setname(x);

		}
	}
	void PrintDetails()
	{
		for (int i = 0; i < total; i++)
		{
			cout<<arr[i];
		}
	}
	void setballs(int i)
	{
		arr[i].increase_balls();
	}
	void Setscore(int index,int score)
	{
		arr[index].increase_score(score);
		if (score == 6)
		{
			arr[index].increase_six();
		}
		if (score == 0)
		{
			arr[index].increase_dottedShot();
		}
		if (score == 4)
		{
			arr[index].increase_fourshot();
		}
	}
	int getStatus()
	{
		return status;
	}
	void setstatus(int s)
	{
		status = s;
	}
	void setBollingScore(int index,int score)
	{
		arr[index].increase_balling_score(score);
		if (score == 0)
		{
			arr[index].increase_balling_dotted();
		}
		if (score == 4)
		{
			arr[index].increase_balling_four();
		}
		if (score == 6)
		{
			arr[index].increase_balling_six();
		}
	}
	void increase_extra(int index)
	{
		arr[index].increase_extras();
		arr[index].increase_balling_score(1);
	}

	string getName()
	{
		return name;
	}
	int getPlayerStatus(int i)
	{
		return arr[i].getstatus();
	}
	void setPlayerStatus(int i,int s)
	{
		arr[i].setstatus(s);
	}
	int getTeamScore()
	{
		int sum = 0;
		for (int i = 0; i < total; i++)
		{
			sum = sum + arr[i].score();
		}
		return sum;
	}
	void setwicket(int i)
	{
		arr[i].increase_wickets();
	}
	
	

};
class Play {
	Team obj1;
	Team obj2;
public:
	Play()
	{
		cout << "Constructor called" << endl;
	}
	void calculations()
	{
		cout << "Enter Total Number of Players in One team: ";
		cin >> total;
		cout << "Enter 1st Team details: " << endl;
		cout << "Enter Name of 1st team: ";
		string s;
		cin >> s;
		obj1.setTeamName(s);
		obj1.Setteam();
		system("cls");
		cout << "Enter 2nd Team details: " << endl;
		cout << "Enter Name of 2nd team: ";
		cin >> s;
		obj2.setTeamName(s);
		obj2.Setteam();
		
		system("cls");
		obj1.PrintDetails();
		cout << endl;
		obj2.PrintDetails();
		cout << endl;
		int overs;
		int balls;
		cout << "Enter Total Overs: ";
		cin >> overs;
		balls = overs * 6;
		cout << endl;
		cout << "Who is Playing First" << endl << "Press 1 for team: " << obj1.getName() << endl;
		cout << "Press 2 for team: " << obj2.getName() << endl;
		int selector;
		while (true)
		{
			cin >> selector;
			if (selector == 1)
			{
				cout << "Press 1 for balling OR press 2 for batting: ";
				int select;
				cin >> select;
				if (select == 1)
				{
					obj1.setstatus(1);    //status 1 is for batting
					break;
				}
				else
				{
					obj1.setstatus(2);	//status 2 is for balling
					break;
				}

			}
			else if (selector == 2)
			{
				cout << "Press 1 for balling OR press 2 for batting: ";
				int select;
				cin >> select;
				if (select == 1)
				{
					obj2.setstatus(1);    //status 1 is for batting
					break;
				}
				else
				{
					obj2.setstatus(2);	//status 2 is for balling
					break;
				}
			}
			else
			{
				cout << "Enter A valid Number";
			}
		}
		int flag=0;

		while (flag < 2)
		{
			int x = 0;
			int y = 1;
			
			int bowler_index = 0;
			int Bat_index = 0;
			int O = 0;
			int striker = x;
			if (obj1.getStatus() == 2 || obj2.getStatus()==1)  //balling
			{
				cout << "Team 2 batting " << endl;
				for (int i = 0; i < balls; i++)
				{
				
					obj2.setPlayerStatus(x,1);
					obj2.setPlayerStatus(y, 2);
					int h;
					cout << "Press 1 for normal Delivery: " << endl;
					cout << "Press 2 for Invalid Delivery: " << endl;
					cout << "Press 3 for wicket:" << endl;
					cin >> h;
					
					if (h == 1)
					{
						if (i % 6 == 0)
						{
							bowler_index++;
							if (striker == x)
							{
								striker == y;
							}
							if (striker == y)
							{
								striker == x;
							}

						}
						if (bowler_index % total == 0)
						{
							bowler_index = 0;
						}
						obj1.setballs(bowler_index);
						cout << "Enter Score";
						int s;
						cin >> s;
						obj1.setBollingScore(bowler_index, s);
						obj2.Setscore(striker, s);
						if (s == 1)
						{
							if (striker == x)
							{
								striker == y;
							}
							if (striker == y)
							{
								striker == x;
							}
						}
						
					}
					if (h == 2)
					{
						obj2.Setscore(striker, 1);
						obj1.increase_extra(bowler_index);
					}
					if (h == 3)
					{
						obj1.setwicket(bowler_index);
						x = y + 1;
						if (x > total)
						{
							break;
						}
						striker = x;
						swap(x, y);

					}
					system("cls");
					cout << "Score: " << obj2.getTeamScore() << endl;
					
				}
				obj1.setstatus(1);
				obj2.setstatus(2);
				
			}
			else if (obj1.getStatus() == 1 || obj2.getStatus() == 2)  //batting of team 1
			{
				cout << "Team 1 batting" << endl;
				for (int i = 0; i < balls; i++)
				{

					obj1.setPlayerStatus(x, 1);
					obj1.setPlayerStatus(y, 2);
					int h;
					cout << "Press 1 for normal Delivery: " << endl;
					cout << "Press 2 for Invalid Delivery: " << endl;
					cout << "Press 3 for wicket:" << endl;
					cin >> h;

					if (h == 1)
					{
						if (i % 6 == 0)
						{
							bowler_index++;
							if (striker == x)
							{
								striker == y;
							}
							if (striker == y)
							{
								striker == x;
							}

						}
						if (bowler_index % total == 0)
						{
							bowler_index = 0;
						}
						obj2.setballs(bowler_index);
						cout << "Enter Score";
						int s=0;
						cin >> s;
						obj2.setBollingScore(bowler_index, s);
						obj1.Setscore(striker, s);
						if (s == 1)
						{
							if (striker == x)
							{
								striker == y;
							}
							if (striker == y)
							{
								striker == x;
							}
						}
					}
					if (h == 2)
					{
						obj1.Setscore(striker, 1);
						obj2.increase_extra(bowler_index);
					}
					if (h == 3)
					{
						obj2.setwicket(bowler_index);
						x = y + 1;
						
						if (x > total)
						{
							break;
						}
						striker = x;
						swap(x, y);
					}
					system("cls");
					cout << "Score: " << obj1.getTeamScore() << endl;
				}
				obj1.setstatus(2);
				obj2.setstatus(1);

			}
			flag++;
		}
		obj1.PrintDetails();
		obj2.PrintDetails();
	}
};
int main()
{
	Play obj;
	obj.calculations();
	system("pause");
	return 0;
}
