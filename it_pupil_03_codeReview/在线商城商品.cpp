#include<iostream>
#include<string>
#include <fstream>  
#include <iostream>  
using namespace std;

string name[999];		//用来保存文件中的名字
string price[999];			//.		.	.	.	.	  价格
string type[999];			//.		.	.	.	.	  类型
int isLive[999];				//.		.	.	. 是否被删除
int bianhao[999];			//.		.	.	.	.	  编号
int Id = 0;

/*
将所有商品的共性提取出来，组成一个基类Goods类，
然后让所有的商品继承这个基类，在分别写商品的构造函数
*/

class Goods		//商品类	所有商品的基类
{
private:		
	string	price;			//价格
	string name;			//名字
	string type;			//类型
	int id;				//编号
	int isLive;			//是否被删除
public:
	void setPrice(string price) {			//设置价格
		this->price = price;
	}

	void setName(string name) {			//设置名字
		this->name = name;
	}

	void setType(string type) {				//设置类型
		this->type = type;
	}

	void setId()				//设置编号
	{
		this->id = Id++;
	}

	void setIsLive()				//默认没有被删除
	{
		this->isLive = 1;
	}

	int getIsLive()			//获取状态
	{
		return this->isLive;
	}

	int get_id()
	{
		return this->id;
	}

	void show() {
		cout << "种类：" << type << "		名字：" << name << "		价格(元)：" << price << endl;
	}

	void save() {				//把所有东西都存到文件里
		ofstream os_id("goods_id.txt", ios::app);					//以追加写入的方式打开文件
		os_id << id << endl;									//写入
		os_id.close();							//关闭文件
		ofstream os_type("goods_type.txt", ios::app);	
		os_type << type << endl;
		os_type.close();
		ofstream os_name("goods_name.txt", ios::app);
		os_name << name << endl;
		os_name.close();
		ofstream os_price("goods_price.txt", ios::app);
		os_price << price << endl;
		os_price.close();
		ofstream os_isLive("goods_isLive.txt", ios::app);
		os_isLive << isLive << endl;
		os_isLive.close();
	}
};

class Computer : public Goods			//计算机类  继承商品类
{
public:
	Computer(string name, string price)
	{
		this->setName(name);
		this->setPrice(price);
		this->setType("计算机");
		this->setId();
		this->setIsLive();
	}
};

class Peripheral : public Goods			//外围设备类    继承商品类
{
public:
	Peripheral(string name, string price)
	{
		this->setName(name);
		this->setPrice(price);
		this->setType("外围设备");
		this->setId();
		this->setIsLive();
	}
};

class Office :public Goods			//办公用品类			继承商品类
{
public:
	Office(string name, string price)
	{
		this->setName(name);
		this->setPrice(price);
		this->setType("办公用品");
		this->setId();
		this->setIsLive();
	}
};

class Life :public Goods			//生活用品类				继承商品类
{
public:
	Life(string name, string price)
	{
		this->setName(name);
		this->setPrice(price);
		this->setType("生活用品");
		this->setId();
		this->setIsLive();
	}
};

class Books :public Goods				//图书类				继承商品类
{
public:
	Books(string name, string price)
	{
		this->setName(name);
		this->setPrice(price);
		this->setType("图书");
		this->setId();
		this->setIsLive();
	}
};


/*
	将所有方法封装在这个类中
*/
class Methods				//方法类		
{
public:
	void get_all_goods()			//把文件里的所有商品加载到内存里
	{
		ifstream OpenFile("goods_id.txt");			//把最新商品id给Id
		int i = 0;
		while (OpenFile)
		{
			string text;
			OpenFile >> text;
			//cout << text << endl;
			if(text.size()!=0)
			{
				Id = atoi(text.c_str());
				bianhao[i++] = Id;
			}
		}
		Id++;
		OpenFile.close();

		ifstream OpenFile_name("goods_name.txt");			//把所有名字读入内存
		i = 0;
		while (OpenFile_name)
		{
			string text;
			OpenFile_name >> text;
			//cout << text<<endl;
			name[i++] = text;
		}
		OpenFile_name.close();


		ifstream OpenFile_price("goods_price.txt");			//把所有价格读入内存
		i = 0;
		while (OpenFile_price)
		{
			string text;
			OpenFile_price >> text;
			//cout << text<<endl;
			price[i++] = text;
		}
		OpenFile_price.close();


		ifstream OpenFile_type("goods_type.txt");			//把所有类别读入内存
		 i = 0;
		while (OpenFile_type)
		{
			string text;
			OpenFile_type >> text;
			//cout << text<<endl;
			type[i++] = text;
		}
		OpenFile_type.close();


		ifstream OpenFile_live("goods_isLive.txt");			//把所有状态读入内存
		i = 0;
		while (OpenFile_live)
		{
			string text;
			OpenFile_live >> text;
			//cout << text<<endl;
			isLive[i++] = text[0]-'0';
		}
		OpenFile_live.close();

	}

	void add_one_good()		//增加一个商品
	{
		string input;
		while (true)
		{
			cout << "请选择您要添加的商品的类别" << endl;
			cout << "1.计算机类" << endl;
			cout << "2.外围设备类" << endl;
			cout << "3.办公用品类" << endl;
			cout << "4.生活用品类" << endl;
			cout << "5.图书类" << endl;
			cout << "6.取消" << endl;
			cin >> input;
			if (input == "6")
				return;
			if (input != "1"&&input != "2"&&input != "3"&&input != "4"&&input != "5")
			{
				cout << "您选择的商品类别不存在，请重新选择，或者输入6退出此功能" << endl;
			}
			else
			{
				break;
			}
		}
		int a = int(input[0] - '0');
		string t_name;
		string t_price;
		Goods *g;			//定义一个基类，方便后面类型转换（多态）
		int t_id;
	
		switch (a)
		{
		case 1:
			cout << "请输入计算机的名字" << endl;
			cin >> t_name;
			cout << "请输入计算机的价格" << endl;
			cin >> t_price;
			g = new Computer(t_name,t_price);				//多态，利用基类对象实例化一个子类对象
			g->save();
			t_id = g->get_id();
			name[t_id] = t_name;
			price[t_id] = t_price;
			type[t_id] = "计算机";
			isLive[t_id] = 1;
			bianhao[t_id] = t_id;
			break;
		case 2:
			cout << "请输入外围设备的名字" << endl;
			cin >> t_name;
			cout << "请输入外围设备的价格" << endl;
			cin >> t_price;
			g = new Peripheral(t_name, t_price);
			g->save();
			t_id = g->get_id();
			name[t_id] = t_name;
			price[t_id] = t_price;
			type[t_id] = "外围设备";
			isLive[t_id] = 1;
			bianhao[t_id] = t_id;
			break;
		case 3:
			cout << "请输入办公用品的名字" << endl;
			cin >> t_name;
			cout << "请输入办公用品的价格" << endl;
			cin >> t_price;
			g = new Office(t_name, t_price);
			g->save();
			t_id = g->get_id();
			name[t_id] = t_name;
			price[t_id] = t_price;
			type[t_id] = "办公用品";
			isLive[t_id] = 1;
			bianhao[t_id] = t_id;
			break;
		case 4:
			cout << "请输入生活用品的名字" << endl;
			cin >> t_name;
			cout << "请输入生活用品的价格" << endl;
			cin >> t_price;
			g = new Life(t_name, t_price);
			g->save();
			 t_id = g->get_id();
			name[t_id] = t_name;
			price[t_id] = t_price;
			type[t_id] = "生活用品";
			isLive[t_id] = 1;
			bianhao[t_id] = t_id;
			break;
		case 5:
			cout << "请输入图书的名字" << endl;
			cin >> t_name;
			cout << "请输入图书的价格" << endl;
			cin >> t_price;
			g = new Books(t_name, t_price);
			g->save();
			t_id = g->get_id();
			name[t_id] = t_name;
			price[t_id] = t_price;
			type[t_id] = "图书";
			isLive[t_id] = 1;
			bianhao[t_id] = t_id;
			break;
		default:
			break;
		}
		cout << endl << "添加成功，编号为：" << bianhao[t_id] << endl;
	}

	void show_all_goods()
	{
		for (int i = 0; i != Id; i++)
		{
			if(isLive[i])
				cout <<"编号："<<bianhao[i]<<"    类别: "<< type[i] << "    " << "名字："<<name[i] << "    价格：" << price[i] << endl;
		}
	}

	void del_one_good()
	{
		cout << "请输入您想要删除商品的编号" << endl;
		string text;
		cin >> text;
		int t_del = atoi(text.c_str());
		isLive[t_del] = 0;
		cout << "完成" << endl;
	}

	void change_one_good()
	{
		cout << "请输入您想要修改的商品的编号" << endl;
		string text;
		cin >> text;
		int t_change = atoi(text.c_str());
		cout << "请输入修改后的名字" << endl;
		cin >> text;
		name[t_change] = text;
		cout << "请输入修改后的价格" << endl;
		cin >> text;
		price[t_change] = text;
	}

	void find_by_type()
	{
		cout << "请输入您想要查询的类别:" << endl;
		string text;
		cin >> text;
		while (text != "计算机"&&text != "外围设备"&&text != "办公用品"&&text != "生活用品"&&text != "图书")
		{
			cout << "输入有误，请重新输入" << endl;
			cin >> text;
		}
		cout << "请输入您想要查询的名称:" << endl;
		string text2;
		cin >> text2;
		for (int i = 0; i != Id; i++)
		{
			if (type[i] == text&& name[i]==text2)
			{
				cout <<"编号："<<bianhao[i]<< "    名字：" << name[i] << "    价格：" << price[i] << endl;
			}
		}
	}

	void save_other_op()				//将内存中的信息重新写入文件	
	{
		ofstream os_id("goods_id.txt");									//首先只写模式打开文件（会删除文件之前的内容）
		ofstream os_type("goods_type.txt");
		ofstream os_name("goods_name.txt");
		ofstream os_price("goods_price.txt");	
		ofstream os_isLive("goods_isLive.txt");

		//将信息写入文件
		for (int i = 0; i != Id; i++)
		{
			os_id << bianhao[i] << endl;
			os_type << type[i] << endl;
			os_name << name[i] << endl;
			os_price << price[i] << endl;
			os_isLive << isLive[i] << endl;
		}

					
		os_id.close();					//最后关闭文件
		os_type.close();
		os_name.close();
		os_price.close();
		os_isLive.close();
	}
};

int main()
{
	Methods m;
	m.get_all_goods();
	
	while(true)
	{
		cout << "*******************************" << endl;
		cout << "欢迎使用在线商城商品管理系统" << endl;
		cout << "您可以使用以下功能" << endl;
		cout << "1.展示所有商品" << endl;
		cout << "2.增加一个商品" << endl;
		cout << "3.删除一个商品" << endl;
		cout << "4.修改一个商品" << endl;
		cout << "5.类别查找商品" << endl;
		cout << "6.保存之前除增加之外的操作" << endl;
		cout << "7.退出" << endl;
		cout << "请输入您的选择" << endl;
		cout << "*******************************" << endl;
		string input;
		cin >> input;
		if (input != "1"&&input != "2"&&input != "3"&&input != "4"&&input != "5"&&input != "6"&&input!="7")
			cout << "输入有误，请重新输入" << endl;
		else
		{
			int a = int(input[0]-'0');
			switch (a)
			{
			case 1:
				m.show_all_goods();
				//展示所有商品
				break;
			case 2:
				m.add_one_good();
				//增加一个商品
				break;
			case 3:
				m.del_one_good();
				//删除一个商品
				break;
			case 4:
				m.change_one_good();
				//修改一个商品
				break;
			case 5:
				m.find_by_type();
				//类别查找商品
				break;
			case 6:
				m.save_other_op();
				//保存之前增加之外的操作
				break;
			case 7:
				//退出
				cout << "欢迎再次使用" << endl;
				return 1;
			default:
				break;
			}
		}
	}
	system("pause");
}