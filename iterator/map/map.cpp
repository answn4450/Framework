#include <iostream>
#include <map>
#include <string>
#include <list>

using namespace std;


typedef struct Score
{
	string name;
	int Kor;
	int Eng;
	int Math;

	Score(int _Kor, int _Eng, int _Math) : Kor(_Kor), Eng(_Eng), Math(_Math) {}
	Score() :Kor(0),Eng(0),Math(0){}
};


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

	/*
	* //여러 키
	map<string, list<Score>> StudentList;

	string key = "홍";
	string key2 = "이";

	Score score = Score(100, 200, 300);
	score.name = "길동";

	list<Score> tmpList;
	tmpList.push_back(score);
	StudentList.insert(make_pair(key, tmpList));
	StudentList.insert(make_pair(key2, tmpList));
	
	map<string, list<Score>>::iterator findKey1 = StudentList.find(key);
	map<string, list<Score>>::iterator findKey2 = StudentList.find(key2);
	score = Score(900, 200, 300);
	findKey1->second.push_back(score);
	findKey2->second.push_back(score);

	//list<Score> ManyHong = findKey1->second;
	
	for (map<string, list<Score>>::iterator iter = StudentList.begin(); iter != StudentList.end(); ++iter)
	{
		cout << "key가 " << iter->first << endl;
		for (list<Score>::iterator iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			cout << "이름: " << iter2->name << endl;
			cout << "국어 점수: " << iter2->Kor << endl;
			cout << "영어 점수: " << iter2->Eng << endl;
			cout << "수학 점수: " << iter2->Math << endl;
			cout << endl;
		}
		cout << endl;
	}
	*/

	/*
	for (list<Score>::iterator iter = ManyHong.begin(); iter != ManyHong.end(); ++iter)
	{
		cout << "######################################################################################" << endl;

		cout << "국어 점수: " << iter->Kor << endl;
		cout << "영어 점수: " << iter->Eng << endl;
		cout << "수학 점수: " << iter->Math << endl;
	}
	*/

	return 0;
}