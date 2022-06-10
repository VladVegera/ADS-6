// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
  private:
    T arr[size];
    int first;
    int last;
  public:
    void push(T obj) {
      int i = last;
      for (; (i >= first) && arr[i % size].prior < obj.prior; --i) {
        arr[(i+1) % size] = arr[i % size];
      }
      arr[(i + 1) % size] = obj;
      ++last;
    }
    T pop() {
      return arr[(first++) % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
