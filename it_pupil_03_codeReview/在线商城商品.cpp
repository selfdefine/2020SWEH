#include<iostream>
#include<string>
#include <fstream>  
#include <iostream>  
using namespace std;

string name[999];		//���������ļ��е�����
string price[999];			//.		.	.	.	.	  �۸�
string type[999];			//.		.	.	.	.	  ����
int isLive[999];				//.		.	.	. �Ƿ�ɾ��
int bianhao[999];			//.		.	.	.	.	  ���
int Id = 0;

/*
��������Ʒ�Ĺ�����ȡ���������һ������Goods�࣬
Ȼ�������е���Ʒ�̳�������࣬�ڷֱ�д��Ʒ�Ĺ��캯��
*/

class Goods		//��Ʒ��	������Ʒ�Ļ���
{
private:		
	string	price;			//�۸�
	string name;			//����
	string type;			//����
	int id;				//���
	int isLive;			//�Ƿ�ɾ��
public:
	void setPrice(string price) {			//���ü۸�
		this->price = price;
	}

	void setName(string name) {			//��������
		this->name = name;
	}

	void setType(string type) {				//��������
		this->type = type;
	}

	void setId()				//���ñ��
	{
		this->id = Id++;
	}

	void setIsLive()				//Ĭ��û�б�ɾ��
	{
		this->isLive = 1;
	}

	int getIsLive()			//��ȡ״̬
	{
		return this->isLive;
	}

	int get_id()
	{
		return this->id;
	}

	void show() {
		cout << "���ࣺ" << type << "		���֣�" << name << "		�۸�(Ԫ)��" << price << endl;
	}

	void save() {				//�����ж������浽�ļ���
		ofstream os_id("goods_id.txt", ios::app);					//��׷��д��ķ�ʽ���ļ�
		os_id << id << endl;									//д��
		os_id.close();							//�ر��ļ�
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

class Computer : public Goods			//�������  �̳���Ʒ��
{
public:
	Computer(string name, string price)
	{
		this->setName(name);
		this->setPrice(price);
		this->setType("�����");
		this->setId();
		this->setIsLive();
	}
};

class Peripheral : public Goods			//��Χ�豸��    �̳���Ʒ��
{
public:
	Peripheral(string name, string price)
	{
		this->setName(name);
		this->setPrice(price);
		this->setType("��Χ�豸");
		this->setId();
		this->setIsLive();
	}
};

class Office :public Goods			//�칫��Ʒ��			�̳���Ʒ��
{
public:
	Office(string name, string price)
	{
		this->setName(name);
		this->setPrice(price);
		this->setType("�칫��Ʒ");
		this->setId();
		this->setIsLive();
	}
};

class Life :public Goods			//������Ʒ��				�̳���Ʒ��
{
public:
	Life(string name, string price)
	{
		this->setName(name);
		this->setPrice(price);
		this->setType("������Ʒ");
		this->setId();
		this->setIsLive();
	}
};

class Books :public Goods				//ͼ����				�̳���Ʒ��
{
public:
	Books(string name, string price)
	{
		this->setName(name);
		this->setPrice(price);
		this->setType("ͼ��");
		this->setId();
		this->setIsLive();
	}
};


/*
	�����з�����װ���������
*/
class Methods				//������		
{
public:
	void get_all_goods()			//���ļ����������Ʒ���ص��ڴ���
	{
		ifstream OpenFile("goods_id.txt");			//��������Ʒid��Id
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

		ifstream OpenFile_name("goods_name.txt");			//���������ֶ����ڴ�
		i = 0;
		while (OpenFile_name)
		{
			string text;
			OpenFile_name >> text;
			//cout << text<<endl;
			name[i++] = text;
		}
		OpenFile_name.close();


		ifstream OpenFile_price("goods_price.txt");			//�����м۸�����ڴ�
		i = 0;
		while (OpenFile_price)
		{
			string text;
			OpenFile_price >> text;
			//cout << text<<endl;
			price[i++] = text;
		}
		OpenFile_price.close();


		ifstream OpenFile_type("goods_type.txt");			//�������������ڴ�
		 i = 0;
		while (OpenFile_type)
		{
			string text;
			OpenFile_type >> text;
			//cout << text<<endl;
			type[i++] = text;
		}
		OpenFile_type.close();


		ifstream OpenFile_live("goods_isLive.txt");			//������״̬�����ڴ�
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

	void add_one_good()		//����һ����Ʒ
	{
		string input;
		while (true)
		{
			cout << "��ѡ����Ҫ��ӵ���Ʒ�����" << endl;
			cout << "1.�������" << endl;
			cout << "2.��Χ�豸��" << endl;
			cout << "3.�칫��Ʒ��" << endl;
			cout << "4.������Ʒ��" << endl;
			cout << "5.ͼ����" << endl;
			cout << "6.ȡ��" << endl;
			cin >> input;
			if (input == "6")
				return;
			if (input != "1"&&input != "2"&&input != "3"&&input != "4"&&input != "5")
			{
				cout << "��ѡ�����Ʒ��𲻴��ڣ�������ѡ�񣬻�������6�˳��˹���" << endl;
			}
			else
			{
				break;
			}
		}
		int a = int(input[0] - '0');
		string t_name;
		string t_price;
		Goods *g;			//����һ�����࣬�����������ת������̬��
		int t_id;
	
		switch (a)
		{
		case 1:
			cout << "����������������" << endl;
			cin >> t_name;
			cout << "�����������ļ۸�" << endl;
			cin >> t_price;
			g = new Computer(t_name,t_price);				//��̬�����û������ʵ����һ���������
			g->save();
			t_id = g->get_id();
			name[t_id] = t_name;
			price[t_id] = t_price;
			type[t_id] = "�����";
			isLive[t_id] = 1;
			bianhao[t_id] = t_id;
			break;
		case 2:
			cout << "��������Χ�豸������" << endl;
			cin >> t_name;
			cout << "��������Χ�豸�ļ۸�" << endl;
			cin >> t_price;
			g = new Peripheral(t_name, t_price);
			g->save();
			t_id = g->get_id();
			name[t_id] = t_name;
			price[t_id] = t_price;
			type[t_id] = "��Χ�豸";
			isLive[t_id] = 1;
			bianhao[t_id] = t_id;
			break;
		case 3:
			cout << "������칫��Ʒ������" << endl;
			cin >> t_name;
			cout << "������칫��Ʒ�ļ۸�" << endl;
			cin >> t_price;
			g = new Office(t_name, t_price);
			g->save();
			t_id = g->get_id();
			name[t_id] = t_name;
			price[t_id] = t_price;
			type[t_id] = "�칫��Ʒ";
			isLive[t_id] = 1;
			bianhao[t_id] = t_id;
			break;
		case 4:
			cout << "������������Ʒ������" << endl;
			cin >> t_name;
			cout << "������������Ʒ�ļ۸�" << endl;
			cin >> t_price;
			g = new Life(t_name, t_price);
			g->save();
			 t_id = g->get_id();
			name[t_id] = t_name;
			price[t_id] = t_price;
			type[t_id] = "������Ʒ";
			isLive[t_id] = 1;
			bianhao[t_id] = t_id;
			break;
		case 5:
			cout << "������ͼ�������" << endl;
			cin >> t_name;
			cout << "������ͼ��ļ۸�" << endl;
			cin >> t_price;
			g = new Books(t_name, t_price);
			g->save();
			t_id = g->get_id();
			name[t_id] = t_name;
			price[t_id] = t_price;
			type[t_id] = "ͼ��";
			isLive[t_id] = 1;
			bianhao[t_id] = t_id;
			break;
		default:
			break;
		}
		cout << endl << "��ӳɹ������Ϊ��" << bianhao[t_id] << endl;
	}

	void show_all_goods()
	{
		for (int i = 0; i != Id; i++)
		{
			if(isLive[i])
				cout <<"��ţ�"<<bianhao[i]<<"    ���: "<< type[i] << "    " << "���֣�"<<name[i] << "    �۸�" << price[i] << endl;
		}
	}

	void del_one_good()
	{
		cout << "����������Ҫɾ����Ʒ�ı��" << endl;
		string text;
		cin >> text;
		int t_del = atoi(text.c_str());
		isLive[t_del] = 0;
		cout << "���" << endl;
	}

	void change_one_good()
	{
		cout << "����������Ҫ�޸ĵ���Ʒ�ı��" << endl;
		string text;
		cin >> text;
		int t_change = atoi(text.c_str());
		cout << "�������޸ĺ������" << endl;
		cin >> text;
		name[t_change] = text;
		cout << "�������޸ĺ�ļ۸�" << endl;
		cin >> text;
		price[t_change] = text;
	}

	void find_by_type()
	{
		cout << "����������Ҫ��ѯ�����:" << endl;
		string text;
		cin >> text;
		while (text != "�����"&&text != "��Χ�豸"&&text != "�칫��Ʒ"&&text != "������Ʒ"&&text != "ͼ��")
		{
			cout << "������������������" << endl;
			cin >> text;
		}
		cout << "����������Ҫ��ѯ������:" << endl;
		string text2;
		cin >> text2;
		for (int i = 0; i != Id; i++)
		{
			if (type[i] == text&& name[i]==text2)
			{
				cout <<"��ţ�"<<bianhao[i]<< "    ���֣�" << name[i] << "    �۸�" << price[i] << endl;
			}
		}
	}

	void save_other_op()				//���ڴ��е���Ϣ����д���ļ�	
	{
		ofstream os_id("goods_id.txt");									//����ֻдģʽ���ļ�����ɾ���ļ�֮ǰ�����ݣ�
		ofstream os_type("goods_type.txt");
		ofstream os_name("goods_name.txt");
		ofstream os_price("goods_price.txt");	
		ofstream os_isLive("goods_isLive.txt");

		//����Ϣд���ļ�
		for (int i = 0; i != Id; i++)
		{
			os_id << bianhao[i] << endl;
			os_type << type[i] << endl;
			os_name << name[i] << endl;
			os_price << price[i] << endl;
			os_isLive << isLive[i] << endl;
		}

					
		os_id.close();					//���ر��ļ�
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
		cout << "��ӭʹ�������̳���Ʒ����ϵͳ" << endl;
		cout << "������ʹ�����¹���" << endl;
		cout << "1.չʾ������Ʒ" << endl;
		cout << "2.����һ����Ʒ" << endl;
		cout << "3.ɾ��һ����Ʒ" << endl;
		cout << "4.�޸�һ����Ʒ" << endl;
		cout << "5.��������Ʒ" << endl;
		cout << "6.����֮ǰ������֮��Ĳ���" << endl;
		cout << "7.�˳�" << endl;
		cout << "����������ѡ��" << endl;
		cout << "*******************************" << endl;
		string input;
		cin >> input;
		if (input != "1"&&input != "2"&&input != "3"&&input != "4"&&input != "5"&&input != "6"&&input!="7")
			cout << "������������������" << endl;
		else
		{
			int a = int(input[0]-'0');
			switch (a)
			{
			case 1:
				m.show_all_goods();
				//չʾ������Ʒ
				break;
			case 2:
				m.add_one_good();
				//����һ����Ʒ
				break;
			case 3:
				m.del_one_good();
				//ɾ��һ����Ʒ
				break;
			case 4:
				m.change_one_good();
				//�޸�һ����Ʒ
				break;
			case 5:
				m.find_by_type();
				//��������Ʒ
				break;
			case 6:
				m.save_other_op();
				//����֮ǰ����֮��Ĳ���
				break;
			case 7:
				//�˳�
				cout << "��ӭ�ٴ�ʹ��" << endl;
				return 1;
			default:
				break;
			}
		}
	}
	system("pause");
}