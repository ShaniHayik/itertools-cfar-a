//
// Created by shani && yarden on 09/06/2020.
//

#ifndef ITERTOOLS_CFAR_FILTERFALSE_H
#define ITERTOOLS_CFAR_FILTERFALSE_H

namespace itertools{

    template <typename bol, typename cnt> class filterfalse {
    private:
        cnt container;
        bol b;
        struct Node {
            cnt value;
            Node* next;
            Node(const cnt v, Node* n): value(v),next(n) { }

        };
    public:
        filterfalse(cnt c) :  container(c) {}

        class iterator {
        private:
            Node* pointerThis;

        public:
            iterator(Node* ptr= nullptr) : pointerThis(ptr){}

            cnt& operator* () const {
                return pointerThis->value;
            }
            cnt* operator->() const {
                return &(pointerThis->value);
            }
            iterator& operator++() {
                pointerThis= pointerThis->next;
                return *this;
            }

            const iterator operator++(cnt){
                iterator temp= *this;
                pointerThis = pointerThis->next;
                return temp;
            }

            bool operator==(const iterator& r) const { // check id this is the same element
                return *this == r.pointerThis;
            }
            bool operator!=(const iterator& r) const {
                return *this != r.pointerThis;
            }

//            iterator begin() {
//                return iterator{num1};
//            }
//
//            iterator end(){
//                return iterator{nullptr};
//            }
        };

        // לעשות for לaccumulate הרגיל וגם לא עשינו class ל-accumulate המשופר
//        template<typename IT> accumulate(T c): accumulate() {
////            for (Node* i= c-> ; i<end->value; begin++) {
////                begin->value=value+1;
//            }
//        }
    };
}






#endif //ITERTOOLS_CFAR_FILTERFALSE_H
