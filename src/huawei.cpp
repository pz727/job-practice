
#include <iostream>
#include  <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

//这道题的难点在于，如果题目要求考虑计算其排名的时间效率，
//那么对于对于一个已经排好序的数组，
//当插入一个新条目时，如何更新排序，则成为一个难点

struct Grade
{
  std::string name;
  int math;
  int lang;
  int total_grade;
  int math_rank;
  int lang_rank;
  int total_rank;
};
ostream& operator << (ostream& out, const Grade & stu)
{
  out << "NAME=" << stu.name << "," 
      << "MATH=" << stu.math << ","
      << "LANG=" << stu.lang << ","
      << "RANK_MATH=" << stu.math_rank << ","
      << "RANK_LANG=" << stu.lang_rank << ","
      << "TOTAL_RANK=" << stu.total_rank << endl;
  return out;
}

void get_inf_lod( std::string& str, Grade& stu)
{
  int index_name = str.find("NAME=");
  int index_first_d  = str.find(',');
  int index_first_d2  = str.find(',',index_first_d+1);
  int index_math  = str.find("MATH");
  int index_lang  = str.find("LANG");
  int  math,lang;

  stu.name = str.substr( index_name+5, index_first_d-index_name-5 );
  if( index_math < index_lang )
  {
    string  smath( str,index_math+5,index_first_d2-index_math-5);
    string  slang( str,index_lang+5 );
    stu.math = atoi(smath.c_str());
    stu.lang = atoi(slang.c_str());
  }
  else
  {
    string  slang( str,index_lang+5,index_first_d2-index_lang-5);  
    string  smath( str,index_math+5 );
    stu.math = atoi(smath.c_str());
    stu.lang = atoi(slang.c_str());
  }
  stu.total_grade = stu.math + stu.lang;
  // cout  <<  stu;
}


bool sort_math( const Grade& g1, const Grade& g2 )
{
  return g1.math > g2.math;
}
bool sort_lang( const Grade& g1, const Grade& g2 )
{
  return g1.lang > g2.lang;
}
bool sort_total( const Grade& g1, const Grade& g2 )
{
  return g1.total_grade > g2.total_grade;
}


void update( vector<Grade>&  grade )
{
  //如果再考虑扩展性，把每科成绩和其排名封装成结构体，
  //计算其排名就可以写成一个单独的函数，
  //需要更新其排名，只需调用一个函数即可
  
  //数学排序
  sort(grade.begin(), grade.end(), sort_math );
  int tmp(1);
  grade[0].math_rank = tmp;
  for( int i=1; i < grade.size(); i++ )
  {
    if( grade[i].math == grade[i-1].math )
      grade[i].math_rank = tmp;
    else
      {
        grade[i].math_rank = i+1;
        tmp = i+1;
      }
  }

  //语文排序
  sort(grade.begin(), grade.end(), sort_lang );
  tmp = 1;
  grade[0].lang_rank = tmp;
  for( int i=1; i < grade.size(); i++ )
  {
    if( grade[i].lang == grade[i-1].lang )
      grade[i].lang_rank = tmp;
    else
      {
        grade[i].lang_rank = i+1;
        tmp = i+1;
      }
  }

  //总分排序
  sort(grade.begin(), grade.end(), sort_total );
  tmp = 1;
  grade[0].total_rank = tmp;
  for( int i=1; i < grade.size(); i++ )
  {
    if( grade[i].total_grade == grade[i-1].total_grade )
      grade[i].total_rank = tmp;
    else
      {
        grade[i].total_rank = i+1;
        tmp = i+1;
      }
  }

}


int main()
{
  vector<Grade>  grade;
  string str;

  while( getline( cin,str ) )
  {
    string  com( str.substr(0,3) );
    if( com== string("LOD") )
    {
      Grade stu;
      get_inf_lod( str, stu );

      bool exist(false);
      for(int i=0; i< grade.size(); i++)
        if( grade[i].name == stu.name )
        {
          cout << "this student is already exist!" << endl;
          exist = true;
          break;
        }
      if(!exist)
        grade.push_back(stu);
      else 
        continue;
      update( grade );
    }

    else if( com== string("LST") )
    {
      string name = str.substr( 15 );
      bool find(false);
      for(int i=0; i< grade.size(); i++)
        if( grade[i].name == name )
        {
          cout << grade[i];
          find = true;
          break;
        }
      if(!find)
        cout << "no such item!" << endl;
    }

    else
    {
      cout  <<  "commend error!" << endl;
      continue;
    }


  }

}
