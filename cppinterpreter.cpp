#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

char data[30000];
int ptr, loop;
 
int 
main(int argc, char* argv[]){
  if(argc < 2) return -1;
  std::ifstream ifs(argv[1]);
  if(ifs.fail()) return -1;

  std::istreambuf_iterator<char> it(ifs);
  std::istreambuf_iterator<char> last;
  std::string str(it, last);
  std::string::iterator cursor = str.begin();
  
  while(cursor != str.end()){
    switch(*cursor){
      case '<' :
	{
	  ptr++;
	  break;
	}
      case '>' :
	{
	  ptr--;
	  break;
	}
      case '+' :
	{
	  data[ptr]++;
	  break;
	}
      case '-' :
	{
	  data[ptr]--;
	  break;
	}
      case '.' :
	{
	  std::cout << data[ptr];
	  break;
	}
      case ',' :
	{
	  std::cin >> data[ptr];
	  break;
	}
      case '[' : 
	{
	  if(data[ptr] == 0){
	    for(cursor++; loop > 0 || *cursor != ']'; cursor++){
	      if(*cursor == '[')
		loop++;
	      if(*cursor == ']')
		loop--;
	    }
	  }
	  break;
	}
      case ']' :
	{
	  if(data[ptr] != 0){
	    for(cursor--; loop > 0 || *cursor != '['; cursor--){
	      if(*cursor == ']')
		loop++;
	      if(*cursor == '[')
		loop--;
	    }
	    cursor--;
	  }
	  break;
	}
      default :
	break;	
    }
    cursor++;
  }
  
  return 0;
}
