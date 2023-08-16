#include <iostream>

class A {
public:
    void func() {
        std::cout << "A::func()" << std::endl;
    }
};

class B : public A {
};

class C : public A {
};

class D : public B, public C {
};

// ------------------

class E : virtual public A {
};

class F : virtual public A {
};

class G : virtual public E, virtual public F {
};

int main() {
    D d;
    d.func(); // Ambiguity Error! Which A::func() should be called?

    G g;
    g.func(); // Solved by multiple class used virtual keyword.
    return 0;
}
