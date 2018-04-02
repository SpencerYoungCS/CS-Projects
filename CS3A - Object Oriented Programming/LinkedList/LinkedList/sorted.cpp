#include "sorted.h"

Sorted::Sorted() : List(){
}

Sorted::Sorted (const List &A):List(A){
    sort();
}

//void Sorted::Merge(List& ToThis, List &MergeThis){
//    while(MergeThis.gethead() != NULL){
//        ToThis.inserthead(MergeThis.getitem());
//        MergeThis.gethead() = MergeThis.Next();
//    }
//    ToThis.sort();
//}
