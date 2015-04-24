interface A
{
	void func();
};

class B
{
	public void func1()
	{
		this.print(new A()
		{
			public void func(){System.out.println("Here!!");}
		});
	}
	public void print(A a)
	{
		a.func();
	}
};


class Anomynous
{
	public static void main(String[] args)
	{
		B b = new B();
		b.func1();
	}
}
