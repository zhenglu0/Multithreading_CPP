#include "threadsafe_lookup_table.h"
#include <string>
#include <thread>

int main()
{
  threadsafe_lookup_table<std::string,int> tlt;
  //std::thread t1([&]{ tlt.add_or_update_mapping("one",1);});
  
  tlt.add_or_update_mapping("one",1);
  /*
  tlt.add_or_update_mapping("two",2);
  tlt.add_or_update_mapping("three",3);
  tlt.add_or_update_mapping("four",4);
  tlt.add_or_update_mapping("five",5);
  tlt.add_or_update_mapping("six",6);
  tlt.add_or_update_mapping("seven",7);
  tlt.add_or_update_mapping("eight",8);
  tlt.add_or_update_mapping("nine",9);
  tlt.add_or_update_mapping("ten",10);
  */

  
  //t1.join();
  //tlt.value_for("one");
  
  return 0;
}
