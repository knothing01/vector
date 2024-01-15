#ifndef MY_VECTOR_HEADER_H
#define MY_VECTOR_HEADER_H

typedef struct {
    size_t size;
    size_t capacity;
    int* m_array;
}Vector;

void init_array(Vector*);
void pop_back(Vector*);
void resize(size_t , Vector*);
void push_back(int, Vector*);
void clear(Vector*);
void insert(Vector*, int, int);
void erase(Vector*, int);
void shrink_to_fit(Vector*);

int at(Vector*, int);
int empty(Vector*);
int front(Vector*);
int back (Vector*);
int size(Vector*);
int capacity(Vector*);

//destructor
void destruct(Vector*);

#endif //MY_VECTOR_HEADER_H
