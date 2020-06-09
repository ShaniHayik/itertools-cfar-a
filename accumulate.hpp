//
// Created by yarden && shani on 09/06/2020.
//

#ifndef ITERTOOLS_CFAR_ACCUMULATE_H
#define ITERTOOLS_CFAR_ACCUMULATE_H

namespace itertools{

    template <typename T> class accumulate  {
    private:
       T container;

        struct Node {
            T value;
            Node* next;
            Node(const T v, Node* n): value(v),next(n) { }

        };
    public:
        accumulate(T c) :  container(c) {}

        class iterator {
        private:
            Node* pointerThis;

        public:
            iterator(Node* ptr= nullptr) : pointerThis(ptr){}

            T& operator* () const {
                return pointerThis->value;
            }
            T* operator->() const {
                return &(pointerThis->value);
            }
            iterator& operator++() {
                pointerThis= pointerThis->next;
                return *this;
            }

            const iterator operator++(T){
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

            iterator end(){
                return iterator{nullptr};
            }
        };

        // לעשות for לaccumulate הרגיל וגם לא עשינו class ל-accumulate המשופר
//        template<typename IT> accumulate(T c): accumulate() {
////            for (Node* i= c-> ; i<end->value; begin++) {
////                begin->value=value+1;
//            }
//        }
    };
}



#endif //ITERTOOLS_CFAR_ACCUMULATE_H
