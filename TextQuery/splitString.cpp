/*
 *
 * devide the string ro different word
 * find("string being searched",postion starting)
 * *
 */
#include<string>
#include<vector>
#include <iostream>
using namespace std;
typedef pair<short,short> location;
typedef vector<location> loc;
typedef vector<string> text;
typedef pair<text*,loc*> text_loc;
text_loc* SeperateWords(const vector<string> *text_file)
{
	//words::include the set of word
	//locations: include the relevant lines and arrow
	vector<string> *words=new vector<string>;
	vector<location> *locations=new vector<location>;
	short line_pos=0;
	for( : line_pos<text_file->size();++line_pos)
	{
		short word_pos=0;
		string text_line=(*text_file)[line_pos];
		string::size_type pos=0 ,prev_pos=0;
		while((pos=text_line.find_first_of(' ',pos)!=string::npos))
		{
			words->push_back(substr(prev_pos,pos-prev_pos));
			locations->push_back(make_pair(line_pos,word_pos));
			prev_pos=++pos;
			++word_pos;
		}
			words->push_back(substr(prev_pos,pos-prev_pos));
			locations->push_back(make_pair(line_pos,word_pos));
	}

	return new text_loc(words,locations);
}

typedef vector<string,allocatos>* pvector;
pvector retrive_text()
{
	string file_name;
	cout<<"input the file name:";
	cin>>file_name;

	ifstream infile(file_name);

	while(getline(infile,textline,'\n'))
	{
		cout<<"line read:"<<textline<<'\n';
		if(maxline.fist< textline.size())
		{


		}
	
	}
}
/*
 *text_filter()去除句子中的标点符号
 *
 */
void text_filter(vector<string> *words,string filter)
{
	int cur=0
	for(;cur!=(*words).size();cur++)
	{
		pos=0;
		word_size=(*words)[cur].size();
		while(pos<word_size)
		{	
	    	if(pos=find_first_of(filter.c_str(),pos)!=(word_size-1))
			{
				(*words)[cur].erase(pos);
			
			}
			pos++;
		}
	
	}



}


int main()
{

	vector<string> *text_fo;
	text_file=retrive_text();
	text_loc *text_locations=SeperateWords(text_file);


	return 0;

}
