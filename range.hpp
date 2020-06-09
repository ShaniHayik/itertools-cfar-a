//Created by yarden && shani on 09/06/2020.

#ifndef ITERTOOLS_CFAR_RANGE_H
#define ITERTOOLS_CFAR_RANGE_H


namespace itertools {
    class range {
    public:
        class iterator {
            class range;

    public:
            int operator*() const { return i; }
            const iterator &operator++() {
                ++i;
                return *this;
            }

            bool operator==(const iterator &it) const {
                return i == it.i;
            }

            iterator operator++(int) {
                iterator copy(*this);
                ++i;
                return copy;
            }

            bool operator!=(const iterator &it) const {
                return i != it.i;
            }

            iterator(int start) : i(start) {}

        private:
            int i;

        };

        iterator end() const { return end; }
        iterator begin() const { return begin; }
        range(int begin, int end) : begin(begin), end(end) {}

    private:
        iterator begin;
        iterator end;
    };
}

