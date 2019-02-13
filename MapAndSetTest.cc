#include<iostream>
#include<map>
#include<set>

using std::cout;
using std::endl; 

void test_set()
{
  //key的模拟场景 效率高 时间复杂度为O（logN)
  //排序加去重
  std::set<int> s;
  s.insert(2);
  s.insert(1);
  s.insert(3);  
  s.insert(3);
  //遍历
  std::set<int>::iterator it = s.begin();
 // auto it = s.begin();
  while(it != s.end())
  {
    cout<<*it<<" ";
    ++it;
  }
  cout<<endl;

  int x;
  std::cin>>x;
  std::set<int>::iterator ret = s.find(x);
  s.erase(ret);

  if(ret != s.end())
  {
    cout<<x<<"在set集合中"<<endl;
  }
  else{
    cout<<x<<"不在set集合中"<<endl;
  }
  
  std::set<std::string> str;
  str.insert("sort");
  str.insert("bug");
  
  for(auto e : str)
  {
    cout<<e<<endl;
  }
}


void test_multiset()
{
  //排序
  //与set相比可以重复
  std::multiset<int> ms;
  ms.insert(2);
  ms.insert(3);
  ms.insert(2);
  ms.insert(3);
  ms.insert(1);
  for(auto e: ms)
  {
    cout<<e<<" ";
  }
   cout<<endl;
}

void test_map()
{
  //去重
 // 去重并按照key排序
  std::map<std::string,std::string> dict;
  dict.insert(std::pair<std::string,std::string>("insert","插入"));
  dict.insert(std::pair<std::string,std::string>("apple","苹果"));
dict.insert(std::pair<std::string,std::string>("buff","加成")); 
dict.insert(std::pair<std::string,std::string>("bug","幺蛾子"));
dict.insert(std::pair<std::string,std::string>("bug","幺蛾子"));
std::map<std::string,std::string>::iterator dit = dict.begin();
while(dit != dict.end())
{
  cout<<(*dit).first<<":"<<dit->second<<endl;
  ++dit;
}

//【】没有则插入，有则修改内容，返回value的别名 
dict["insert"] = "入";

for(const auto& e: dict)
{
  cout<<e.first<<":"<<e.second<<endl;
}

}

int main()
{
 // test_set();
 // test_multiset();
    test_map();
  return 0;
}
