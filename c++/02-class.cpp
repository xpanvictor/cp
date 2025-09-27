#include <bits/stdc++.h>
using namespace std;

enum Type
{
    ptr,
    num
};

struct Node
{
};

// to conserve space (good for enum struct like in rust)
union Value
{
    Node *p;
    int i;
};

struct Entry
{
    Type t;
    string name;
    // naked union issue
    Value v; // hence have like v.p or v.i; using type `t` to track which.
    // instead using variant
    variant<Node *, int> v_ext;
};
void log_entry_w_value(const Entry &e)
{
    switch (e.t)
    {
    case ptr:
        printf("Pointer :%d", e.v.p);
        break;
    case num:
        printf("Num :%d", e.v.i);
    }
}

void log_entry_w_variant(const Entry &e)
{
    if (holds_alternative<Node *>(e.v_ext))
    {
        printf("Pointer: %d", get<Node *>(e.v_ext));
    }
    else
    {
        printf("Num: %d", get<int>(e.v_ext));
    }
}

class Vector
{
public:
    Vector(int s) : elem{new double[s]}, sz{s} {}
    double &operator[](int n) { return elem[n]; }
    int size() { return sz; }

private:
    double *elem;
    int sz;
};