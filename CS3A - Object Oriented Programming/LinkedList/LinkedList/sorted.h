#include "list.h"
#ifndef SORTED_H
#define SORTED_H

class Sorted : public List{
private:
public:
    Sorted();
    Sorted(const List& A);
//    void Merge(List&ToThis, List &MergeThis);
};
#endif //SORTED_H
