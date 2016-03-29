#include "threadsafe_list.h"

int main()
{
    threadsafe_list<int> tl;
    tl.push_front(1);

    return 0;
}
