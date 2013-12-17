#include <iostream>
#include <memory>

struct Foo
{
  Foo()      { std::cout << "Foo::Foo\n";  }
  ~Foo()     { std::cout << "Foo::~Foo\n"; }
  void bar() { std::cout << "Foo::bar\n";  }
  Foo &Foo::operator=(const Foo &rhs) { std::cout << "Foo::=\n"; return *this; }
};

void f(const Foo &)
{
  std::cout << "f(const Foo&)\n";
}

int main()
{
  std::unique_ptr<Foo> p1(new Foo);  // p1 owns Foo
  if (p1) p1->bar();
  std::unique_ptr<Foo> p2 = p1;
}
