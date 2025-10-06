module;
export module Vector;

export class Vector
{
public:
    Vector(int n);
    int size() const;
    double &operator[](int n);

private:
    int sz;
    double *elem;
};

Vector::Vector(int n) : elem{new double[n]}, sz{n}
{
}

int Vector::size() const { return sz; }

double &Vector::operator[](int n)
{
    return elem[n];
}

int size(const Vector &v)
{
    return v.size();
}