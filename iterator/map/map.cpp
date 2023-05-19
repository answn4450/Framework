#include <iostream>
#include <map>
#include <string>
#include <list>

using namespace std;


typedef struct tagScore
{
	string name;
	int Kor;
	int Eng;
	int Math;

	tagScore(int _Kor, int _Eng, int _Math) : name(""), Kor(_Kor), Eng(_Eng), Math(_Math) {}
	tagScore() : name(""), Kor(0), Eng(0), Math(0) {}
	tagScore(string _name, int _Kor, int _Eng, int _Math) : name(_name), Kor(_Kor), Eng(_Eng), Math(_Math) {}
}Score;


map<string, list<Score>> StudentList;

Score CreateScore(string _name, int _kor, int _eng, int _math);
bool AddStudent(string _key, Score _score);

int main()
{
	/*
	map<string, list<Score>> List;

	string key = "홍";
	Score score = Score(100, 200, 300);
	score.name = "길동";

	List.insert(make_pair(key, score));

	cout << key + List[key].name<< endl;
	cout << List[key].Kor << endl;
	cout << List[key].Eng << endl;
	cout << List[key].Math << endl;

	multimap<string, Score> multiList;

	multiList.insert(make_pair(key, score));
	score = Score(130, 200, 300);
	multiList.insert(make_pair(key, score));

	for (multimap<string, Score>::iterator iter = multiList.begin(); iter != multiList.end(); ++iter)
	{
		cout << "국어 점수: " << iter->first << iter->second.Kor << endl;
		cout << "영어 점수: " << iter->first << iter->second.Eng << endl;
		cout << "수학 점수: " << iter->first << iter->second.Math << endl;
	}
	*/


	string key = "홍";
	string key2 = "이";
	string name = "길동";

	float Result = true;
	Result = Result && AddStudent(key, CreateScore(name, 100, 200, 300));
	//Result = Result && AddStudent(key2, name, 100, 200, 300);
	if (!Result)
		cout << "X" << endl;


	for (map<string, list<Score>>::iterator iter = StudentList.begin(); iter != StudentList.end(); ++iter)
	{
		cout << "key: " << iter->first << endl;
		for (list<Score>::iterator iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			cout << "이름: " << iter2->name << endl;
			cout << "Kor: " << iter2->Kor << endl;
			cout << "Eng: " << iter2->Eng << endl;
			cout << "Math: " << iter2->Math << endl;
			cout << "######################################" << endl;
		}
	}

	return 0;
}


Score CreateScore(string _name, int _kor, int _eng, int _math)
{
	if (_kor > 100 || _kor < 0)
		_kor = 0;
	if (_eng > 100 || _eng < 0)
		_eng = 0;
	if (_math > 100 || _math < 0)
		_math = 0;

	return Score(_name, _kor, _eng, _math);
}


bool AddStudent(string _key, Score _score)
{
	map<string, list<Score>>::iterator iter = StudentList.find(_key);
	
	if (iter == StudentList.end())
	{
		list<Score> tempList;
		tempList.push_back(_score);
		StudentList.insert(make_pair(_key, tempList));
		map<string, list<Score>>::iterator iter = StudentList.find(_key);
		return true;
	}
	else
		iter->second.push_back(_score);


	return true;
}