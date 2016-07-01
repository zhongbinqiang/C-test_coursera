#include <iostream> 
#include <iterator> 
#include<stdlib.h>
#include <list> 
#include<map>
using namespace std;

typedef map<int, list<int> > myMap;

int main() { 
    int n;
    myMap m;
    cin>>n;
    char c[20];
    int id1,id2,num;
    list<int>::iterator i;
    while(n--){
    	cin>>c;
    	switch(c[0]){
    		case 'n':{
    			cin>>id1;
    			m.insert(myMap::value_type(id1,list<int>()));
				break;
			}
			case 'a':{
				cin>>id1>>num;
				m[id1].push_back(num);
				break;
			}
			case 'm':{
				cin>>id1>>id2;
				m[id1].merge(m[id2]);
				break;
			}
			case 'u':{
				cin>>id1;
				m[id1].sort();
				m[id1].unique();
				break;
			}
			case 'o':{
				cin>>id1;
				m[id1].sort();
				for(i = m[id1].begin(); i!=m[id1].end(); i++){
					cout<<*i<<" ";
				}
				cout<<endl;
				break;
			}
		}
	}
	return 0;
}

