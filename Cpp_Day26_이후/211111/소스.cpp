class A
{
	friend class B;

	friend void Add(A& a, int const i)
	{
		
		a.i += i;
	}
	int i = 0;
};
class B
{
public:
	void Set(class A& a, int i)
	{
		a.i = i;
	}
	int Get(class A const& a)
	{
		return a.i;
	}

};

int main()
{
	A a;
	B b;
	b.Set(a, 5);
	Add(a, 2);// 객체지향 어디감?


	return 0;
}