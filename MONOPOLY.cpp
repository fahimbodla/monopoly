
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <fstream>
	using namespace std;
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
class name
{
private:
	char *fname;
	char *lname;
	char *oname;
public:
	name()
	{
		fname = nullptr;
		lname = nullptr;
		oname = nullptr;
	}
	name(char *fn, char*ln)
	{
		int k = strlen(fn) + 1;
		int b = strlen(ln) + 1;
		fname = new char[k];
		lname = new char[b];
		for (int i = 0; i < k; i++)
		{
			fname[i] = fn[i];
		}
		for (int i = 0; i < b; i++)
		{
			lname[i] = ln[i];
		}
	}
	void setname(char *fn, char*ln)
	{
		int k = strlen(fn) + 1;
		int b = strlen(ln) + 1;
		fname = new char[k];
		lname = new char[b];
		for (int i = 0; i < k; i++)
		{
			fname[i] = fn[i];
		}
		for (int i = 0; i < b; i++)
		{
			lname[i] = ln[i];
		}
	}
	char *getfname()
	{
		return fname;
	}
	char *getlname()
	{
		return lname;
	}
	~name()
	{
		delete[]fname;
		delete[]lname;
	}
	void setlname(char*n)
	{
		int k = strlen(n) + 1;
		lname = new char[k];
		for (int i = 0; i < k; i++)
		{
			lname[i] = n[i];
		}
	}
	void setfname(char*n)
	{
		int k = strlen(n) + 1;
		fname = new char[k];
		for (int i = 0; i < k; i++)
		{
			fname[i] = n[i];
		}
	}
	void setoname(char*n)
	{
		int k = strlen(n) + 1;
		oname = new char[k];
		for (int i = 0; i < k; i++)
		{
			oname[i] = n[i];
		}
	}
	char*getoname()
	{
		return oname;
	}
	void print()
	{
		if (fname != nullptr)
		{
			for (int i = 0; fname[i] != '\0'; i++)
			{
				cout << fname[i];
			}
			cout << endl;
		}
		if (lname != nullptr)
		{
			for (int i = 0; lname[i] != '\0'; i++)
			{
				cout << lname[i];
			}
			cout << endl;
		}
		if (oname != nullptr)
		{
			for (int i = 0; oname[i] != '\0'; i++)
			{
				cout << oname[i];
			}
			cout << endl;
		}
	}
	friend ostream&operator<<(ostream&out, name n)
	{
		out << n.getoname();
		return out;
	}
};
class property :public name
{
private:
	int rent;
	int cost;
	char * type;
	bool status;
	int buyerid;
public:
	void setbuyid(int i)
	{
		buyerid = i;
	}
	int getbuyid()
	{
		return buyerid;
	}
	void setstatus(bool s)
	{
		status = s;
	}
	bool getstatus()
	{
		return status;
	}
	void setrent(int r)
	{
		rent = r;
	}
	int getrent()
	{
		return rent;
	}
	void setcost(int c)
	{
		cost = c;
	}
	int getcost()
	{
		return cost;
	}
	void setproperty(char*p)
	{
		int k = strlen(p) + 1;
		type = new char[k];
		for (int i = 0; i < k; i++)
		{
			type[i] = p[i];
		}
	}
	virtual char * getproperty()
	{
		return type;
	}
	virtual void print() = 0;
};
class chest :public property
{
private:
	const char**instructions;
	int index;
	int sizeofinst;
	char * type;
public:
	chest()
	{
		index = 0;
		sizeofinst = 15;
		instructions = new const char*[15];
		instructions[0] = "Advance To Go And Collect 400 PKR";
		instructions[1] = "Bank will pay you 200 PKR";
		instructions[2] = "From Sale you got 50 PKR";
		instructions[3] = "Get out of jail,maybe kept until needed or sold for 500 PKR";
		instructions[4] = "Income tax refund collect 150 PKR";
		instructions[5] = "Your health insurance matures,collect 100 PKR";
		instructions[6] = "Pay Donation to Hospital 100 PKR";
		instructions[7] = "Pay street repair charges 50 PKR per House and 150 PKR per Hotel";
		instructions[8] = "Collect 50 PKR for your sevices";
		instructions[9] = "You Won Prize Money of 300 PKR";
		instructions[10] = "Pay Water Bill of 50 PKR";
		instructions[11] = "Pay Electricity Bill of 80 PKR";
		instructions[12] = "Pay Internet Bill of 50 PKR";
		instructions[13] = "Pay Doctor Fee 200 PKR";
		instructions[14] = "Pay Student tax of 200 PKR";
	}
	chest(const char*P)
	{
		int k = strlen(P) + 1;
		type = new char[k];
		for (int i = 0; i < k; i++)
		{
			type[i] = P[i];
		}
	}
	void check(int r)
	{
		for (int i = 0; i < 15; i++)
		{
			if (r == i)
			{
				cout << instructions[i] << endl;
			}
		}
	}
	chest(int i, char**inst)
	{
		index = i;
	}
	virtual void print()
	{
		cout << type << endl;
		/*
		if (instructions != nullptr)
		{
		for (int i = 0;i < sizeofinst;i++)
		{
		cout << instructions[i] << endl;
		}
		}
		*/
	}
	void print1()
	{
		if (instructions != nullptr)
		{
			for (int i = 0; i < sizeofinst; i++)
			{
				cout << instructions[i] << endl;
			}
		}
	}
	friend ostream & operator<<(ostream&out, chest c)
	{
		cout << "Chest: " << endl;
		for (int i = 0; i < 15; i++)
		{
			out << i + 1 << "." << c.instructions[i] << endl;
		}
		return out;
	}
	virtual char * getproperty()
	{
		return type;
	}
	~chest()
	{

	}
};
class chance :public property
{
private:
	int index;
	const char**instructions;
	int sizeofinst;
	char*type;
public:
	chance(const char*P)
	{
		int k = strlen(P) + 1;
		type = new char[k];
		for (int i = 0; i < k; i++)
		{
			type[i] = P[i];
		}
	}
	chance()
	{
		index = 0;
		sizeofinst = 15;
		instructions = new const char*[15];
		instructions[0] = "Advance To Go And Collect 300 PKR";
		instructions[1] = "Advance To DHA Phase 1";
		instructions[2] = "Advance To Nearest Utility,If unowned By Bank,If Owned Pay Owner 5x the amount shown on dice";
		instructions[3] = "Advance To Nearest Station,If unowned By Bank,If Owned Pay Owner double the amount shown on dice";
		instructions[4] = "Advance To Model Town If You pass by GO collect 300 PKR";
		instructions[5] = "Bank Pays you 100 PKR";
		instructions[6] = "Get out of Jail.Maybe kept until needed or sold for 500 PKR";
		instructions[7] = "Go Back 4 blocks";
		instructions[8] = "Repair Your Property,For Each House Pay 50 PKR for each hotel and pay 100 PKR for each house";
		instructions[9] = "Pay a small tax of 25 PKR";
		instructions[10] = "You have been selected as chair person,pay 25 PKR to each player";
		instructions[11] = "Collect 150 PKR from Bank";
		instructions[12] = "Advance to Airport and not pay any Tax beofre";
		instructions[13] = "Advance to Metro Station";
		instructions[14] = "Advance To Nearest Station,If Onowned By Bank,If Owned Pay Owner double the amount shown on dice";
	}
	~chance()
	{

	}
	chance(int i, char**r)
	{
		index = i;
	}
	void check(int r)
	{
		for (int i = 0; i < 15; i++)
		{
			if (r == i)
			{
				cout << instructions[i] << endl;;
			}
		}
	}
	void setindex(int i)
	{
		index = i;
	}
	int getindex()
	{
		return index;
	}
	void print()
	{
		cout << type << endl;
		/*
		if (instructions != nullptr)
		{
		for (int i = 0;i < sizeofinst;i++)
		{
		cout << instructions[i] << endl;
		}
		}
		*/
	}
	virtual char * getproperty()
	{
		return type;
	}
	void print1()
	{
		if (instructions != nullptr)
		{
			for (int i = 0; i < sizeofinst; i++)
			{
				cout << instructions[i] << endl;
			}
		}
	}
	friend ostream&operator<<(ostream&out, chance c)
	{
		cout << "Chance: " << endl;
		for (int i = 0; i < 14; i++)
		{
			out << i + 1 << "." << c.instructions[i] << endl;
		}
		return out;
	}
};
/*
class utility
{
private:
name ut;
name owner;
int purchase;
int rent;
public:
utility()
{
//ut = nullptr;
//owner = nullptr;
purchase = 0;
rent = 0;
}
utility(char *u, char *fn,char*ln, int p, int r)
{
ut.setoname(u);
owner.setname(fn,ln);
purchase = p;
rent = r;

}
~utility()
{

}
};
*/
class bank
{
private:
	int amount;
	int size;
	bool status;
	char**list;
public:
	bank()
	{
		amount = 0;
		size = 0;
		status = 0;
		list = nullptr;
	}
	bank(int a, int s, bool st, char**l)
	{
		amount = a;
		size = s;
		status = st;
	}
	~bank()
	{

	}
};
class player :public name
{
private:
	//name pname;
	int money;
	bool status;
	int pos;
	int playerid;
	property**properties;
	int sizeofp;
	char * type;
public:
	player()
	{
		//pname = nullptr;
		money = 0;
		status = 0;
		pos = 0;
		playerid = 0;
		properties = nullptr;
		sizeofp = 0;
	}
	void setplayerid(int x)
	{
		playerid = x;
	}
	player(char*p)
	{
		int k = strlen(p) + 1;
		type = new char[k];
		for (int i = 0; i < k; i++)
		{
			type[i] = p[i];
		}
	}
	player(char *fn, char*ln, int m, bool s, int p, int pid)
	{
		//pname.setname(fn,ln);
		money = m;
		status = s;
		pos = p;
		playerid = pid;
	}
	friend ostream &operator<<(ostream&out, player p)
	{
		out << p.getfname() << " " << p.getlname();
		return out;
	}
	~player()
	{

	}
	void setmoney(int m)
	{
		money = m;
	}
	int getmoney()
	{
		return money;
	}
	void setpos(int p)
	{
		pos = p;
	}
	int getpos()
	{
		return pos;
	}
	void setp(char*p)
	{
		int k = strlen(p) + 1;
		type = new char[k];
		for (int i = 0; i < k; i++)
		{
			type[i] = p[i];
		}
	}
	void setpropertyofplayer(char*p)
	{
		if (properties == nullptr)
		{
			sizeofp++;
			properties = new property*[sizeofp];
			properties[0]->setproperty(p);
		}
		else
		{
			sizeofp++;
			property ** sav = new property*[sizeofp];
			for (int i = 0; i < sizeofp - 1; i++)
			{
				sav[i] = properties[i];
			}
			sav[sizeofp]->setproperty(p);
			properties = new property*[sizeofp];
			for (int i = 0; i < sizeofp; i++)
			{
				properties[i] = sav[i];
			}
		}
	}
	void printproperty()
	{
		for (int i = 0; i < sizeofp; i++)
		{
			cout << properties[i] << endl;
		}
	}
	void deductmoney(int d)
	{
		money = money - d;
	}
	void addmoney(int d)
	{
		money = money + d;
	}
	int getid()
	{
		return playerid;
	}
	virtual char * getproperty()
	{
		return type;
	}
};
class nonupgradable :public property
{
private:
	name  str;
	name owner;
	int purchase;
	int rent;
	char * type;
public:
	nonupgradable()
	{
		//str = nullptr;
		//owner = nullptr;
		purchase = 0;
		rent = 0;
	}
	nonupgradable(const char*P)
	{
		int k = strlen(P) + 1;
		type = new char[k];
		for (int i = 0; i < k; i++)
		{
			type[i] = P[i];
		}
	}
	nonupgradable(char*m, char*n, int p, int r)
	{
		purchase = p;
		rent = r;
		str.setoname(m);
		owner.setoname(n);
	}
	void setpurchase(int s)
	{
		purchase = s;
	}
	int getpurchase()
	{
		return purchase;
	}
	void setrent(int r)
	{
		rent = r;
	}
	int getrent()
	{
		return rent;
	}
	void setownname(char *r)
	{
		owner.setoname(r);
	}
	char *getownname()
	{
		return owner.getoname();
	}
	void setstr(char *sr)
	{
		str.setoname(sr);
	}
	char *getstr()
	{
		return str.getoname();
	}
	~nonupgradable()
	{

	}
	virtual char * getproperty()
	{
		return type;
	}
	virtual void print()
	{
		cout << type << endl;
	}
};
class upgradeable :public property
{
private:
	//int type;
	name owner;
	bool status;
	int purchase;
	int rent;
	char * type;
public:
	upgradeable()
	{
		//type = 0;
		//owner = nullptr;
		status = 0;
		purchase = 0;
		rent = 0;
	}
	upgradeable(const char*P)
	{
		int k = strlen(P) + 1;
		type = new char[k];
		for (int i = 0; i < k; i++)
		{
			type[i] = P[i];
		}
	}
	upgradeable(int t, char*fn, char*ln, bool s, int p, int r)
	{
		//type = t;
		owner.setname(fn, ln);
		status = s;
		purchase = p;
		rent = r;
	}
	~upgradeable()
	{

	}
	virtual void print()
	{
		cout << type << endl;
	}
	virtual char * getproperty()
	{
		return type;
	}
};
class parking :public property
{
private:
	int rs;
	char * type;
public:
	parking(const char*P)
	{
		int k = strlen(P) + 1;
		type = new char[k];
		for (int i = 0; i < k; i++)
		{
			type[i] = P[i];
		}
	}
	parking()
	{
		rs = 0;
	}
	parking(int r)
	{
		rs = r;
	}
	~parking()
	{

	}
	virtual void print()
	{
		cout << type << endl;
	}
	virtual char * getproperty()
	{
		return type;
	}
};
class go :public property
{
private:
	int collect;
	bool status;
	char * type;
public:
	go()
	{
		collect = 0;
		status = 0;
	}
	go(const char*P)
	{
		int k = strlen(P) + 1;
		type = new char[k];
		for (int i = 0; i < k; i++)
		{
			type[i] = P[i];
		}
	}
	go(int c, bool s)
	{
		collect = c;
		status = s;
	}
	void setcol(int c)
	{
		collect = c;
	}
	int getcol()
	{
		return collect;
	}
	void setstatus(bool s)
	{
		status = s;
	}
	bool getstatus()
	{
		return status;
	}
	~go()
	{

	}
	virtual void print()
	{
		cout << type << endl;
	}
	virtual char * getproperty()
	{
		return type;
	}
};
class landtax :public property
{
private:
	int rs;
	char * type;
public:
	landtax(const char*P)
	{
		int k = strlen(P) + 1;
		type = new char[k];
		for (int i = 0; i < k; i++)
		{
			type[i] = P[i];
		}
	}
	landtax()
	{
		rs = 0;
	}
	landtax(int r)
	{
		rs = r;
	}
	~landtax()
	{

	}
	virtual void print()
	{
		cout << type << endl;
	}
	virtual char * getproperty()
	{
		return type;
	}
};
class  jail :public property
{
private:
	bool status;
	char * type;
public:
	jail(const char*P)
	{
		int k = strlen(P) + 1;
		type = new char[k];
		for (int i = 0; i < k; i++)
		{
			type[i] = P[i];
		}
	}
	jail()
	{
		status = 0;
	}
	jail(bool s)
	{
		status = s;
	}
	~jail()
	{

	}
	virtual void print()
	{
		cout << type << endl;
	}
	virtual char * getproperty()
	{
		return type;
	}
};
class board
{
private:
	player * *plist;
	int sizeofboard;
	int pos;
	bool status;
	int noofP;
	property**prlist;
	int size;
public:
	board()
	{
		//proplist = nullptr;
		noofP = 0;
		sizeofboard = 40;
		pos = 0;
		prlist = new property*[40];

		prlist[0] = new go("GO");
		prlist[0]->setcost(0);
		prlist[0]->setrent(0);
		prlist[0]->setstatus(0);

		prlist[1] = new upgradeable("JoharTownA");
		prlist[1]->setcost(200);
		prlist[1]->setrent(80);
		prlist[1]->setbuyid(0);
		prlist[1]->setstatus(0);

		prlist[2] = new chest("Chest");
		prlist[2]->setcost(0);
		prlist[2]->setrent(0);
		prlist[2]->setbuyid(0);
		prlist[2]->setstatus(0);

		prlist[3] = new upgradeable("JoharTownB");

		prlist[3]->setcost(250);
		prlist[3]->setrent(90);
		prlist[3]->setbuyid(0);
		prlist[3]->setstatus(0);

		prlist[4] = new landtax("Tax");

		prlist[4]->setcost(0);
		prlist[4]->setrent(200);
		prlist[4]->setbuyid(0);
		prlist[4]->setstatus(0);

		prlist[5] = new nonupgradable("MetroStation");

		prlist[5]->setcost(2000);
		prlist[5]->setrent(200);
		prlist[5]->setbuyid(0);
		prlist[5]->setstatus(0);

		prlist[6] = new upgradeable("IqbalTownA");

		prlist[6]->setcost(250);
		prlist[6]->setrent(60);
		prlist[6]->setbuyid(0);
		prlist[6]->setstatus(0);

		prlist[7] = new chance("Chance");

		prlist[7]->setcost(0);
		prlist[7]->setrent(0);
		prlist[7]->setbuyid(0);
		prlist[7]->setstatus(0);

		prlist[8] = new upgradeable("IqbalTownB");

		prlist[8]->setcost(300);
		prlist[8]->setrent(70);
		prlist[8]->setbuyid(0);
		prlist[8]->setstatus(0);

		prlist[9] = new upgradeable("IqbalTownC");

		prlist[9]->setcost(400);
		prlist[9]->setrent(100);
		prlist[9]->setbuyid(0);
		prlist[9]->setstatus(0);

		prlist[10] = new jail("Jail");

		prlist[10]->setcost(0);
		prlist[10]->setrent(0);
		prlist[10]->setbuyid(0);
		prlist[10]->setstatus(0);

		prlist[11] = new upgradeable("FaisalTownA");

		prlist[11]->setcost(300);
		prlist[11]->setrent(100);
		prlist[11]->setbuyid(0);
		prlist[11]->setstatus(0);

		prlist[12] = new nonupgradable("Lesco");

		prlist[12]->setcost(5000);
		prlist[12]->setrent(450);
		prlist[12]->setbuyid(0);
		prlist[12]->setstatus(0);

		prlist[13] = new upgradeable("FaisalTownB");

		prlist[13]->setcost(400);
		prlist[13]->setrent(130);
		prlist[13]->setbuyid(0);
		prlist[13]->setstatus(0);

		prlist[14] = new upgradeable("FaisalTownC");

		prlist[14]->setcost(400);
		prlist[14]->setrent(130);
		prlist[14]->setbuyid(0);
		prlist[14]->setstatus(0);

		prlist[15] = new nonupgradable("BusStation");

		prlist[15]->setcost(2000);
		prlist[15]->setrent(200);
		prlist[15]->setbuyid(0);
		prlist[15]->setstatus(0);

		prlist[16] = new upgradeable("ModelTownA");

		prlist[16]->setcost(800);
		prlist[16]->setrent(200);
		prlist[16]->setbuyid(0);
		prlist[16]->setstatus(0);

		prlist[17] = new chest("CommunityChest");

		prlist[17]->setcost(0);
		prlist[17]->setrent(0);
		prlist[17]->setbuyid(0);
		prlist[17]->setstatus(0);

		prlist[18] = new upgradeable("ModelTownB");

		prlist[18]->setcost(850);
		prlist[18]->setrent(250);
		prlist[18]->setbuyid(0);
		prlist[18]->setstatus(0);

		prlist[19] = new upgradeable("ModelTownC");

		prlist[19]->setcost(2000);
		prlist[19]->setrent(500);
		prlist[19]->setbuyid(0);
		prlist[19]->setstatus(0);

		prlist[20] = new parking("Parking");

		prlist[20]->setcost(0);
		prlist[20]->setrent(10);
		prlist[20]->setbuyid(0);
		prlist[20]->setstatus(0);

		prlist[21] = new nonupgradable("PTCL");

		prlist[21]->setcost(8000);
		prlist[21]->setrent(500);
		prlist[21]->setbuyid(0);
		prlist[21]->setstatus(0);

		prlist[22] = new chance("Chance");

		prlist[22]->setcost(0);
		prlist[22]->setrent(0);
		prlist[22]->setbuyid(0);
		prlist[22]->setstatus(0);

		prlist[23] = new upgradeable("Gulberg2A");

		prlist[23]->setcost(1000);
		prlist[23]->setrent(300);
		prlist[23]->setbuyid(0);
		prlist[23]->setstatus(0);

		prlist[24] = new upgradeable("Gulberg2B");

		prlist[24]->setcost(1200);
		prlist[24]->setrent(350);
		prlist[24]->setbuyid(0);
		prlist[24]->setstatus(0);

		prlist[25] = new nonupgradable("RailwayStation");

		prlist[25]->setcost(2500);
		prlist[25]->setrent(350);
		prlist[25]->setbuyid(0);
		prlist[25]->setstatus(0);

		prlist[26] = new upgradeable("Gulberg2C");

		prlist[26]->setcost(2500);
		prlist[26]->setrent(600);
		prlist[26]->setbuyid(0);
		prlist[26]->setstatus(0);

		prlist[27] = new upgradeable("DHA-A");

		prlist[27]->setcost(2000);
		prlist[27]->setrent(500);
		prlist[27]->setbuyid(0);
		prlist[27]->setstatus(0);

		prlist[28] = new nonupgradable("WASA");

		prlist[28]->setcost(4000);
		prlist[28]->setrent(400);
		prlist[28]->setbuyid(0);
		prlist[28]->setstatus(0);

		prlist[29] = new upgradeable("DHA-B");

		prlist[29]->setcost(2000);
		prlist[29]->setrent(500);
		prlist[29]->setbuyid(0);
		prlist[29]->setstatus(0);

		prlist[30] = new jail("Gotojail");

		prlist[30]->setcost(0);
		prlist[30]->setrent(0);
		prlist[30]->setbuyid(0);
		prlist[30]->setstatus(0);

		prlist[31] = new upgradeable("DHAYblock");

		prlist[31]->setcost(2500);
		prlist[31]->setrent(1000);
		prlist[31]->setbuyid(0);
		prlist[31]->setstatus(0);

		prlist[32] = new nonupgradable("SUI");

		prlist[32]->setcost(2500);
		prlist[32]->setrent(350);
		prlist[32]->setbuyid(0);
		prlist[32]->setstatus(0);

		prlist[33] = new chest("CommunityChest");

		prlist[33]->setcost(0);
		prlist[33]->setrent(0);
		prlist[33]->setbuyid(0);
		prlist[33]->setstatus(0);

		prlist[34] = new upgradeable("BahriaTownA");

		prlist[34]->setcost(2500);
		prlist[34]->setrent(800);
		prlist[34]->setbuyid(0);
		prlist[34]->setstatus(0);

		prlist[35] = new nonupgradable("OrangeTrain");

		prlist[35]->setcost(2500);
		prlist[35]->setrent(350);
		prlist[35]->setbuyid(0);
		prlist[35]->setstatus(0);

		prlist[36] = new chance("Chance");

		prlist[36]->setcost(0);
		prlist[36]->setrent(0);
		prlist[36]->setbuyid(0);
		prlist[36]->setstatus(0);

		prlist[37] = new upgradeable("BahriaTownB");

		prlist[37]->setcost(3000);
		prlist[37]->setrent(900);
		prlist[37]->setbuyid(0);
		prlist[37]->setstatus(0);

		prlist[38] = new landtax("Tax");

		prlist[38]->setcost(0);
		prlist[38]->setrent(100);
		prlist[38]->setbuyid(0);
		prlist[38]->setstatus(0);

		prlist[39] = new upgradeable("BahriaTownC");

		prlist[39]->setcost(3000);
		prlist[39]->setrent(1000);
		prlist[39]->setbuyid(0);
		prlist[39]->setstatus(0);
	}
	friend ostream&operator<<(ostream&out, board b)
	{
		int x = 5, y = 5;
		if (b.plist != nullptr)
		{
			for (int i = 0; i < 2; i++)
				out << *b.plist[i] << endl;
		}
		for (int i = 0; i < 40; i++)
		{
			gotoxy(x, y);
			out << *b.prlist[i] << endl;
			if (i < 10)
				x = x + 14;
			else if (i >= 10 && i < 20)
				y = y + 3;
			else if (i >= 20 && i < 30)
				x = x - 14;
			else
				y = y - 3;
		}
		return out;
	}
	void print()
	{
		int x = 5, y = 5;
		for (int i = 0; i < noofP; i++)
		{
			cout << plist[i] << endl;
		}
		for (int i = 0; i < 40; i++)
		{
			gotoxy(x, y);
			prlist[i]->print();
			if (i < 10)
				x = x + 14;
			else if (i >= 10 && i < 20)
				y = y + 3;
			else if (i >= 20 && i < 30)
				x = x - 14;
			else
				y = y - 3;
		}
	}
	void setpos(int p)
	{
		pos = p;
	}
	int getpos()
	{
		return pos;
	}
	int getcost(int p)
	{
		for (int i = 0; i < 40; i++)
		{
			if (i == p)
			{
				return prlist[i]->getcost();
			}
		}
	}
	void setstatusandid(int p, int id)
	{
		for (int i = 0; i < 40; i++)
		{
			if (i == p)
			{
				prlist[i]->setstatus(true);
				prlist[i]->setbuyid(id);
			}
		}
	}
	bool getstatus(int st)
	{
		for (int i = 0; i < 40; i++)
		{
			if (i == st)
			{
				return prlist[i]->getstatus();
			}
		}
	}
	int getid(int id)
	{
		for (int i = 0; i < 40; i++)
		{
			if (i == id)
			{
				return prlist[i]->getbuyid();
			}
		}
	}
	int getrent(int r)
	{
		for (int i = 0; i < 40; i++)
		{
			if (i == r)
			{
				return prlist[i]->getrent();
			}
		}
	}
	char * getproperty(int p)
	{
		for (int i = 0; i < 40; i++)
		{
			if (i == p)
			{
				return prlist[i]->getproperty();
			}
		}
	}
	void setrent(int index, int ren)
	{
		for (int i = 0; i < 40; i++)
		{
			if (i == index)
			{
				prlist[i]->setrent(ren);
			}
		}
	}
};
int main()
{
	board b;
	b.print();
	chest c;
	//cout << c;
	chance c1;
	//cout << c1;
	int no;
	for (int j = 0; j < 30; j++)
		cout << endl;
	cout << "How many players are going to play" << endl;
	cin >> no;
	player**p = new player*[no];
	for (int i = 0; i < no; i++)
	{
		p[i] = new player[1];
	}
	char fname[20], lname[20];
	for (int i = 0; i < no; i++)
	{
		system("cls");
		cout << "Enter details" << endl;
		cout << "Enter first name" << endl;
		cin >> fname;
		cout << "Enter last name" << endl;
		cin >> lname;
		p[i]->setfname(fname);
		p[i]->setlname(lname);
		p[i]->setmoney(5000);
		p[i]->setpos(0);
		p[i]->setplayerid(i + 1);
	}
	bool check = false;
	bool check1 = false;
	bool check2 = false;
	bool check3 = false;
	bool check4 = false;
	bool check5 = false;
	bool check6 = false;
	bool check7 = false;
	int count, turns = 0;
	int i = 1;
	int Q;
	count = 0;
	srand(time(0));
	int pos = 0;
	int pos2 = 0;
	int pos1 = 0;
	int save = 0;
	int upgrade = 0;
	int counter = 0;
	int choose = 0;
	int skipturn=0;
	while (check == false)
	{
		//int skipturn;
		if (skipturn != 1)
		{
			cout << "Turn of Player " << i << endl;
		}
		if (skipturn == 1)
		{
			i++;
			cout << "Turn of Player " << i << endl;
			skipturn = 0;
		}
		if (p[count]->getpos() == 10)
		{
			if (skipturn != 1)
			{
				int c;
				cout << "Do you want to pay a fine PKR 400 ";
				cin >> c;
				if (c == 1)
				{
					p[count]->deductmoney(400);
				}
				else
				{
					count++; i++;
					cout << "Turn of Player " << i << endl;
					skipturn = 1;
				}
			}
		}
		int dice;
		dice = rand() % 6 + 1;
		if (i == 1)
		{
			pos1 = pos1 + dice;
			pos = pos1;
		}
		if (i == 2)
		{
			pos2 = pos2 + dice;
			pos = pos2;
		}
		cout << "Dice : " << dice << endl;
		p[count]->setpos(pos);
		int Q = 1;
		//PropertyPurchasing
		if (Q == 1 && pos != 38 && Q == 1 && pos != 20 && Q == 1 && pos != 4 && Q == 1 && pos != 30 && Q == 1 && pos != 10 && Q == 1 && pos != 2 && Q == 1 && pos != 7 && Q == 1 && pos != 17 && Q == 1 && pos != 33 && Q == 1 && pos != 36)
		{
			b.setpos(pos);
			if (p[count]->getmoney() >= b.getcost(pos) && b.getstatus(pos) == false)
			{
				cout << "Do You Want To Purchse This Property (1 for yes and 0 for no)" << endl;
				cin >> Q;
				if (Q == 1)
				{
					cout << "Purchased" << endl;
					p[count]->deductmoney(b.getcost(p[count]->getpos()));
					b.setstatusandid(p[count]->getpos(), i);
				}
				//p[count]->setpropertyofplayer(b.getproperty(b.getpos()));
				//p[count]->printproperty();
			}
			else
			{
				cout << "Cannot Purchase" << endl;
			}
		}
		//checkforupgradableproperties
		if (b.getstatus(1) == true && b.getstatus(3) == true && check1 == false)
		{
			cout << "Properties are upgradable (Press 1 to upgrade 0 to ignore)" << endl;
			cin >> upgrade;
			if (upgrade == 1)
			{
				cout << "Chose to following items to add to you property and -1 to exit" << endl;
				cout << "1.House" << endl;
				cout << "2.Hotel" << endl;
				cout << "3.Shop" << endl;
				cout << "4.Wi-Fi" << endl;
				cout << "5.Gas-Connection" << endl;
				cout << "6.Electricity" << endl;
				while (choose != -1)
				{
					cin >> choose;
					if (choose == 1)
					{
						p[count]->deductmoney(100);
						b.setrent(pos, 30);
					}
					else if (choose == 2)
					{
						p[count]->deductmoney(200);
						b.setrent(pos, 80);
					}
					else if (choose == 3)
					{
						p[count]->deductmoney(300);
						b.setrent(pos, 60);
					}
					else if (choose == 4)
					{
						p[count]->deductmoney(30);
						b.setrent(pos, 10);
					}
					else if (choose == 5)
					{
						p[count]->deductmoney(50);
						b.setrent(pos, 20);
					}
					else if (choose == 6)
					{
						p[count]->deductmoney(50);
						b.setrent(pos, 30);
					}
				}
			}
			check1 = true;
		}
		else if (b.getstatus(6) == true && b.getstatus(8) == true && b.getstatus(9) == true && check2 == false)
		{
			cout << "Properties are upgradable (Press 1 to upgrade 0 to ignore)" << endl;
			cin >> upgrade;
			if (upgrade == 1)
			{
				cout << "Chose to following items to add to you property" << endl;
				cout << "1.House" << endl;
				cout << "2.Hotel" << endl;
				cout << "3.Shop" << endl;
				cout << "4.Wi-Fi" << endl;
				cout << "5.Gas-Connection" << endl;
				cout << "6.Electricity" << endl;
				while (choose != -1)
				{
					cin >> choose;
					if (choose == 1)
					{
						p[count]->deductmoney(100);
						b.setrent(pos, 30);
					}
					else if (choose == 2)
					{
						p[count]->deductmoney(200);
						b.setrent(pos, 80);
					}
					else if (choose == 3)
					{
						p[count]->deductmoney(300);
						b.setrent(pos, 60);
					}
					else if (choose == 4)
					{
						p[count]->deductmoney(30);
						b.setrent(pos, 10);
					}
					else if (choose == 5)
					{
						p[count]->deductmoney(50);
						b.setrent(pos, 20);
					}
					else if (choose == 6)
					{
						p[count]->deductmoney(50);
						b.setrent(pos, 30);
					}
				}
			}
			check2 = true;
		}
		else if (b.getstatus(11) == true && b.getstatus(13) == true && b.getstatus(14) == true && check3 == false)
		{
			cout << "Properties are upgradable (Press 1 to upgrade 0 to ignore)" << endl;
			cin >> upgrade;
			if (upgrade == 1)
			{
				cout << "Chose to following items to add to you property -1 to stop entering" << endl;
				cout << "1.House" << endl;
				cout << "2.Hotel" << endl;
				cout << "3.Shop" << endl;
				cout << "4.Wi-Fi" << endl;
				cout << "5.Gas-Connection" << endl;
				cout << "6.Electricity" << endl;
				while (choose != -1)
				{
					cin >> choose;
					if (choose == 1)
					{
						p[count]->deductmoney(100);
						b.setrent(pos, 30);
					}
					else if (choose == 2)
					{
						p[count]->deductmoney(200);
						b.setrent(pos, 80);
					}
					else if (choose == 3)
					{
						p[count]->deductmoney(300);
						b.setrent(pos, 60);
					}
					else if (choose == 4)
					{
						p[count]->deductmoney(30);
						b.setrent(pos, 10);
					}
					else if (choose == 5)
					{
						p[count]->deductmoney(50);
						b.setrent(pos, 20);
					}
					else if (choose == 6)
					{
						p[count]->deductmoney(50);
						b.setrent(pos, 30);
					}
				}
			}
			check3 = true;
		}
		else if (b.getstatus(16) == true && b.getstatus(18) == true && b.getstatus(19) == true && check4 == false)
		{
			cout << "Properties are upgradable (Press 1 to upgrade 0 to ignore)" << endl;
			cin >> upgrade;
			if (upgrade == 1)
			{
				cout << "Chose to following items to add to you property -1 to stop entering" << endl;
				cout << "1.House" << endl;
				cout << "2.Hotel" << endl;
				cout << "3.Shop" << endl;
				cout << "4.Wi-Fi" << endl;
				cout << "5.Gas-Connection" << endl;
				cout << "6.Electricity" << endl;
				while (choose != -1)
				{
					cin >> choose;
					if (choose == 1)
					{
						p[count]->deductmoney(100);
						b.setrent(pos, 30);
					}
					else if (choose == 2)
					{
						p[count]->deductmoney(200);
						b.setrent(pos, 80);
					}
					else if (choose == 3)
					{
						p[count]->deductmoney(300);
						b.setrent(pos, 60);
					}
					else if (choose == 4)
					{
						p[count]->deductmoney(30);
						b.setrent(pos, 10);
					}
					else if (choose == 5)
					{
						p[count]->deductmoney(50);
						b.setrent(pos, 20);
					}
					else if (choose == 6)
					{
						p[count]->deductmoney(50);
						b.setrent(pos, 30);
					}
				}
			}
			check4 = true;
		}
		else if (b.getstatus(23) == true && b.getstatus(24) == true && b.getstatus(26) == true && check5 == false)
		{
			cout << "Properties are upgradable (Press 1 to upgrade 0 to ignore)" << endl;
			cin >> upgrade;
			if (upgrade == 1)
			{
				cout << "Chose to following items to add to you property -1 to stop entering" << endl;
				cout << "1.House" << endl;
				cout << "2.Hotel" << endl;
				cout << "3.Shop" << endl;
				cout << "4.Wi-Fi" << endl;
				cout << "5.Gas-Connection" << endl;
				cout << "6.Electricity" << endl;
				while (choose != -1)
				{
					cin >> choose;
					if (choose == 1)
					{
						p[count]->deductmoney(100);
						b.setrent(pos, 30);
					}
					else if (choose == 2)
					{
						p[count]->deductmoney(200);
						b.setrent(pos, 80);
					}
					else if (choose == 3)
					{
						p[count]->deductmoney(300);
						b.setrent(pos, 60);
					}
					else if (choose == 4)
					{
						p[count]->deductmoney(30);
						b.setrent(pos, 10);
					}
					else if (choose == 5)
					{
						p[count]->deductmoney(50);
						b.setrent(pos, 20);
					}
					else if (choose == 6)
					{
						p[count]->deductmoney(50);
						b.setrent(pos, 30);
					}
				}
			}
			check5 = true;
		}
		else if (b.getstatus(27) == true && b.getstatus(29) == true && b.getstatus(31) == true && check6 == false)
		{
			cout << "Properties are upgradable (Press 1 to upgrade 0 to ignore)" << endl;
			cin >> upgrade;
			if (upgrade == 1)
			{
				cout << "Chose to following items to add to you property -1 to stop entering" << endl;
				cout << "1.House" << endl;
				cout << "2.Hotel" << endl;
				cout << "3.Shop" << endl;
				cout << "4.Wi-Fi" << endl;
				cout << "5.Gas-Connection" << endl;
				cout << "6.Electricity" << endl;
				while (choose != -1)
				{
					cin >> choose;
					if (choose == 1)
					{
						p[count]->deductmoney(100);
						b.setrent(pos, 30);
					}
					else if (choose == 2)
					{
						p[count]->deductmoney(200);
						b.setrent(pos, 80);
					}
					else if (choose == 3)
					{
						p[count]->deductmoney(300);
						b.setrent(pos, 60);
					}
					else if (choose == 4)
					{
						p[count]->deductmoney(30);
						b.setrent(pos, 10);
					}
					else if (choose == 5)
					{
						p[count]->deductmoney(50);
						b.setrent(pos, 20);
					}
					else if (choose == 6)
					{
						p[count]->deductmoney(50);
						b.setrent(pos, 30);
					}
				}
			}
			check6 = true;
		}
		else if (b.getstatus(34) == true && b.getstatus(37) == true && b.getstatus(39) == true && check7 == false)
		{
			cout << "Properties are upgradable (Press 1 to upgrade 0 to ignore)" << endl;
			cin >> upgrade;
			if (upgrade == 1)
			{
				cout << "Chose to following items to add to you property -1 to stop entering" << endl;
				cout << "1.House" << endl;
				cout << "2.Hotel" << endl;
				cout << "3.Shop" << endl;
				cout << "4.Wi-Fi" << endl;
				cout << "5.Gas-Connection" << endl;
				cout << "6.Electricity" << endl;
				while (choose != -1)
				{
					cin >> choose;
					if (choose == 1)
					{
						p[count]->deductmoney(100);
						b.setrent(pos, 30);
					}
					else if (choose == 2)
					{
						p[count]->deductmoney(200);
						b.setrent(pos, 80);
					}
					else if (choose == 3)
					{
						p[count]->deductmoney(300);
						b.setrent(pos, 60);
					}
					else if (choose == 4)
					{
						p[count]->deductmoney(30);
						b.setrent(pos, 10);
					}
					else if (choose == 5)
					{
						p[count]->deductmoney(50);
						b.setrent(pos, 20);
					}
					else if (choose == 6)
					{
						p[count]->deductmoney(50);
						b.setrent(pos, 30);
					}
				}
			}
			check7 = true;
		}
		//payingrentcostifplayerpassesbyanownedproperty
		if (b.getstatus(pos))
		{
			if (b.getid(pos) != p[count]->getid())
			{
				p[count]->deductmoney(b.getrent(pos));
				cout << "RENT Collected from Player " <<i<<endl;
			}
		}
		//parking
		if (p[count]->getpos() == 20)
		{
			p[count]->deductmoney(20);
		}
		//landtax20%
		if (p[count]->getpos() == 38)
		{
			p[count]->deductmoney(200);
		}
		//propertytax10%
		if (p[count]->getpos() == 4)
		{
			p[count]->deductmoney(100);
		}
		//jail
		if (p[count]->getpos() == 10)
		{

		}
		//ifpassesbygo
		if (p[count]->getpos() >= 39)
		{
			p[count]->setmoney(p[count]->getmoney() + 500);
			if (count == 0)
			{
				pos1 = 0;
			}
			else
			{
				pos2 = 0;
			}
		}
		//breakingthegameifplayerhasgonebankrupt
		if (p[count]->getmoney() <= 0)
		{
			if (count + 1 < no)
			{
				if (p[count + 1]->getmoney() <= 0)
				{
					check = true;
					if (count != 0)
						cout << "\nWinner is Player 2 ";
					if (count != 1)
						cout << "\nWinner is Player 1 ";
				}
			}
		}
		//gotojail
		if (p[count]->getpos() == 30)
		{
			cout << "Player " << count+1 << " is in JAIL\n";
			p[count]->setpos(10);
			if (count == 0)
			{
				pos1 = 10;
			}
			else if (count == 1)
			{
				pos2 = 10;
			}
			pos = 10;
		}
		//chance
		if (p[count]->getpos() == (7 || 22 || 36))
		{
			int card;
			card = rand() % 14 + 1;
			chance c;
			c.check(card);
			if (card == 0)
			{
				p[count]->setmoney(p[count]->getmoney() + 300);
				if (count == 0)
				{
					pos1 = 0;
				}
				else
				{
					pos2 = 0;
				}
			}
			if (card == 1)
			{
				if (count == 0)
				{
					pos1 = 27;
				}
				else
				{
					pos2 = 27;
				}
			}
			if (card == 2)
			{

			}
			if (card == (3 || 4))
			{

			}
			if (card == 5)
			{

			}
			if (card == 6)
			{
				if (count == 0)
				{
					pos1 = 16;
				}
				else
				{
					pos2 = 16;
				}
			}
			if (card == 7)
			{
				p[count]->addmoney(100);
			}
			if (card == 8)
			{
				int che;
				cout << "Do you want to sell Get out of jail or not ";
				cin >> che;
				if (che == 1)
				{
					p[count]->addmoney(500);
				}
			}
			if (card == 9)
			{
				if (count == 0)
				{
					pos1 = pos1 - 4;
				}
				else
				{
					pos2 = pos2 - 4;
				}
			}
			if (card == 10)
			{

			}
			if (card == 11)
			{
				p[count]->deductmoney(25);
			}
			if (card == 12)
			{
				if (count == 0)
				{
					p[count + 1]->addmoney(25);
				}
				else
					p[count - 1]->addmoney(25);


			}
			if (card == 13)
			{
				p[count]->addmoney(150);
			}
			if (card == 14)
			{

			}
		}
		if (p[count]->getpos() == (2 || 17 || 33))
		{
			int card;
			card = rand() % 14 + 1;
			chest c;
			c.check(card);
			if (card == 0)
			{
				p[count]->setmoney(p[count]->getmoney() + 400);
				if (count == 0)
				{
					pos1 = 0;
				}
				else
				{
					pos2 = 0;
				}
			}
			if (card == 1)
			{
				p[count]->addmoney(200);
			}
			if (card == 2)
			{
				p[count]->deductmoney(200);
			}
			if (card == 3)
			{
				p[count]->addmoney(50);
			}
			if (card == 4)
			{
				int che;
				cout << "Do you want to sell Get out of jail or not ";
				cin >> che;
				if (che == 1)
				{
					p[count]->addmoney(500);
				}
			}
			if (card == 5)
			{
				p[count]->addmoney(150);
			}
			if (card == 6)
			{
				p[count]->addmoney(150);

			}
			if (card == 7)
			{
				p[count]->addmoney(200);

			}
			if (card == 8)
			{
				p[count]->addmoney(150);

			}
			if (card == 9)
			{
				p[count]->deductmoney(100);

			}
			if (card == 10)
			{
				p[count]->deductmoney(200);

			}
			if (card == 11)
			{
				p[count]->addmoney(50);

			}
			if (card == 12)
			{

			}
			if (card == 13)
			{
				p[count]->addmoney(300);

			}
			if (card == 14)
			{
				p[count]->deductmoney(50);

			}
		}
		count++;
		if (i == no)
		{
			i = 0;
			count = 0;
		}
		i++;
		

	}
	_getch();
}
