//Created by yarden && shani on 09/06/2020

#pragma once

namespace itertools {

    typedef struct {
        template <typename T>
        T operator ()(T x, T y) const{
            return x+y;
        }
    } oper_plus;

    template <typename container, typename sign = oper_plus>

    class accumulate {
        container _container;
        sign _sign;

    public:
        accumulate(container cont, sign s = oper_plus()) : _container(cont), _sign(s){}

        class iterator{
            decltype(*(_container.begin())) _value;
            typename container::iterator _iter;
            typename container::iterator _end;
            sign _sign;

        public:
            iterator(typename container::iterator iter, typename container::iterator end, sign s) : _iter(iter), _end(end), _sign(s), _value(*iter){};
            iterator(const iterator& it) = default;

            iterator& operator=(const iterator& it){
                if(this != &it) {
                    this->_value = it._value;
                    this->_iter = it._iter;
                    this->_end = it._end;
                    this->_sign = it._sign;
                }
                return *this;
            }

            bool operator==(const iterator& it) {
                return _iter == it._iter;
            }

            bool operator !=(const iterator& it) {
                return _iter != it._iter;
            }

            //add more operators for the second eccumulate?
            iterator& operator++(){
                ++_iter;
                if(_iter != _end) _value = _sign(_value, *_iter);
                return *this;
            }

            iterator operator++(int){
                iterator iter = *this;
                ++(*this);
                return iter;
            }

            auto operator*(){
                return _value;
            }
        };

        iterator begin(){ return iterator(_container.begin(), _container.end(), _sign); }
        iterator end(){ return iterator(_container.end(), _container.end(), _sign); }

    };
}


